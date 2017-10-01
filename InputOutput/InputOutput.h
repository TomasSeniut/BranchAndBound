//
// Created by Tomas on 2017.09.30.
//

#include "../DataStructures/structures.h"

#ifndef CREATORTEST_INPUTOUTPUT_H
#define CREATORTEST_INPUTOUTPUT_H

#endif //CREATORTEST_INPUTOUTPUT_H

void PrintPointArray(point *array, int n);
void PrintDistanceMatrix(int n, double distanceMatrix[][n]);
void PrintDistanceMatrixToFile(char *fileName, int n, double distanceMatrix[][n]);
void PrintResult(double totalPath, int n, int solution[]);
void WriteResultToPythonFile(char *fileName, int n, int solution[], char *dataFileName);
void LoadFileToPointArray(char *fileName, point *array);
void LoadFileToDistanceMatrix(char *fileName, int n, double distanceMatrix[][n]);