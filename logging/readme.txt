This module contains a logging class for variable verbosity output to any stream object.
Additionally, logging code (and any code) can be conditionally compiled by using 
"conditional_logging.hpp". Obviously this does not allow for run-time logging level changes,
but is handy for reducing code size while still keeping debugging code in your source.
See LogStdio_unitTest() for an example of how to use this module.