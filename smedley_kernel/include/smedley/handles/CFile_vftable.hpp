#ifndef HANDLES_CFILE_VFTABLE_HPP_
#define HANDLES_CFILE_VFTABLE_HPP_

#include <cstdint>
#include "basic_string.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CFile;

struct CFile_vftable
{
	void *Destroy_CFile;
	void (__thiscall *ReadByte)(CFile * _this);
	void (__thiscall *ReadAll)(CFile * _this, void * buf);
	void (__thiscall *Read)(CFile * _this, void * buf, size_t n);
	void *field4_0x10;
	void (__thiscall *WriteString)(CFile * _this, basic_string<char> * str);
	void (__thiscall *WriteLong)(CFile * _this, basic_string<char> * str);
	void (__thiscall *WriteByte)(CFile * _this, char ch);
	void (__thiscall *Write)(CFile * _this, void * data, size_t n);
	bool (__thiscall *EOF)(CFile * _this);
	bool (__thiscall *Seek)(CFile * _this, size_t n);
	bool (__thiscall *SeekEnd)(CFile * _this);
	bool (__thiscall *SeekBegin)(CFile * _this);
	bool (__thiscall *Flush)(CFile * _this);
	size_t (__thiscall *GetSize)(CFile * _this);
	void *field15_0x3c;
	void *field16_0x40;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CFILE_VFTABLE_HPP_
