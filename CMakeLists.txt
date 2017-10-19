cmake_minimum_required(VERSION 3.8)
project(CreatorTest)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c utils.c Algorithms/heuristics.c Algorithms/SimpleBranchAndBound.c InputOutput/InputOutput.h InputOutput/InputOutput.c DataStructures/definitions.h DataStructures/ConstantSizeStack.c constants.h Algorithms/algorithms.h DataStructures/structs.h DataStructures/DynamicStack.c Algorithms/SimpleBranchandBound_wDynamicStack.c Algorithms/ParallelBranshAndBound.c utils.h DataStructures/LinkedStack.c Algorithms/SimpleBranchAndBound_wLinkedStack.c)
add_executable(CreatorTest ${SOURCE_FILES})