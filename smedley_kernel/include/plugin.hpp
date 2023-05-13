#ifndef PLUGIN_HPP_
#define PLUGIN_HPP_

#include <string>
#include <unordered_map>

#include <windows.h>

#define PLUGIN_API extern "C" __declspec(dllexport)

struct PluginListNode
{
	const char *name;
	PluginListNode *next;
};

PLUGIN_API void LoadPlugins(PluginListNode *root);

namespace smedley
{
namespace core
{

struct PluginMetadata
{
	std::string name;
	std::string path;
};

class Plugin
{
	PluginMetadata _metadata;
public:
	Plugin();
	virtual ~Plugin() {};

	std::string name() { return _metadata.name;  };
	std::string path() { return _metadata.path;  };

	virtual void OnAttach() = 0;
};

} // core
} // smedley

#endif // PLUGIN_HPP_