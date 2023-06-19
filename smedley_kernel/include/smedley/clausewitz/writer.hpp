#pragma once

#include "file.hpp"

namespace smedley::clausewitz
{

	class CWriter
	{
		int _indent_level;
		CFile *_file;
		bool _uk_0xc;
	public:
		virtual ~CWriter();
	};

	static_assert(sizeof(CWriter) == 0x10);

}