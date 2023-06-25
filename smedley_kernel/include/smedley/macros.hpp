#pragma once 

#include "apimacros.hpp"
#include "memory.hpp"
#include <cstdint>

template <typename Fn>
struct _identity_helper;

template <typename R, typename Arg>
struct _identity_helper<R(Arg)>
{
    using type = Arg;
};

// used to get around template parameters being parsed as macro arguments
#define TYPE_IDENTITY(...) _identity_helper<void __VA_ARGS__>::type

#define DEFINE_STATIC_GETTER_BASE(fn_name, ret_type, addr)     \
    static ret_type fn_name()                                  \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        return *(reinterpret_cast<ret_type *>(_addr));         \
    }

#define DEFINE_STATIC_GETTER(fn_name, ret_type, addr)  \
    DEFINE_STATIC_GETTER_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DECLARE_MEMBER_FN_CLASS(class_name) \
    typedef class_name _MEMBER_FN_CLASS

#define DEFINE_MEMBER_FN_0_BASE(fn_name, ret_type, addr)       \
    ret_type fn_name()                      \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        struct _empty                                          \
        {                                                      \
        };                                                     \
        typedef ret_type (_empty::*_##fn_name##_type)();       \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;   \
        return (reinterpret_cast<_empty *>(this)->*fn)();      \
    }

#define DEFINE_MEMBER_FN_0(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_0_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                      \
    {                                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr;                 \
        struct _empty                                                          \
        {                                                                      \
        };                                                                     \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name);    \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                   \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name);             \
    }

#define DEFINE_MEMBER_FN_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    DEFINE_MEMBER_FN_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                       \
    {                                                                                                \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                       \
        struct _empty                                                                                \
        {                                                                                            \
        };                                                                                           \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name);     \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                         \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name);                        \
    }

#define DEFINE_MEMBER_FN_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    DEFINE_MEMBER_FN_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_3_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name)                                        \
    {                                                                                                                      \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                             \
        struct _empty                                                                                                      \
        {                                                                                                                  \
        };                                                                                                                 \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name);      \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                                               \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name, arg3_name);                                   \
    }

#define DEFINE_MEMBER_FN_3(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name)  \
    DEFINE_MEMBER_FN_3_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_4_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name, arg4_type arg4_name)                                         \
    {                                                                                                                                            \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                                                   \
        struct _empty                                                                                                                            \
        {                                                                                                                                        \
        };                                                                                                                                       \
        typedef ret_type (_empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name, arg4_type arg4_name);       \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                                                                     \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name, arg3_name, arg4_name);                                              \
    }

