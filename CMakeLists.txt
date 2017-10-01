cmake_minimum_required(VERSION 3.8)
project(CreatorTest)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c utils.c heuristics.c SimpleBranchAndBound.c InputOutput/InputOutput.h InputOutput/InputOutput.c DataStructures/structures.h DataStructures/ConstantSizeStack.c constants.h)
add_executable(CreatorTest ${SOURCE_FILES})