#ifndef API_COUNTRY_HPP_
#define API_COUNTRY_HPP_

#include "../native/handles/CCountry.hpp"
#include "native.hpp"
#include "state.hpp"
#include <unordered_map>
#include <windows.h>

namespace smedley
{
namespace api
{

class SMEDLEY_API Country
{
	handles::CCountry *_handle;
	static HandleRegistry<handles::CCountry *, Country *> *_registry;
protected:
	Country(handles::CCountry *handle);
public:
	struct StateIterable
	{
		using ListIterator = MappedNativeListIterator<handles::CState *, State>;
		StateIterable(handles::CList<handles::CState *> *list) : _list(list) {}
		ListIterator begin() { return ListIterator(State::registry(), _list->begin()); };
		ListIterator end() { return ListIterator(State::registry(), _list->end()); };
	private:
		handles::CList<handles::CState *> *_list;
	};

	handles::CCountry *handle() { return _handle; }

	virtual std::string name() = 0;

	StateIterable states() { return StateIterable(&_handle->states); };
	static HandleRegistry<handles::CCountry *, Country *> *registry() { return _registry; };
};

class NativeCountry : public Country
{
public:
	NativeCountry(handles::CCountry *handle);

	static void InstallHooks(DWORD baseAddr);
	std::string name() override;
};

}
}

#endif // API_COUNTRY_HPP_