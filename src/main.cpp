#include <cstdio>    // For FILE and fopen
#include <iostream>  // For input/output
#include <cerrno>    // For errno
#include <cstring>   // For strerror

// Declare external lexer and parser functions
extern int yyparse();
extern FILE* yyin;

// Main entry point
int main(int argc, char* argv[]) {
    // Ensure a file is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.netcraft>" << std::endl;
        return 1;
    }

    // Open the input file
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error: Cannot open file " << argv[1] 
                  << " (" << strerror(errno) << ")" << std::endl;
        return 1;
    }

    // Enable Bison debugging if necessary (set yydebug=1)
    extern int yydebug;
    yydebug = 1; // Set to 0 to disable debugging

    // Call the parser
    int parseResult = yyparse();
    if (parseResult == 0) {
        std::cout << "Parsing completed successfully!\n";
    } else {
        std::cerr << "Error occurred during parsing. Check the input file and error messages.\n";
    }

    // Close the input file
    if (fclose(yyin) != 0) {
        std::cerr << "Warning: Failed to close file " << argv[1] << std::endl;
    }

    return parseResult;
}
