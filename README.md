ucToolbox
=========

Collection of C++ libraries intended for use in embedded systems

Library restrictions
================
- No dynamic memory usage
-- I may change my mind about this. If I do, any library module that uses dynamic memory will clearly state so.
- No exceptions or RTTI
- No STL (for the moment, due to my lack of understanding)

Aims
====

- To provide a large, useful set of libraries, useable in many embedded systems. 
- To learn how to do so using C++ rather than C
- To learn how to use git/github in the process
- To provide this library to anyone, with a permissive license (MIT-ish?)

Motivations
===========

- There are good libraries scattered about, but I haven't managed to find a single source for a large variety of applications. 
- I've used C for long enough - Arduino has showed me how easy it is to use C++ for a tiny embedded system.
- I hate seeing useful code with a GPL or similar license. There I said it. I do a lot of coding at work and don't want to steal code.