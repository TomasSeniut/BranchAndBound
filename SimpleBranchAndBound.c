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

    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull() {

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

node peek() {
    return stack[top];
}

node pop() {
    node data;

    if(!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

void push(node data) {

    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

double SimpleBranchAndBound(double bestKnownSolution, int n, double distanceMatrix[][n], int solution[]) {

    int startCity = 0;
    double bestSolutionEstimate = bestKnownSolution;
    node problemSolution;

    node initialProblem;
    initialProblem.currentPathLength = 0;
    initialProblem.currentCity = startCity;
    InitializeArray(n, initialProblem.citiesVisited);

    initialProblem.citiesVisited[initialProblem.currentCity] = 1 + startCity;

    push(initialProblem);

    int h = 0;
    while (!isEmpty())
    {
        if (++h % 10000000 == 0 ) {
            printf("%e\n", (double)h);
        }

        node problem = pop();

        for (int i = 0; i < N; ++i) {
            int allCitiesVisited = IsAllCitiesVisited(n, problem.citiesVisited);

            if (problem.citiesVisited[i] && !allCitiesVisited) {
                continue;
            }

            double pathEstimate = problem.currentPathLength + distanceMatrix[i][startCity];
            if (bestSolutionEstimate < pathEstimate) {
                continue;
            }

            if (allCitiesVisited) {
                if (bestSolutionEstimate > pathEstimate) {
                    printf("\n Better solution found: %f\n", pathEstimate);
                    bestSolutionEstimate = pathEstimate;
                    problemSolution = problem;
                }
            } else {
                node subproblem;
                subproblem.currentCity = i;
                subproblem.currentPathLength =
                        problem.currentPathLength + distanceMatrix[problem.currentCity][subproblem.currentCity];
                CopyArray(n, problem.citiesVisited, subproblem.citiesVisited);
                subproblem.citiesVisited[subproblem.currentCity] = 1 + subproblem.currentCity;

                push(subproblem);
            }
        }
    }

    CopyArray(n, problemSolution.citiesVisited, solution);
    return problemSolution.currentPathLength + distanceMatrix[problemSolution.currentCity][startCity];
}