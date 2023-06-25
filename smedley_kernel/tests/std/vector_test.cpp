#include "memory.hpp"
#include "std/vector.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <windows.h>

using namespace smedley;

TEST(SStdVectorTest, TestPushBack)
{
    memory::Map::game_heap = GetProcessHeap();

    sstd::vector<int> test_vec;
    test_vec.push_back(1);
    test_vec.push_back(2);

    ASSERT_EQ(test_vec.size(), 2);
    ASSERT_EQ(test_vec[0], 1);
    ASSERT_EQ(test_vec[1], 2);
}

