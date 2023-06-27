#include "plugin.hpp"
#include "util.hpp"
#include <cstdlib>
#include <toml.hpp>

namespace smedley
{

    PluginDefinition::Version PluginDefinition::Version::Parse(const std::string &s)
    {
        PluginDefinition::Version ver;
        auto ver_strs = SplitString(s, '.');

        ver.str = s;
        ver.num_versions = ver_strs.size();
        ver.versions = std::unique_ptr<int[]>(new int[ver.num_versions]);
        for (int i = 0; i < ver.num_versions; i++) {
            ver.versions[i] = std::atoi(ver_strs[i].c_str());
        }

        return ver;
    }

    Plugin::Plugin() : _checksum(0), _logger(nullptr)
    {
    }

    PluginDefinition PluginDefinition::Read(const std::string &filename)
    {
        PluginDefinition def{};
        auto tbl = toml::parse_file(filename);

        std::optional<std::string> id = tbl["id"].value<std::string>();
        std::optional<std::string> name = tbl["name"].value<std::string>();
        std::optional<std::string> module_name = tbl["module"].value<std::string>();

        if (!id.has_value() || !name.has_value()  || !module_name.has_value()) {
            // TODO: custom exception
            std::runtime_error("plugin definition missing requirement!");
        }

        def.id = *id;
        def.name = *name;
        def.module_name = *module_name;

        return def;
    }

    bool operator==(const PluginDefinition::Version &lhs, const PluginDefinition::Version &rhs)
    {
        if (lhs.num_versions != rhs.num_versions) {
            return false;
        }

        for (int i = 0; i < lhs.num_versions; i++) {
            if (lhs.versions[i] != rhs.versions[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const PluginDefinition::Version &lhs, const PluginDefinition::Version &rhs)
    {
        if (lhs.num_versions != rhs.num_versions) {
            return true;
        }

        for (int i = 0; i < lhs.num_versions; i++) {
            if (lhs.versions[i] != rhs.versions[i]) {
                return true;
            }
        }

        return false;
    }
}