#pragma once 

#include "apimacros.hpp"
#include "memory.hpp"
#include <cstdint>

#define DEFINE_STATIC_GETTER(fn_name, ret_type, addr)          \
    static constexpr uintptr_t fn_name##_address = addr;       \
    static ret_type fn_name()                                  \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        return *(reinterpret_cast<ret_type *>(_addr));         \
    }

#define DECLARE_MEMBER_FN_CLASS(class_name) \
    typedef class_name _MEMBER_FN_CLASS

#define DEFINE_MEMBER_FN_1(fn_name, ret_type, addr, arg1_type, arg1_name)   \
    static constexpr uintptr_t fn_name##_address = addr;                    \
    ret_type fn_name(arg1_type arg1_name)                                   \
    {                                                                       \
        const uintptr_t _addr = memory::Map::base_addr + addr;              \
        struct _empty                                                       \
        {                                                                   \
        };                                                                  \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name); \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name);          \
    }

#define DEFINE_MEMBER_FN_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    static constexpr uintptr_t fn_name##_address = addr;                                         \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                   \
    {                                                                                            \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                   \
        struct _empty                                                                            \
        {                                                                                        \
        };                                                                                       \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name); \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                     \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name);                    \
    }

#define DEFINE_MEMBER_FN_3(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name) \
    static constexpr uintptr_t fn_name##_address = addr;                                                              \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name)                                   \
    {                                                                                                                 \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                        \
        struct _empty                                                                                                 \
        {                                                                                                             \
        };                                                                                                            \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name); \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                                          \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name, arg3_name);                              \
    }

#define DEFINE_MEMBER_FN_ESI_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;                      \
    ret_type fn_name(arg1_type arg1_name)                                     \
    {                                                                         \
        const uintptr_t _addr = memory::Map::base_addr + addr;                \
        __asm mov esi, this __asm push arg1_name __asm call _addr             \
    }

#define DEFINE_MEMBER_FN_ESI_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;                                            \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                      \
    {                                                                                               \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                      \
        __asm mov esi, this __asm push arg1_name __asm push arg2_name __asm call _addr              \
    }

#define DEFINE_MEMBER_FN_1_ESI(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;                      \
    ret_type fn_name(arg1_type arg1_name)                                     \
    {                                                                         \
        const uintptr_t _addr = memory::Map::base_addr + addr;                \
        __asm mov esi, arg1_name __asm push this __asm call _addr             \
    }

#define DEFINE_MEMBER_FN_EDI_0(fn_name, ret_type, addr)        \
    static constexpr uintptr_t fn_name##_address = addr;       \
    ret_type fn_name()                                         \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        __asm mov edi, this __asm call _addr                   \
    }

#define DEFINE_MEMBER_FN_EDI_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;                      \
    ret_type fn_name(arg1_type arg1_name)                                     \
    {                                                                         \
        const uintptr_t _addr = memory::Map::base_addr + addr;                \
        __asm mov edi, this __asm push arg1_name __asm call _addr             \
    }

#define DEFINE_MEMBER_FN_EDI_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;                                            \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                      \
    {                                                                                               \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                      \
        __asm mov edi, this __asm push arg1_name __asm push arg2_name __asm __asm call _addr        \
    }

#define DEFINE_MEMBER_FN_EDI_4(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name) \
    static constexpr uintptr_t fn_name##_address = addr;                                                                                        \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name, arg4_type arg4_name)                                        \
    {                                                                                                                                           \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                                                  \
        __asm mov edi, this __asm push arg1_name __asm push arg2_name __asm push arg3_name __asm push arg4_name __asm call _addr                \
    }

#define DEFINE_MEMBER_FN_EDI_EAX(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;                        \
    ret_type fn_name(arg1_type arg1_name)                                       \
    {                                                                           \
        const uintptr_t _addr = memory::Map::base_addr + addr;                  \
        __asm mov edi, this __asm mov eax, arg1_name __asm call _addr           \
    }
