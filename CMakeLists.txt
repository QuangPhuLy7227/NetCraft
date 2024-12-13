cmake_minimum_required(VERSION 3.10)
project(NetCraft)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Boost libraries
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/third_party/boost/libs)
set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib)
include_directories(${BOOST_INCLUDEDIR})
link_directories(${BOOST_LIBRARYDIR})

# Add Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Generate lexer and parser files
BISON_TARGET(Parser src/parser/netcraft.y ${CMAKE_CURRENT_BINARY_DIR}/netcraft.tab.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/netcraft.tab.h)
FLEX_TARGET(Lexer src/lexer/netcraft.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)      # Project include directory
include_directories(${CMAKE_BINARY_DIR})              # Include generated Bison headers

# Add source files for the executable
add_executable(NetCraft
    src/main.cpp
    src/networking/network.cpp
    src/networking/protocols.cpp
    src/networking/packet_crafter.cpp
    src/cli/cli.cpp
    src/parser/parser.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Lexer_OUTPUTS}
)

# Ensure linking with C++
set_target_properties(NetCraft PROPERTIES LINKER_LANGUAGE CXX)

# Find and link Boost libraries
find_package(Boost REQUIRED COMPONENTS system filesystem regex)
if(Boost_FOUND)
    target_include_directories(NetCraft PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(NetCraft PRIVATE ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost libraries not found.")
endif()

# Link system libraries
target_link_libraries(NetCraft PRIVATE pthread)

# Additional debug output (optional, helpful for diagnosing issues)
message(STATUS "Bison output files: ${BISON_Parser_OUTPUTS}")
message(STATUS "Flex output files: ${FLEX_Lexer_OUTPUTS}")
message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
