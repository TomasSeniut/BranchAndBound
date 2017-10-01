//
// Created by Tomas on 2017.09.24.
//

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int VisitNearestNeighbour(int currentCity, int n, double distanceMatrix[][n], int visitedCities[], double *distance);
double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]);

double BestOfNNearestNeighbourMethod(int times, int n, double distanceMatrix[][n], int solution[]) {
    double bestLength = DBL_MAX;
    int candidateSolution[n];

    for (int i = 0; i < times; ++i) {
        int startCity = rand() % n;
        InitializeArray(n, candidateSolution);
        double pathLength = NearestNeighbourMethod(startCity, n, distanceMatrix, candidateSolution);

        if (pathLength < bestLength) {
            bestLength = pathLength;
            CopyArray(n, candidateSolution, solution);
        }
    }

    return bestLength;
}

double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]) {
    int visitedCities[n];
    InitializeArray(n, visitedCities);
    visitedCities[startCity] = 1;

    int currentCity = startCity;
    double totalLength = 0;

    for (int i = 0; i < n; ++i) {
        double distanceToNextCity = 0;
        int nextCity = VisitNearestNeighbour(currentCity, n, distanceMatrix, visitedCities, &distanceToNextCity);

        if (nextCity == -2) {
            printf("Kazkas ne taip");
        }

        if (nextCity == -1) {
            distanceToNextCity = distanceMatrix[currentCity][startCity];
        }

        solution[i] = currentCity;
        currentCity = nextCity;
        totalLength += distanceToNextCity;
    }

    return totalLength;
}

int VisitNearestNeighbour(int currentCity, int n, double distanceMatrix[][n], int visitedCities[], double *distance) {
    int nearestCity = -2;
    double smallestDistance = DBL_MAX;

    for (int i = 0; i < n; ++i) {
        if (visitedCities[i]) {
            continue;
        }

        double distanceBetweenCities = distanceMatrix[currentCity][i];
        if (smallestDistance > distanceBetweenCities) {
            smallestDistance = distanceBetweenCities;
            nearestCity = i;
        }
    }

    if (!IsAllCitiesVisited(n, visitedCities)) {
        *distance = smallestDistance;
        visitedCities[nearestCity] = 1;
    } else {
        nearestCity = -1;
    }

    return nearestCity;
}