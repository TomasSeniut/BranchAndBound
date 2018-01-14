//
// Created by Tomas on 2017.12.31.
//

#include <float.h>

double GetLowerBound(int n, double distanceMatrix[][n], int citiesVisited[], int cityToVisit) {
    double lowerBound = 0;

    for (int i = 0; i < n; ++i) {
        if (citiesVisited[i] || i == cityToVisit) {
            continue;
        }

        double firstNearestCity = DBL_MAX;
        double secondNearestCity = DBL_MAX;

        for (int j = 0; j < n; ++j) {
            if (citiesVisited[j] || j == cityToVisit || i == j) {
                continue;
            }

            double distance = distanceMatrix[i][j];

            if (distance < secondNearestCity) {
                if (distance < firstNearestCity) {
                    if (firstNearestCity < secondNearestCity) {
                        secondNearestCity = firstNearestCity;
                    }

                    firstNearestCity = distance;
                } else {
                    secondNearestCity = distance;
                }
            }
        }

        if (secondNearestCity == DBL_MAX) {
            return 0;
        }

        lowerBound += firstNearestCity + secondNearestCity;
    }

    return lowerBound / 2 ;
}