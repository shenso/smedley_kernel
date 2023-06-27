#include "plugin.hpp"
#include <string>
#include <vector>
#include <gtest/gtest.h>

using namespace smedley;

using iv = std::vector<int>;
using Version = PluginDefinition::Version;

Version v(std::string s, iv v)
{
    Version ver;
    ver.str = s;
    ver.num_versions = v.size();
    ver.versions = std::unique_ptr<int[]>(new int[ver.num_versions]);
    for (int i = 0; i < ver.num_versions; i++) {
        ver.versions[i] = v[i];
    }
    return ver;
}

TEST(PluginTests, ParsePluginVersionTest)
{
    ASSERT_EQ(Version::Parse("1.0.0"), v("1.0.0", iv({1, 0, 0})));
    ASSERT_EQ(Version::Parse("2.8.3"), v("2.8.3", iv({2, 8, 3})));
    ASSERT_NE(Version::Parse("3.8.3"), v("2.8.3", iv({2, 8, 3})));
}