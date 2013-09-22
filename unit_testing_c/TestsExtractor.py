""" Extracts unit test information from c files

TODO:
- encode test suite names in source files rather than
  having separate config files
"""

import re

def main():
	pass


def getTestFunctionsFromFile(path):
	""" Returns a list of C function names that were defined as:

			TEST_FUNCTION xxx();

			within the given file.
	"""
	function_pattern = re.compile(r'TEST_FUNCTION\s+.+\s*\(')
	infile = open(path)
	intext = infile.read()
	infile.close()
	raw_function_list = re.findall(function_pattern, intext)
	clean_function_list = []
	for function in raw_function_list:
		function = function.replace('TEST_FUNCTION','')
		function = function.replace('(','')
		function = function.replace('\n','').replace('\r','')
		function = function.strip()
		clean_function_list.append(function)
	return clean_function_list


if __name__ == "__main__":
    main()
