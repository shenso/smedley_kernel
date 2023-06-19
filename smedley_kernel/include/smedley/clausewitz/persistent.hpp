#pragma once

#include "reader.hpp"
#include "writer.hpp"

namespace smedley::clausewitz
{

	// base class for all persistent objects (objects serialized/deserialized from game files)
	class CPersistent
	{
		int _type_token;
	public:
		virtual ~CPersistent();
		virtual void Write(CWriter &);
		virtual void WriteMembers(CWriter &);
		virtual void Read(CReader &);
		virtual void ReadMember(CReader &reader, int type);
		virtual void InitPostRead();
	};

	static_assert(sizeof(CPersistent) == 0x8);

}