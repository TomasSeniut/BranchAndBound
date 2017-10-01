//
// Created by Tomas on 2017.10.01.
//

#include "../constants.h"

#ifndef CREATORTEST_STRUCTURE_H
#define CREATORTEST_STRUCTURE_H

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    int citiesVisited[N];
    double currentPathLength;
    int currentCity;
    int stepsTaken;
} node;

typedef node stackData;

int isEmpty();
int isFull();
stackData pop();
void push(stackData n);

#endif //CREATORTEST_STRUCTURE_H




