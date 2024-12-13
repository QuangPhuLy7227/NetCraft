#include <cstdio>    // For FILE and fopen
#include <iostream>  // For input/output
#include <cerrno>    // For errno
#include <cstring>   // For strerror

// Declare external lexer and parser functions
extern int yyparse();
extern FILE* yyin;

// Main entry point
int main(int argc, char* argv[]) {
    // Determine input source
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.netcraft>\n"
                  << "Alternatively, provide input through standard input.\n";
        yyin = stdin;
    } else {
        // Open the input file
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            std::cerr << "Error: Cannot open file " << argv[1] 
                      << " (" << strerror(errno) << ")" << std::endl;
            return 1;
        }
    }

    // Display processing information
    std::cout << "Starting parse for " << (argc > 1 ? argv[1] : "standard input") << std::endl;

    // Enable Bison debugging
    extern int yydebug;
    yydebug = 0; // Set to 0 to disable debugging

    // Call the parser
    int parseResult = yyparse();
    if (parseResult == 0) {
        std::cout << "Parsing completed successfully!\n";
    } else {
        std::cerr << "Error occurred during parsing. Check the input file and error messages.\n";
    }

    // Close the input file if not standard input
    if (yyin != stdin && fclose(yyin) != 0) {
        std::cerr << "Warning: Failed to close file " << argv[1] << std::endl;
    }

    return parseResult;
}
