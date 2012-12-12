Very simple logging module that includes code based on the global logging level. 

Configure logging with logging_conf.h. There you can set the global logging level
and include the header to the logging functions you want to use. See logging_stdio.hpp/cpp
for examples.

One day I'll learn how to interface logging nicely with standard iostreams - currently I don't
know how to do this without having to include iostream, which makes code size much larger. The
goal of this module is to provide logging ability while keeping code size and ram usage to a 
minimum.