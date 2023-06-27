#pragma once

#include "../memory.hpp"
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string>

namespace smedley::sstd
{

    template <typename T,
              class Traits = std::char_traits<T>,
              class Allocator = std::allocator<T>>
    class basic_string
    {
    public:
        using size_type = size_t;

        using reference = T &;
        using const_reference = const T &;
    protected:
        static constexpr size_type default_capacity = 0xf;

        union {
            T buf[default_capacity + 1];
            T *ptr;
        } _impl;
        size_type _size;
        size_type _capacity;
        Allocator _alloc;
    public:
        basic_string() : _size(0), _capacity(default_capacity)
        {
            _impl.buf[0] = static_cast<T>(0x0);
        }

        basic_string(const T *str)
        {
            size_type n = Traits::length(str);
            if (n > default_capacity) {
                DWORD old_protect;
                _impl.ptr = reinterpret_cast<T *>(HeapAlloc(memory::Map::game_heap, 0, (n * sizeof(T)) + 1));
                std::memcpy(_impl.ptr, str, n * sizeof(T));
                _capacity = n;
            } else {
                std::memcpy(_impl.buf, str, sizeof(_impl.buf));
                _capacity = default_capacity;
            }

            _size = n;
        }

        inline const T *c_str() const {
            if (_capacity > default_capacity) {
                return _impl.ptr;
            }
            return _impl.buf;
        }

        inline size_type size() const noexcept { return _size; }
        inline size_type capacity() const noexcept { return _capacity; }

        inline reference operator[](size_type pos)
        {
            if (_capacity > default_capacity) {
                return _impl.ptr[pos];
            }
            return _impl.buf[pos];
        }

        inline const_reference operator[](size_type pos) const
        {
            if (_capacity > default_capacity) {
                return _impl.ptr[pos];
            }
            return _impl.buf[pos];
        }

        friend bool operator==(const basic_string<T> &lhs, const basic_string<T> &rhs)
        {
            return Traits::compare(lhs.c_str(), rhs.c_str(), std::max(lhs.size(), rhs.size())) == 0;
        }
    };

    using string = basic_string<char>;

    static_assert(sizeof(string) == 0x1c);

}