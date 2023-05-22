#ifndef HOOK_HOOK_HPP_
#define HOOK_HOOK_HPP_

#include "memory.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <queue>
#include <utility>

#include <windows.h>

namespace smedley
{
namespace hook
{

template <class... Args>
class Hook
{
public:
	using Callback = std::function<void(Args...)>;
protected:
	std::vector<std::tuple<int, std::string, Callback>> _callbacks;

	DWORD _addr;
	int _numBytes;
	void *_trampoline;
	std::vector<uint8_t> _oldInstr;
public:
	Hook(DWORD addr, int numBytes, void *trampoline);
	virtual ~Hook();

	void Add(const std::string &name, Callback fn, int priority);
	void Remove(const std::string &name);
	void __thiscall Notify(Args... args);
protected:
};

template<class ...Args>
Hook<Args...>::Hook(DWORD addr, int numBytes, void *trampoline)
	: _addr(addr),
	  _numBytes(numBytes),
	  _trampoline(trampoline)
{
	core::memory::Hook((void *) _addr, _trampoline, _numBytes, &_oldInstr);
}

template<class ...Args>
Hook<Args...>::~Hook()
{
	core::memory::Patch((void *) _addr, _oldInstr.data(), _oldInstr.size());
}

template<class ...Args>
void Hook<Args...>::Add(const std::string &name, Callback fn, int priority)
{
	auto findPred = [&name](const std::tuple<int, std::string, Callback> &elem) { return std::get<1>(elem) == name; };
	auto cmp = [](const std::tuple<int, std::string, Callback> &a, const std::tuple<int, std::string, Callback> &b) {
		return std::get<0>(a) < std::get<0>(b);
	};

	if (std::find_if(_callbacks.begin(), _callbacks.end(), findPred) != _callbacks.end()) {
		return;
	}

	_callbacks.push_back(std::make_tuple(priority, name, fn));
	std::sort(_callbacks.begin(), _callbacks.end(), cmp);
}

template<class ...Args>
void Hook<Args...>::Remove(const std::string &name)
{
	auto pred = [&fn](const std::tuple<int, std::string, Callback> &elem) { std::get<1>(elem) == name; };
	auto elem = std::find_if(_callbacks.begin(), _callbacks.end(), pred);
	if (elem != _callbacks.end()) {
		_callbacks.erase(elem);
	}
}
template<class ...Args>
void Hook<Args...>::Notify(Args ...args)
{
	for (auto it = _callbacks.begin(); it != _callbacks.end(); it++) {
		(std::get<2>(*it))(args...);
	}
}

}
}

#endif // HOOK_HOOK_HPP_