#define DEFINE_MEMBER_FN_4(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name)  \
    DEFINE_MEMBER_FN_3_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_THISCALL_0_BASE(fn_name, ret_type, addr)   \
    ret_type fn_name()                                              \
    {                                                               \
        const uintptr_t _addr = memory::Map::base_addr + addr;      \
        struct _empty                                               \
        {                                                           \
        };                                                          \
        typedef ret_type (__thiscall _empty::*_##fn_name##_type)(); \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;        \
        return (reinterpret_cast<_empty *>(this)->*fn)();           \
    }

#define DEFINE_MEMBER_FN_THISCALL_0(fn_name, ret_type, addr, arg1_type, arg1_name) \
    DEFINE_MEMBER_FN_THISCALL_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name)         \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_THISCALL_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                               \
    {                                                                                   \
        const uintptr_t _addr = memory::Map::base_addr + addr;                          \
        struct _empty                                                                   \
        {                                                                               \
        };                                                                              \
        typedef ret_type (__thiscall _empty::*_##fn_name##_type)(arg1_type arg1_name);  \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                            \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name);                      \
    }

#define DEFINE_MEMBER_FN_THISCALL_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    DEFINE_MEMBER_FN_THISCALL_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name)         \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_THISCALL_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                                \
    {                                                                                                         \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                \
        struct _empty                                                                                         \
        {                                                                                                     \
        };                                                                                                    \
        typedef ret_type (__thiscall _empty::*_##fn_name##_type)(arg1_type arg1_name, arg2_type arg2_name);   \
        _##fn_name##_type fn = *(_##fn_name##_type *)&_addr;                                                  \
        return (reinterpret_cast<_empty *>(this)->*fn)(arg1_name, arg2_name);                                 \
    }

#define DEFINE_MEMBER_FN_THISCALL_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    DEFINE_MEMBER_FN_THISCALL_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)         \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name)   \
    ret_type fn_name(arg1_type arg1_name)                                                \
    {                                                                                    \
        const uintptr_t _addr = memory::Map::base_addr + addr;                           \
        ret_type ret_val;                                                                \
        auto val_ptr = &ret_val;                                                         \
        {                                                                                \
            __asm push this __asm push arg1_name __asm mov esi, val_ptr __asm call _addr \
        }                                                                                \
        return ret_val;                                                                  \
    }

#define DEFINE_MEMBER_FN_1_RET_ESI(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_2_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                                \
    {                                                                                                         \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                \
        ret_type ret_val;                                                                                     \
        auto val_ptr = &ret_val;                                                                              \
        {                                                                                                     \
            __asm push this __asm push arg1_name __asm push arg2_name __asm mov esi, val_ptr __asm call _addr \
        }                                                                                                     \
        return ret_val;                                                                                       \
    }

#define DEFINE_MEMBER_FN_2_RET_ESI(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    DEFINE_MEMBER_FN_2_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_ESI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov esi, this __asm push arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_ESI_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    DEFINE_MEMBER_FN_ESI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name)     \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_ESI_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                           \
    {                                                                                                    \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                           \
        __asm mov esi, this __asm push arg1_name __asm push arg2_name __asm call _addr                   \
    }

#define DEFINE_MEMBER_FN_ESI_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    DEFINE_MEMBER_FN_ESI_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_1_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov esi, arg1_name __asm push this __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_1_ESI(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_1_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_1_EDI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov edi, arg1_name __asm push this __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_1_EDI(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_1_EDI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;


#define DEFINE_MEMBER_FN_EAX_0_BASE(fn_name, ret_type, addr)   \
    ret_type fn_name()                                         \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        __asm mov eax, this __asm call _addr                   \
    }

#define DEFINE_MEMBER_FN_EAX_0(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_EAX_0_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EAX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov eax, this __asm call _addr                                       \
    }

#define DEFINE_MEMBER_FN_EAX_1(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EAX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_0_BASE(fn_name, ret_type, addr)   \
    ret_type fn_name()                                         \
    {                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr; \
        __asm mov edi, this __asm call _addr                   \
    }

#define DEFINE_MEMBER_FN_EDI_0(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_EDI_0_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov edi, this __asm push arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_EDI_1(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EDI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                           \
    {                                                                                                    \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                           \
        __asm mov edi, this __asm push arg1_name __asm push arg2_name __asm __asm call _addr             \
    }

#define DEFINE_MEMBER_FN_EDI_2(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    DEFINE_MEMBER_FN_EDI_2_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_4_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name, arg3_type arg3_name, arg4_type arg4_name)                                             \
    {                                                                                                                                                \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                                                       \
        __asm mov edi, this __asm push arg1_name __asm push arg2_name __asm push arg3_name __asm push arg4_name __asm call _addr                     \
    }

