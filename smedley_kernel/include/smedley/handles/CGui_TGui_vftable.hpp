#ifndef HANDLES_CGUI_TGUI_VFTABLE_HPP_
#define HANDLES_CGUI_TGUI_VFTABLE_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CGui;
struct CGuiType;

struct CGui_TGui_vftable
{
	void *Destroy_CGui;
	void *field1_0x4;
	void *field2_0x8;
	void *field3_0xc;
	void *field4_0x10;
	void *field5_0x14;
	void *field6_0x18;
	void *field7_0x1c;
	void *field8_0x20;
	void *field9_0x24;
	void *field10_0x28;
	void *CreateWindow;
	void *field12_0x30;
	void *field13_0x34;
	void *field14_0x38;
	void *field15_0x3c;
	void *field16_0x40;
	void *field17_0x44;
	CGuiType * (__thiscall *GetPosition)(CGui * _this, basic_string<char> * key);
	void *field19_0x4c;
	void *field20_0x50;
	void *field21_0x54;
	void *field22_0x58;
	void *field23_0x5c;
	void *field24_0x60;
	void *field25_0x64;
	void *field26_0x68;
	void *field27_0x6c;
	void *field28_0x70;
	void *field29_0x74;
	void *field30_0x78;
	void *field31_0x7c;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CGUI_TGUI_VFTABLE_HPP_
