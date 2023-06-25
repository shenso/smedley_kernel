#include <smedley/plugin.hpp>
#include <smedley/eventregistry.hpp>
#include <smedley/events/console.hpp>
#include <smedley/std/string.hpp>
#include <smedley/std/vector.hpp>
#include <smedley/v2/console.hpp>
#include <functional>
#include <sstream>

namespace v2up
{

	namespace events = smedley::events;
	namespace sstd = smedley::sstd;
	namespace v2 = smedley::v2;

	v2::CConsoleCmd::SResult *OnCommand(v2::CConsoleCmd::SResult *__return_storage_ptr__, const sstd::vector<sstd::string> *argv)
	{
		__return_storage_ptr__->success = true;
		__return_storage_ptr__->message = "hello, world!";
		return __return_storage_ptr__;
	}

	class Plugin : public smedley::Plugin
	{
	public:
		Plugin() : smedley::Plugin()
		{
		}

		void OnLoad() override
		{
			logger().Info("Loading v2up...");
			AddEventHandler<events::ConsoleCmdManagerInitEvent>(
				"on_console_cmd_init",
				std::bind(&Plugin::OnConsoleCmdManagerInit, this, std::placeholders::_1));
		}

		void OnConsoleCmdManagerInit(events::ConsoleCmdManagerInitEvent &e)
		{
			logger().Info("Initializing commands...");

			auto cmd_data = new v2::CConsoleCmd::SCommandData{0};
			cmd_data->is_allowed = true;
			cmd_data->name = "v2up";
			cmd_data->num_aliases = 0;
			cmd_data->description = "displays the current version of the plugin.";
			cmd_data->handler = &OnCommand;

			e.cmd_mgr()->commands().push_back(cmd_data);
		}
	};

}

PLUGIN_API smedley::Plugin *CreatePlugin()
{
	return static_cast<smedley::Plugin *>(new v2up::Plugin{});
}
