//
// Created by Tomas on 2017.10.15.
//

#ifndef CREATORTEST_UTILS_H
#define CREATORTEST_UTILS_H

#include "DataStructures/definitions.h"

void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]);

void CopyArray(int n, int from[], int to[]);
void CopyDoubleArray(int n, double from[], double to[]);
void InvertCopyArray(int n, int from[], int to[]);
void InitializeArray(int n, int array[]);
int IsAllCitiesVisited(int n, int cityArray[]);

#endif //CREATORTEST_UTILS_H
