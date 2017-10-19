//
// Created by Tomas on 2017.09.24.
//

#include <math.h>
#include "DataStructures/definitions.h"
#include "utils.h"

double calculate_distance(point point1, point point2) {
    return sqrt(pow(point1.y - point2.y, 2) + pow(point1.x - point2.x, 2));
}

void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double temp = calculate_distance(array[i], array[j]);
            distanceMatrix[i][j] = temp;
        }
    }
}

void CopyArray(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) {
        to[i] = from[i];
    }
}

void InvertCopyArray(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) {
        to[from[i]] = i;
    }
}

void InitializeArray(int n, int array[]) {
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
}

int IsAllCitiesVisited(int n, int cityArray[]) {
    for (int i = 0; i < n; ++i) {
        if (!cityArray[i]) {
            return 0;
        }
    }

    return 1;
}