//
// Created by Tomas on 2017.10.10.
//

#include <float.h>
#include <malloc.h>
#include <stdio.h>
#include "../DataStructures/definitions.h"
#include "../utils.h"

double SimpleBranchAndBoundDynamicStack(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]) {
    InitializeArray(n, solution);
    double bestSolutionEstimate = bound ? bound : DBL_MAX;

    struct node *stack = NULL;

    dynamic_stack_data initialProblem;
    initialProblem.currentCity = startCity;
    initialProblem.currentPathLength = 0;
    initialProblem.stepsTaken = 0;
    InitializeArray(n, initialProblem.citiesVisited);
    initialProblem.citiesVisited[initialProblem.currentCity] = initialProblem.stepsTaken + 1;

    stack = dynamic_stack_push(stack, initialProblem);

    int count1 = 0, count2 = 0;
    while (!dynamic_stack_isempty(stack)) {
        if (++count1 % 10000000 == 0) {
            count1 = 0;
            printf("Hit %5de+007 nodes\n", ++count2);
        }

        dynamic_stack_data problem;
        stack = dynamic_stack_pop(stack, &problem);

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

            dynamic_stack_data subproblem;
            subproblem.currentCity = i;
            subproblem.stepsTaken = problem.stepsTaken + 1;
            subproblem.currentPathLength =
                    problem.currentPathLength + distanceMatrix[problem.currentCity][subproblem.currentCity];
            CopyArray(n, problem.citiesVisited, subproblem.citiesVisited);
            subproblem.citiesVisited[subproblem.currentCity] = problem.stepsTaken + 1;

            stack = dynamic_stack_push(stack, subproblem);
        }
    }

    printf("Nodes checked: %d%d\n", count2, count1);

    return bestSolutionEstimate;
}