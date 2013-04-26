import os, re

SOURCE_FILE_EXTS = [".c", ".cpp"]
HEADER_FILE_EXTS = [".h", ".hpp"]

OUTPUT_SOURCE_FILE = "test_suites.c"
OUTPUT_HEADER_FILE = "test_suites.h"

UNIT_TEST_SOURCE_FILE = "UnitTesting.c"
UNIT_TEST_HEADER_FILE = "UnitTesting.h"

TESTS_LOCATION = "tests"

EXCLUDE_FILES = [
    UNIT_TEST_SOURCE_FILE,
    UNIT_TEST_HEADER_FILE,
    OUTPUT_SOURCE_FILE,
    OUTPUT_HEADER_FILE,
]

GEN_FILE_HEADER_TEXT = """
/*
Generated by TestSuiteGenerator.py. Don't edit this file manually.
*/
"""

DEBUG = True

def main():
    sources, headers = getSourceAndHeaderFiles(TESTS_LOCATION)
    if DEBUG:
        print "Ignoring the following files:"
        for item in EXCLUDE_FILES:
            print item
    generateOutputSource(sources)
    generateOutputHeader(sources)

def generateOutputSource(sources):
    ofile = open(OUTPUT_SOURCE_FILE,"w")
    ofile.write(GEN_FILE_HEADER_TEXT)
    ofile.write("#include \"" + UNIT_TEST_HEADER_FILE + "\"\n")
    ofile.write("#include \"" + OUTPUT_HEADER_FILE + "\"\n\n")

    test_functions = getAllTestFunctionsInSourceList(sources)
    ofile.write(genTestFuncDeclarations(test_functions))
    ofile.write("\n")

    for source_file in sources:
        ofile.write(genTestSuite(source_file))

    ofile.write(getAllTestSuitesStruct(sources))
    ofile.close()

def generateOutputHeader(sources):
    ofile = open(OUTPUT_HEADER_FILE,"w")
    ofile.write(GEN_FILE_HEADER_TEXT)
    header_guard_name = OUTPUT_HEADER_FILE.replace('.','_').upper()
    ofile.write("#ifndef " + header_guard_name + "\n")
    ofile.write("#define " + header_guard_name + "\n\n")

    ofile.write("#include \"" + UNIT_TEST_HEADER_FILE + "\"\n\n")

    for source in sources:
        ofile.write("extern const TestSuite " +
                    genTestSuiteName(source) + ";\n")
    ofile.write("\n")

    num_suites = len(sources)
    ofile.write("#define TOTAL_SUITES    " + str(num_suites) + "\n\n")
    ofile.write("extern const TestSuite* all_suites[TOTAL_SUITES];\n\n")

    ofile.write("#endif // " + header_guard_name + "\n")
    ofile.close()

def getAllTestFunctionsInSourceList(source_file_list):
    test_functions = []
    for file in source_file_list:
        if DEBUG:
            print "reading", file
        funcs = getTestFunctionsFromFile(file)
        if DEBUG:
            for func in funcs:
                print "    found: ", func
        test_functions.extend(funcs)
    return test_functions

def genTestFuncDeclarations(test_functions):
    output = ""
    for function in test_functions:
        output += "TEST_FUNCTION " + function + "();\n"
    return output

def genTestSuite(source_file):
    suite_name = genTestSuiteName(source_file)
    test_functions = getTestFunctionsFromFile(source_file)

    output = "TEST_FUNCTION_ptr _" + suite_name + "[] = {\n"

    for function in test_functions:
        output += "    " + function + ",\n"
    output += "};\n\n"

    output += "const TestSuite " + suite_name + " = {\n"
    output += '    "' + suite_name + '",\n'
    output += "    sizeof(_" + suite_name + ") / sizeof(TEST_FUNCTION_ptr),\n"
    output += "    _" + suite_name + "\n"
    output += "};\n\n"

    return output

def getAllTestSuitesStruct(source_files):
    num_suites = len(source_files)
    output = "const TestSuite* all_suites[TOTAL_SUITES] = {\n"

    for file in source_files:
        output += "    &" + genTestSuiteName(file) + ",\n"

    output += "};\n"
    return output

def genTestSuiteName(source_file):
    filename = os.path.split(source_file)[1]
    return os.path.splitext(filename)[0]

def getTestFunctionsFromFile(path):
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

def getSourceAndHeaderFiles(path):
    sources = []
    headers = []
    EXCLUDE_FILES.extend(getExcludesFromFile("excludes.txt"))
    
    for item in os.listdir(path):
        if item in EXCLUDE_FILES:
            continue
        fullpath = os.path.join(path,item)
        if isSourceFile(fullpath):
            sources.append(fullpath)
        elif isHeaderFile(fullpath):
            headers.append(fullpath)
    return sources, headers

def getExcludesFromFile(path):
    infile = open(path)
    excludes = []
    for line in infile:
        if not line.strip().startswith("#") and not line.strip() == "":
            excludes.append(line.strip())
    return excludes

def isSourceFile(path):
    if os.path.isfile(path):
        for ext in SOURCE_FILE_EXTS:
            if path.endswith(ext):
                return True
    return False

def isHeaderFile(path):
    if os.path.isfile(path):
        for ext in HEADER_FILE_EXTS:
            if path.endswith(ext):
                return True
    return False

if __name__ == "__main__":
    main()
