#pragma once

#include "file.hpp"

namespace smedley::clausewitz
{

	class CWriter
	{
	protected:
		int _indent_level; // 4
		CFile *_file; // 8
		bool _uk_0xc;
	public:
		virtual ~CWriter();
	};

	static_assert(sizeof(CWriter) == 0x10);

}