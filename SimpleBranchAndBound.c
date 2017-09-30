//
// Created by Tomas on 2017.09.27.
//

#include <float.h>
#include <stdio.h>
#include "structures.h"

#define MAXSIZE 1000

node stack[MAXSIZE];
int top = -1;

int isEmpty() {

    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

node peek() {
    return stack[top];
}

node pop() {
    node data;

    if (!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

void push(node data) {

    if (!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

double
SimpleBranchAndBound(int startCity, double bestKnownSolution, int n, double distanceMatrix[][n], int solution[]) {

    double bestSolutionEstimate;
    if (bestKnownSolution == 0) {
        bestSolutionEstimate = DBL_MAX;
    } else {
        bestSolutionEstimate = bestKnownSolution;
    }

    node initialProblem;
    initialProblem.currentPathLength = 0;
    initialProblem.stepsTaken = 1;
    initialProblem.currentCity = startCity;
    InitializeArray(n, initialProblem.citiesVisited);

    initialProblem.citiesVisited[initialProblem.currentCity] = initialProblem.stepsTaken;

    push(initialProblem);

    int h = 0;
    while (!isEmpty()) {
        if (++h % 10000000 == 0) {
            printf("Hit %e nodes\n", (double) h);
        }

        node problem = pop();

        if (IsAllCitiesVisited(n, problem.citiesVisited)) {
            double pathLength = problem.currentPathLength + distanceMatrix[problem.currentCity][startCity];

            if (bestSolutionEstimate > pathLength) {
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

    printf("Nodes checked: %d\n", h);

    return bestSolutionEstimate;
}