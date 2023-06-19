#pragma once

namespace smedley::clausewitz
{

	class CToken
	{
	protected:
		int _type;
		char _str[256];
	};

	static_assert(sizeof(CToken) == 0x104);

}