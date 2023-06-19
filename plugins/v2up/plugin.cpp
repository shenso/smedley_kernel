#include <smedley/plugin.hpp>

namespace v2up
{

	class Plugin : public smedley::Plugin
	{
		void OnLoad() override
		{
			logger().Info("Hello, world!");
		}
	};

}

PLUGIN_API smedley::Plugin *CreatePlugin()
{
	return static_cast<smedley::Plugin *>(new v2up::Plugin{});
}
