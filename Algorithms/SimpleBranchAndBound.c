//
// Created by Tomas on 2017.09.27.
//

#include <float.h>
#include <stdio.h>
#include "../DataStructures/definitions.h"
#include "../utils.h"

double SimpleBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]) {
    InitializeArray(n, solution);
    double bestSolutionEstimate = bound ? bound : DBL_MAX;

    constant_stack_node initialProblem;
    initialProblem.currentPathLength = 0;
    initialProblem.stepsTaken = 0;
    initialProblem.currentCity = startCity;
    InitializeArray(n, initialProblem.citiesVisited);

    initialProblem.citiesVisited[initialProblem.currentCity] = initialProblem.stepsTaken + 1;

    constant_stack_push(initialProblem);

    int count1 = 0, count2 = 0;
    while (!constant_stack_isEmpty()) {
        if (++count1 % 10000000 == 0) {
            count1 = 0;
            printf("Hit %5de+007 nodes\n", ++count2);
        }

        constant_stack_node problem = constant_stack_pop();

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

            constant_stack_node subproblem;
            subproblem.currentCity = i;
            subproblem.stepsTaken = problem.stepsTaken + 1;
            subproblem.currentPathLength =
                    problem.currentPathLength + distanceMatrix[problem.currentCity][subproblem.currentCity];
            CopyArray(n, problem.citiesVisited, subproblem.citiesVisited);
            subproblem.citiesVisited[subproblem.currentCity] = problem.stepsTaken + 1;

            constant_stack_push(subproblem);
        }
    }

    printf("Nodes checked: %d%d\n", count2, count1);

    return bestSolutionEstimate;
}