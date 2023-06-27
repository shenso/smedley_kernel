#pragma once

#include <cstdint>
#include "../std/string.hpp"

namespace smedley::clausewitz
{

    struct PHYSFS_File
    {
        void *opaque;
    };

    class CBlob;

    class CFile
    {
    protected:
        uint32_t _unk_0x4;
        uint32_t _unk_0x8;
        uint32_t _unk_0xc;
        uint32_t _unk_0x10;
        sstd::string _filename;
    public:
        virtual ~CFile(); // 0
        virtual char Get(); // 4
        virtual bool ReadData(CBlob &blob); // 8
        virtual bool Read(void *, int n); // c
        virtual bool ReadString(CBlob &blob); // 10
        virtual void WriteString(sstd::string &); // 14
        virtual void WriteULong(unsigned long); // 18
        virtual void WriteByte(unsigned int); // 1c
        virtual void WriteData(void *, unsigned int); // 20
        virtual bool IsValid(); // 24
        virtual bool SeekStart(int); // 28
        virtual bool SeekEnd(); // 2c
        virtual bool Reset(); // 30
        virtual bool Flush(); // 38
        virtual int GetSize(); // 3c
        virtual int *GetFilePointer(); // 40
        virtual int CalculateChecksum(int); // 44
    };

    static_assert(sizeof(CFile) == 0x30);

}