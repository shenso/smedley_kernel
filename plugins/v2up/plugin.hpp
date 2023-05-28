#ifndef V2UP_PLUGIN_HPP_
#define V2UP_PLUGIN_HPP_

#include <smedley/plugin.hpp>

using namespace smedley;

namespace v2up
{

class V2UPPlugin : public core::Plugin
{
public:
	virtual ~V2UPPlugin();
	virtual void OnAttach();
};

}

#endif // V2UP_PLUGIN_HPP_