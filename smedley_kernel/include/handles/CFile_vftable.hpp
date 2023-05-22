#ifndef HANDLES_CFILE_VFTABLE_HPP_
#define HANDLES_CFILE_VFTABLE_HPP_

#include <cstdint>
#include <handles/basic_string.hpp>

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct void;
struct CFile;

struct CFile_vftable
{
	void *~CFile;
	void (*ReadByte)(CFile * this);
	void (*ReadAll)(CFile * this, void * buf);
	void (*Read)(CFile * this, void * buf, size_t n);
	void *field4_0x10;
	void (*WriteString)(CFile * this, basic_string<char> * str);
	void (*WriteLong)(CFile * this, basic_string<char> * str);
	void (*WriteByte)(CFile * this, char ch);
	void (*Write)(CFile * this, void * data, size_t n);
	bool (*EOF)(CFile * this);
	bool (*Seek)(CFile * this, size_t n);
	bool (*SeekEnd)(CFile * this);
	bool (*SeekBegin)(CFile * this);
	bool (*Flush)(CFile * this);
	size_t (*GetSize)(CFile * this);
	void *field15_0x3c;
	void *field16_0x40;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CFILE_VFTABLE_HPP_
