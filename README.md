JMacro - Re-implementation of macro processor
=============================================

This project is originally created for preprocessing Java code, but I
recently realized that you are allowed to run `cpp` on Java code

Feel free to do this in C. Nothing's implemented yet but work plan

## Design

Unlike those monolithic GNU softwares, my project aims to be modular. Builtin modules are listed below:

* Define: Deals with `#define` directive
* include: Deals with `#include` directive
* Comment: Strips comments out

### Preprocessing Progress

1. Parsing command line arguments
2. Calling modules to expand macros
3. Check if all macros are expanded
	* If not, jump to step 2

## Current Plan

- [ ] Define macro using `#define`
- [ ] Include other files using `#include`
- [ ] Undefine macro using `#undef`
- [ ] Strip out comments

## Further Goals

* Condition macro like `#if`
* Optimization for Java
* Builtin macros for conveniencing x86 Assembly Language.
* Macros look like functions

