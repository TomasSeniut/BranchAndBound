//
// Created by Tomas on 2017.10.01.
//

#ifndef CREATORTEST_CONSTANTS_H
#define CREATORTEST_CONSTANTS_H

#endif //CREATORTEST_CONSTANTS_H

#define N 16
#define DATA_FILE_NAME "gd16"

void InitializeArray(int n, int array[]);
int IsAllCitiesVisited(int n, int cityArray[]);
void CopyArray(int n, int from[], int to[]);
void InvertCopyArray(int n, int from[], int to[]);

double SimpleBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]);

