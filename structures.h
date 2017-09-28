//
// Created by Tomas on 2017.09.24.
//

#ifndef CREATORTEST_STRUCTURES_H
#define CREATORTEST_STRUCTURES_H

#endif //CREATORTEST_STRUCTURES_H

#define N 38

void InitializeArray(int n, int array[]);
int IsAllCitiesVisited(int n, int cityArray[]);
void CopyArray(int n, int from[], int to[]);

double SimpleBranchAndBound(int n, double distanceMatrix[][n], int solution[]);

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    int citiesVisited[N];
    double currentPathLength;
    int currentCity;
} node;

