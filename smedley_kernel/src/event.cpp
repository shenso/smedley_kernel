#include "event.hpp"
#include "eventregistry.hpp"
#include "events/console.hpp"

#define DECLARE_REGISTRY(Ev) \
    smedley::EventRegistry<Ev>::Handlers smedley::EventRegistry<Ev>::_handlers = smedley::EventRegistry<Ev>::Handlers{};

using namespace smedley::events;

DECLARE_REGISTRY(ConsoleCmdManagerInitEvent);

namespace smedley
{

    void Event::Cancel()
    {
        _is_cancelled = _cancelable;
    }

}