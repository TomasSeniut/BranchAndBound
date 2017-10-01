//
// Created by Tomas on 2017.09.27.
//

#include <float.h>
#include <stdio.h>
#include "DataStructures/structures.h"

double SimpleBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]) {
    InitializeArray(n, solution);
    double bestSolutionEstimate = bound ? bound : DBL_MAX;

    node initialProblem;
    initialProblem.currentPathLength = 0;
    initialProblem.stepsTaken = 1;
    initialProblem.currentCity = startCity;
    InitializeArray(n, initialProblem.citiesVisited);

    initialProblem.citiesVisited[initialProblem.currentCity] = initialProblem.stepsTaken;

    push(initialProblem);

    int count1 = 0, count2 = 0;
    while (!isEmpty()) {
        if (++count1 % 10000000 == 0) {
            count1 = 0;
            printf("Hit %5de+007 nodes\n", ++count2);
        }

        node problem = pop();

        if (IsAllCitiesVisited(n, problem.citiesVisited)) {
            double pathLength = problem.currentPathLength + distanceMatrix[problem.currentCity][startCity];

            if (bestSolutionEstimate >= pathLength) {
                printf("Better solution found: %f\n", pathLength);
                bestSolutionEstimate = pathLength;
                InvertCopyArray(n, problem.citiesVisited, solution);
            }

            continue;
        }

        for (int i = 0; i < N; ++i) {
            if (problem.citiesVisited[i]) {
                continue;
            }

            double pathEstimate = problem.currentPathLength + distanceMatrix[i][startCity];
            if (bestSolutionEstimate < pathEstimate) {
                continue;
            }

            node subproblem;
            subproblem.currentCity = i;
            subproblem.stepsTaken = problem.stepsTaken + 1;
            subproblem.currentPathLength =
                    problem.currentPathLength + distanceMatrix[problem.currentCity][subproblem.currentCity];
            CopyArray(n, problem.citiesVisited, subproblem.citiesVisited);
            subproblem.citiesVisited[subproblem.currentCity] = problem.stepsTaken;

            push(subproblem);
        }
    }

    printf("Nodes checked: %d%d\n", count2, count1);

    return bestSolutionEstimate;
}