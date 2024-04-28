cmake_minimum_required(VERSION 3.20)

project (EvalFromScratch
    VERSION 0.1
    DESCRIPTION "A simple math expression evaluator written in C++"
    LANGUAGES CXX
)

# Use cpp 17
set(CMAKE_CXX_STANDARD 17)

# Add the Tokenizer library
add_library(
    Tokenizer
    STATIC
    lib/Tokenizer/Tokenizer.h
    lib/Tokenizer/Tokenizer.cpp
)



# Include the lib dir
include_directories(lib)

add_executable(${PROJECT_NAME} src/main.cpp)

# Link the libs
target_link_libraries(${PROJECT_NAME} Tokenizer)

