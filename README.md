ucToolbox
=========

Collection of C++ libraries intended for use in embedded systems

Library information
================
- No dynamic memory usage
-- I may change my mind about this. If I do, any library module that uses dynamic memory will clearly state so.
- No exceptions or RTTI
- Will use STL. For my purposes, this will need to be a permissively licensed STL implementation such as
LLVM's libc++ (http://libcxx.llvm.org/).

Aims
====
- To provide a reuseable set of classes, data structures and functions that allows quick implementation
of common functionality. Similar to the arduino library but with a permissive license (ie. you can use
this for proprietary applications).
- To learn how to do so using C++ rather than C
- To learn how to use git/github in the process

Motivations
===========
- There are good libraries scattered about, but I haven't managed to find a single source of a large variety 
of applications with a permissive license.
- I've used C for long enough - there are too many nice features of C++ to keep battling with C.
- I find the GPL and LGPL too restrictive. The fact that they are a barrier to use in closed-source commercial 
applications is a negative in my mind. I am more likely to contribute to source that lets me use it where I want.
