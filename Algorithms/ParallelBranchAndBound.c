//
// Created by Tomas on 2017.10.15.
//

#include <float.h>
#include <stdio.h>
#include <omp.h>
#include <malloc.h>
#include "../utils.h"
#include "../DataStructures/definitions.h"
#include "../DataStructures/structs.h"

double ParallelBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]) {
    InitializeArray(n, solution);
    double bestSolutionEstimate = bound ? bound : DBL_MAX;

    linked_stack_data initialProblem;
    initialProblem.currentCity = startCity;
    initialProblem.currentPathLength = 0;
    initialProblem.stepsTaken = 0;
    InitializeArray(n, initialProblem.citiesVisited);
    initialProblem.citiesVisited[initialProblem.currentCity] = initialProblem.stepsTaken + 1;

    #pragma omp parallel for
    for (int j = 0; j < n; ++j) {
        if (initialProblem.currentCity == j) {
            continue;
        }

        linked_stack_data startProblem;
        startProblem.currentCity = j;
        startProblem.stepsTaken = initialProblem.stepsTaken + 1;
        startProblem.currentPathLength =
                initialProblem.currentPathLength + distanceMatrix[initialProblem.currentCity][startProblem.currentCity];
        CopyArray(n, initialProblem.citiesVisited, startProblem.citiesVisited);
        startProblem.citiesVisited[startProblem.currentCity] = initialProblem.stepsTaken + 1;

        struct linked_node *stack = linked_stack_init();
        stack = linked_stack_push(stack, startProblem);

        unsigned long count = 0;
        while (!linked_stack_isempty(stack)) {
            if (++count % 10000000 == 0) {
                printf("Hit %3.0e nodes on thread %d\n", (float)count, omp_get_thread_num());
            }

            linked_stack_data problem;
            stack = linked_stack_pop(stack, &problem);

            if (IsAllCitiesVisited(n, problem.citiesVisited)) {
                double pathLength = problem.currentPathLength + distanceMatrix[problem.currentCity][startCity];

                #pragma omp critical
                {
                    if (bestSolutionEstimate >= pathLength) {
                        printf("Better solution found: %f\n", pathLength);
                        bestSolutionEstimate = pathLength;
                        InvertCopyArray(n, problem.citiesVisited, solution);
                    }
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

                linked_stack_data subproblem;
                subproblem.currentCity = i;
                subproblem.stepsTaken = problem.stepsTaken + 1;
                subproblem.currentPathLength =
                        problem.currentPathLength + distanceMatrix[problem.currentCity][subproblem.currentCity];
                CopyArray(n, problem.citiesVisited, subproblem.citiesVisited);
                subproblem.citiesVisited[subproblem.currentCity] = problem.stepsTaken + 1;

                stack = linked_stack_push(stack, subproblem);
            }
        }

        free(stack);
    }

    return bestSolutionEstimate;
}