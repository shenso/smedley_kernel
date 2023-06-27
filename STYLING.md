# Table of Contents

1. [Indentation](#indentation)
    1. [Brace Placement](#brace-placement)
    2. [Switch Statements](#switch-statements)
2. [Header Files](#header-files)
3. [Naming](#naming)
    1. [Function, Class, and Struct names](#function-class-and-struct-names)
    2. [Variables](#variables)
    3. [Class Methods](#class-methods)
    4. [Class Members](#class-members)

# Styling Guide

When contributing to the project, please be sure to follow the following styling rules.

## Indentation

Indentations are 4 characters long, using spaces, not tabs.

### Brace Placement

Smedley follows a brace placement style similar to [K&R](https://en.wikipedia.org/wiki/Indentation_style#K&R_style) of brace placement. Functions, classes and structs have their braces placed on the next line. Control flow statements have their brace placed on the same line.

```C++
class ExamplePlugin : public smedley::Plugin
{
public:
    void OnLoad()
    {
        if (true) {
            logger().Info("Hello, world!");
        }
    }
};
```

### Switch Statements

Case clauses within a switch should not be indented. Case fallthrough should be avoided whenever possible.

```C++
switch (ch) {
case 'a':
    // ...
    break;
case 't':
    // ...
    break;
default:
}
```

## Header Files

Begin all header files with `#pragma once`

## Naming

### Function, Class, and Struct names

Use PascalCase for function, class, and struct names:

```C++
void ThisIsAFunction()
{
    // ...
}

class ExampleClass
{
    int ExampleMethod();
};
```

### Variables

Variables should be allow lowercase and snake_case.

### Class Methods

Class methods should typically use PascalCase like functions. Property-like methods - that is getters with no arguments and setters with a single argument should remain lowercase and snake_case akin to a variable name.

```C++
class HelloWorld
{
    int _foo;
public:
    inline int foo() { return _foo; }
    inline void foo(int val) { _foo = val; }
}
```

### Class members

Private and protected member variables should be prefixed with an underscore. Public members should by styled as normal variable names.

```C++
class HelloWorld
{
protected:
    int _a;
    char *_b;
public:
    long long c;
}
```