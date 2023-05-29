#ifndef API_OBJECT_HPP_
#define API_OBJECT_HPP_

#include <iterator>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "../native/handles/CList.hpp"

#ifdef SMEDLEY_KERNEL
#define SMEDLEY_API __declspec(dllexport)
#else
#define SMEDLEY_API __declspec(dllimport)
#endif

namespace smedley
{
namespace api
{

template <typename K, typename V>
class HandleRegistry
{
public:
private:
	std::unordered_map<K, V> _registry;
public:
	V Get(K native) { return _registry.at(native); }
	bool Has(K native) { return _registry.find(native) != _registry.end(); }
	void Register(K native, V obj)
	{
		if (Has(native)) {
			throw std::runtime_error("native mapping is already registered!");
		}

		_registry.insert(std::make_pair(native, obj));
	}
	void Unregister(K native)
	{
		_registry.erase(_registry.find(native));
	}
};


template <typename K, typename V>
struct MappedNativeListIterator : public std::iterator<std::bidirectional_iterator_tag, V>
{
	using ListIterator = typename native::handles::CList<K>::Iterator;

	MappedNativeListIterator(HandleRegistry<K, pointer> *registry, ListIterator iter)
		: _registry(registry), _iter(iter) {}

	reference operator*() const { return *_registry->Get(*_iter); }
	pointer operator->() { return _registry->Get(*_iter); }
	MappedNativeListIterator &operator++() { ++_iter; return *this; }
	MappedNativeListIterator operator++(int) { MappedNativeListIterator tmp = *this; ++(*this); return tmp; }
	MappedNativeListIterator &operator--() { --_iter; return *this; }
	MappedNativeListIterator operator--(int) { MappedNativeListIterator tmp = *this; --(*this); return tmp; }
	friend bool operator==(const MappedNativeListIterator &a, const MappedNativeListIterator &b) { return a._iter == b._iter; }
	friend bool operator!=(const MappedNativeListIterator &a, const MappedNativeListIterator &b) { return a._iter != b._iter; }
private:
	HandleRegistry<K, pointer> *_registry;
	ListIterator _iter;
};

}
}

#endif // API_OBJECT_HPP_