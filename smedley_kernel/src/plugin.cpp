#include "plugin.hpp"
#include "kernel.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <libloaderapi.h>

PLUGIN_API void LoadPlugins(PluginListNode *root)
{
	PluginListNode *node = root;
	while (node != nullptr) {
		MessageBoxA(NULL, node->name, "IT WORKS!", MB_ICONEXCLAMATION);
		node = node->next;
	}

	MessageBoxA(NULL, "LOADING PLUGINS", "IT WORKS?", MB_ICONEXCLAMATION);
}

namespace smedley
{
namespace core
{

Plugin::Plugin()
{
}

}
}