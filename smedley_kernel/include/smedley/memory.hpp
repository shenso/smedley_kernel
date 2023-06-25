#pragma once

#include "macros.hpp"
#include <cstdint>
#include <vector>
#include <windows.h>
#include <memoryapi.h>

namespace smedley::memory
{

	struct SMEDLEY_API Map
	{
		static uintptr_t base_addr;
		static HANDLE game_heap;

		static void Init();
	};

	bool Patch(uintptr_t addr, uint8_t *instr, int n);

	bool Hook(uintptr_t addr, void *jmp, int n, std::vector<uint8_t> *old_instr);

	template <typename... Types>
	bool HookPrologue(uintptr_t addr, void(__stdcall *fn)(Types... args), int n)
	{
		DWORD old_protect, call_addr, ret_addr;
		uint8_t *buf, *trampoline;
		int pos, trampoline_size;

		if (n < 5) {
			return false;
		}

		VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &old_protect);
		buf = new uint8_t[n];
		std::memcpy(buf, addr, n);
		VirtualProtect(addr, n, old_protect, &old_protect);

		if (buf[0] != 0x55 || buf[1] != 0x8b || buf[2] != 0xec) {
			throw std::runtime_error("expected function prologue");
		}

		/*
		 * n: copied from source
		 * i * 4: number of instructions per arg
		 * 10: call and jump instructions
		 */
		trampoline_size = n + (sizeof...(args) * 4) + 10;
		trampoline = new uint8_t[trampoline_size];

		call_addr = (DWORD) fn - ((DWORD) trampoline + trampoline_size - 5 - (n - 3));
		ret_addr = ((DWORD) addr + n) - ((DWORD) trampoline + trampoline_size);

		trampoline[0] = buf[0];
		trampoline[1] = buf[1];
		trampoline[2] = buf[2];

		pos = 3;
		for (int i = 0; i < sizeof...(args); i++, pos += 4) {
			uint8_t offset = 0x8 + (i * 0x4);
			// mov esi, [ebp + offset]
			trampoline[pos] = 0x8b;
			trampoline[pos + 1] = 0x75;
			trampoline[pos + 2] = offset;
			// push esi
			trampoline[pos + 3] = 0x56;
		}
		// call fn
		trampoline[pos++] = 0xe8;
		// little endian
		trampoline[pos++] = call_addr & 0xff;
		trampoline[pos++] = (call_addr >> 0x8) & 0xff;
		trampoline[pos++] = (call_addr >> 0x10) & 0xff;
		trampoline[pos++] = (call_addr >> 0x18) & 0xff;

		for (int i = 3; i < n; i++, pos++) {
			trampoline[pos] = buf[i];
		}
		delete[] buf;

		// jmp ret_addr
		trampoline[pos++] = 0xe9;
		trampoline[pos++] = ret_addr & 0xff;
		trampoline[pos++] = (ret_addr >> 0x8) & 0xff;
		trampoline[pos++] = (ret_addr >> 0x10) & 0xff;
		trampoline[pos++] = (ret_addr >> 0x18) & 0xff;

		VirtualProtect(trampoline, trampoline_size, PAGE_EXECUTE_READWRITE, &old_protect);
		return Hook(addr, trampoline, n, nullptr);

	}

	template <typename... Types>
	bool HookEpilogue(uintptr_t addr, void(__stdcall *fn)(Types... args), int n, const std::vector<int> &preserve = std::vector<int>())
	{
		DWORD old_protect, call_addr;
		uint8_t *buf, *trampoline;
		constexpr uint8_t pattern[] = {0x8b, 0xe5, 0x5d};
		int pos, trampoline_size, epilogue_start;

		if (n < 5) {
			return false;
		}

		VirtualProtect(addr, n, PAGE_EXECUTE_READWRITE, &old_protect);
		buf = new uint8_t[n];
		std::memcpy(buf, addr, n);
		VirtualProtect(addr, n, old_protect, &old_protect);

		epilogue_start = -1;
		for (int i = 0; i + 2 < n; i++) {
			if (buf[i] == pattern[0] && buf[i + 1] == pattern[1] && buf[i + 2] == pattern[2]) {
				epilogue_start = i;
				break;
			}
		}

		if (epilogue_start == -1) {
			throw std::runtime_error("expected function epilogue");
		}

		pos = 0;
		trampoline_size = n + (sizeof...(args) * 4) + 5 + (preserve.size() * 2);
		trampoline = new uint8_t[trampoline_size];

		call_addr = (DWORD) fn - ((DWORD) trampoline + trampoline_size - (n - epilogue_start));

		for (int i = 0; i < epilogue_start; i++, pos++) {
			trampoline[pos] = buf[i];
		}

		// push registers onto the stack
		for (int reg : preserve) {
			trampoline[pos++] = 0x50 + reg;
		}

		for (int i = 0; i < sizeof...(args); i++, pos += 4) {
			uint8_t offset = 0x8 + (i * 0x4);
			// mov esi, [ebp + offset]
			trampoline[pos] = 0x8b;
			trampoline[pos + 1] = 0x75;
			trampoline[pos + 2] = offset;
			// push esi
			trampoline[pos + 3] = 0x56;
		}
		// call fn
		trampoline[pos++] = 0xe8;
		trampoline[pos++] = call_addr & 0xff;
		trampoline[pos++] = (call_addr >> 0x8) & 0xff;
		trampoline[pos++] = (call_addr >> 0x10) & 0xff;
		trampoline[pos++] = (call_addr >> 0x18) & 0xff;

		for (int i = 0; i < n - epilogue_start; i++, pos++) {
			trampoline[pos] = buf[i + epilogue_start];
		}
		delete[] buf;

		// restore registers
		for (int reg : preserve) {
			trampoline[pos++] = 0x58 + reg;
		}

		VirtualProtect(trampoline, trampoline_size, PAGE_EXECUTE_READWRITE, &old_protect);
		return Hook(addr, trampoline, n, nullptr);
	}

}