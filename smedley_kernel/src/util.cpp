#pragma once

#include "util.hpp"

namespace smedley
{

	std::vector<std::string> SplitString(std::string str, char delim)
	{
		std::vector<std::string> vec;
		std::string elem;
		size_t begin = 0;
		size_t end = str.find(delim);

		while (end != std::string::npos) {
			elem = str.substr(begin, end - begin);
			vec.push_back(elem);
			begin = end + 1;
			end = str.find(delim, begin);
		}

		elem = str.substr(begin, end);
		vec.push_back(elem);

		return vec;
	}

}