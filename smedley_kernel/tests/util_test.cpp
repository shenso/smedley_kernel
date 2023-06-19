#include "util.hpp"
#include <gtest/gtest.h>

TEST(UtilTests, SplitStringTest)
{
	using sv = std::vector<std::string>;
	ASSERT_EQ(smedley::SplitString("hello;world", ';'), sv({"hello", "world"}));
}