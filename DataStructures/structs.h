//
// Created by Tomas on 2017.10.10.
//

#ifndef CREATORTEST_STRUCKS_H
#define CREATORTEST_STRUCKS_H

#include "../constants.h"
#include "definitions.h"


typedef struct {
    float x;
    float y;
} point;

typedef struct {
    int citiesVisited[N];
    double currentPathLength;
    int currentCity;
    int stepsTaken;
} simpleStackData;

typedef simpleStackData dynamic_stack_data;
typedef simpleStackData constant_stack_node;
typedef simpleStackData linked_stack_data;

#endif //CREATORTEST_STRUCKS_H
