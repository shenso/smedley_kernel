#include <smedley/plugin.hpp>
#include <smedley/eventregistry.hpp>
#include <smedley/events/console.hpp>
#include <smedley/std/string.hpp>
#include <smedley/std/vector.hpp>
#include <smedley/v2/console.hpp>
#include <smedley/v2/gamestate.hpp>
#include <smedley/v2/db/culture.hpp>
#include <functional>
#include <sstream>

namespace v2up
{

	namespace events = smedley::events;
	namespace sstd = smedley::sstd;
	namespace v2 = smedley::v2;

	v2::CConsoleCmd::SResult OnCommand(const sstd::vector<sstd::string> &argv)
	{
		return v2::CConsoleCmd::SResult("Hello, world!");
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

			auto culture_db = v2::CCultureDataBase::instance();
			auto culture = culture_db->table().Find("yankee");
			for (auto country : v2::CCurrentGameState::instance()->countries()) {
				if (!country->exists()) {
					continue;
				}

				country->AddAcceptedCulture(culture);
				logger().Info(std::string("added yankee culture to ") + country->name().c_str());
			}

			auto cmd_data = new v2::CConsoleCmd::SCommandData{0};
			cmd_data->is_allowed = true;
			cmd_data->name = "v2up";
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