#define DEFINE_MEMBER_FN_EDI_4(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name)  \
    DEFINE_MEMBER_FN_EDI_4_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name, arg4_type, arg4_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov edx, this __asm push arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_EDX_1(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EDX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDX_EDI_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                              \
    {                                                                                  \
        const uintptr_t _addr = memory::Map::base_addr + addr;                         \
        __asm mov edx, this __asm mov esi, arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_EDX_EDI_0(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EDX_EDI_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_EAX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                              \
    {                                                                                  \
        const uintptr_t _addr = memory::Map::base_addr + addr;                         \
        __asm mov edi, this __asm mov eax, arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_EDI_EAX_0(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EDI_EAX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_EDX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                              \
    {                                                                                  \
        const uintptr_t _addr = memory::Map::base_addr + addr;                         \
        __asm mov edi, this __asm mov edx, arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_EDI_EDX_0(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EDI_EDX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_EDX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                               \
    {                                                                                                        \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                               \
        __asm mov edi, this __asm mov edx, arg1_name __asm push arg2_name __asm call _addr                   \
    }

#define DEFINE_MEMBER_FN_EDI_EDX_1(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    DEFINE_MEMBER_FN_EDI_EDX_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_ESI_EDX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                              \
    {                                                                                  \
        const uintptr_t _addr = memory::Map::base_addr + addr;                         \
        __asm mov esi, this __asm mov edx, arg1_name __asm call _addr                  \
    }

#define DEFINE_MEMBER_FN_ESI_EDX_0(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_ESI_EDX_0_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EAX_ESI_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                                      \
    {                                                                                          \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                 \
        ret_type ret_val;                                                                      \
        auto val_ptr = &ret_val;                                                               \
        {                                                                                      \
            __asm mov eax, this __asm mov esi, val_ptr __asm push arg1_name __asm call _addr   \
        }                                                                                      \
        return ret_val;                                                                        \
    }

#define DEFINE_MEMBER_FN_EAX_ESI_1_RET_ESI(fn_name, ret_type, addr, arg1_type, arg1_name)  \
    DEFINE_MEMBER_FN_EAX_ESI_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_ECX_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)  \
    ret_type fn_name(arg1_type arg1_name, arg2_type arg2_name)                                                        \
    {                                                                                                                 \
        const uintptr_t _addr = memory::Map::base_addr + addr;                                                        \
        ret_type ret_val;                                                                                             \
        auto val_ptr = &ret_val;                                                                                      \
        {                                                                                                             \
            __asm mov edi, this __asm mov ecx, arg1_name __asm mov esi, val_ptr __asm push arg2_name __asm call _addr \
        }                                                                                                             \
        return ret_val;                                                                                               \
    }

#define DEFINE_MEMBER_FN_EDI_ECX_1_RET_ESI(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name) \
    DEFINE_MEMBER_FN_EDI_ECX_1_RET_ESI_BASE(fn_name, ret_type, addr, arg1_type, arg1_name, arg2_type, arg2_name)          \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EAX_0_RET_ECX_BASE(fn_name, ret_type, addr)    \
    ret_type fn_name()                                                  \
    {                                                                   \
        const uintptr_t _addr = memory::Map::base_addr + addr;          \
        ret_type ret_val;                                               \
        auto val_ptr = &ret_val;                                        \
        {                                                               \
            __asm mov eax, this __asm mov ecx, val_ptr __asm call _addr \
        }                                                               \
        return ret_val;                                                 \
    }

#define DEFINE_MEMBER_FN_EAX_0_RET_ECX(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_EAX_0_RET_ECX_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_0_RET_EAX_BASE(fn_name, ret_type, addr)    \
    ret_type fn_name()                                                  \
    {                                                                   \
        const uintptr_t _addr = memory::Map::base_addr + addr;          \
        ret_type ret_val;                                               \
        auto val_ptr = &ret_val;                                        \
        {                                                               \
            __asm mov edi, this __asm mov eax, val_ptr __asm call _addr \
        }                                                               \
        return ret_val;                                                 \
    }

#define DEFINE_MEMBER_FN_EDI_0_RET_EAX(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_EDI_0_RET_EAX_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;

#define DEFINE_MEMBER_FN_EDI_0_RET_1_BASE(fn_name, ret_type, addr)    \
    ret_type fn_name()                                                  \
    {                                                                   \
        const uintptr_t _addr = memory::Map::base_addr + addr;          \
        ret_type ret_val;                                               \
        auto val_ptr = &ret_val;                                        \
        {                                                               \
            __asm mov edi, this __asm push val_ptr __asm call _addr \
        }                                                               \
        return ret_val;                                                 \
    }

#define DEFINE_MEMBER_FN_EDI_0_RET_1(fn_name, ret_type, addr)  \
    DEFINE_MEMBER_FN_EDI_0_RET_1_BASE(fn_name, ret_type, addr) \
    static constexpr uintptr_t fn_name##_address = addr;   