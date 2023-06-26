# Smedley Preprocessor

This preprocessor is intended to aid with the defining of Smedley models. Victoria 2 was built with Visual C++; a compiler which optimizes register allocations, which in turn leads to to non-standard calling conventions. These optimized functions cannot be called normally, but instead require some boilerplate assembly code to move values to the appropriate registers. The smedley preprocessor aims to remove the complexity of declaring non-standard calling conventions, and generates the boilerplate for you.

## Issues with macros

Macros are one way to approach this problem. Below is an example within the definition of `CCountry`:

```C++
DEFINE_MEMBER_FN_ESI_1(AddAcceptedCulture, void, 0x00122310, CCulture *, culture);
```

Here we can see the macro `DEFINE_MEMBER_FN_ESI_1` is being invoked with the arguments `AddAcceptedCulture`, `void`, `0x00122310`, `CCulture *`, `cculture`. `DEFINE_MEMBER_FN_ESI_1` essentially means "define a member function `void AddAcceptedCulture(CCulture *culture)` which invokes the function at `0x00122310` by putting `this` in the `ESI` register pushing `culture` on the stack". Below is the macro definition:

```C++
#define DEFINE_MEMBER_FN_ESI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name) \
    ret_type fn_name(arg1_type arg1_name)                                          \
    {                                                                              \
        const uintptr_t _addr = memory::Map::base_addr + addr;                     \
        __asm mov esi, this __asm push arg1_name __asm call _addr                  \
    } // if a function ends with an embedded assembly instruction the 
      // compiler returns EAX

#define DEFINE_MEMBER_FN_ESI_1(fn_name, ret_type, addr, arg1_type, arg1_name) \
    DEFINE_MEMBER_FN_ESI_1_BASE(fn_name, ret_type, addr, arg1_type, arg1_name)     \
    static constexpr uintptr_t fn_name##_address = addr;
```

And invoked ultimately leads to the output (asm transformed into a block for clarity):

```C++
void AddAcceptedCulture(CCulture *culture)
{
    const uintptr_t _addr = memory::Map::base_addr + addr;
    __asm {
        mov esi, this
        push arg1_name
        call _addr
    }
}
```

This approach is problematic. This macro name is slightly confusing at first glance, and its one of the simple cases (see `DEFINE_MEMBER_FN_EDI_ECX_1_RET_ESI` lol). The macros header file became 400 lines long just defining all of calling conventions used by `CCountry` alone. And if any of the boilerplate needs to change it will be a real headache. Macros can't differentiate between template parameters and macro arguments which necessitates a workaround `TYPE_IDENTITY` macro which degrades static analysis output.

## Proposition

The smedley preprocessor processes code within block directives. These are opened by `{%` and closed by `%}`. Everything outside these blocks is ignored. The registers to `this`, parameters, and return values can all be specified within braces.

```C++
{%

void [0x00122310, this: esi] AddAcceptedCulture(CCulture *culture);
void [0x00113c80, this: edi] AddUnit([eax] CUnit *unit);
clausewitz::fixed_point<int64_t,48,15> [0x00139760, this: eax, return ptr: esi] CalcGovernmentNeedForGood(int good_type);

%}