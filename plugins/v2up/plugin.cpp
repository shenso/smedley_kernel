#include <iostream>
#include <string>

#include <kernel.hpp>
#include <plugin.hpp>
#include <handles/console.hpp>

using namespace smedley;

namespace v2up
{

handles::ConsoleCommandOutput *V2UPCommandHandler(handles::ConsoleCommandOutput *out, handles::vector<handles::basic_string<char>> *argv)
{
	out->message.capacity = 0xf;
	out->message.size = 9;
	std::strcpy(out->message._impl, "V2UP v0.1");
	out->success = true;

	return out;
}

class V2UPPlugin : public core::Plugin
{
public:
	virtual ~V2UPPlugin()
	{
	}

	virtual void OnAttach()
	{
		//core::Kernel::GetInstance()->
		std::cout << "v2up attached!" << std::endl;
	}
};

PLUGIN_API core::Plugin *MakePlugin()
{
	return static_cast<core::Plugin *>(new V2UPPlugin());
}

PLUGIN_API const char *PluginName()
{
	return "v2up";
}

}