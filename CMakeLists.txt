cmake_minimum_required(VERSION 3.8)
project(CreatorTest)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c structures.h utils.c heuristics.c SimpleBranchAndBound.c)
add_executable(CreatorTest ${SOURCE_FILES})