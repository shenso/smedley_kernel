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

class Plugin;

class PluginLoader
{
	std::unordered_map<std::string, Plugin *> _plugins;
public:

	PluginLoader();
	void Load(Plugin *newPlugin, const std::string &name, const std::string &path);
};

class Plugin
{
	PluginMetadata _metadata;
public:
	Plugin();
	virtual ~Plugin() {};

	std::string name() { return _metadata.name;  };
	std::string path() { return _metadata.path;  };

	virtual void OnAttach() {};
	virtual void OnDetach() {};

	friend class PluginLoader;
};

} // core
} // smedley

#endif // PLUGIN_HPP_