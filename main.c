
#include <time.h>
#include <stdio.h>
#include "InputOutput/InputOutput.h"
#include "DataStructures/structures.h"

void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]);

double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]);
double BestOfNNearestNeighbourMethod(int T, int n, double distanceMatrix[][n], int solution[]);

int main() {
    clock_t start, duration;

    char dataFileName[30] = "../tsp_data/" DATA_FILE_NAME ".tsp";

    point coordinates[N];
    LoadFileToPointArray(dataFileName, coordinates);

    double distanceArray[N][N] = {0};
    PopulateDistanceMatrix(coordinates, N, distanceArray);

    int solution[N] = {0};
    double pathEstimate = BestOfNNearestNeighbourMethod(5, N, distanceArray, solution);
    printf("Best estimate from heuristics: %f\n", pathEstimate);

    start = clock();
    double path = SimpleBranchAndBound(0, pathEstimate, N, distanceArray, solution);
    duration = clock() - start;

    PrintResult(path, N, solution);
    WriteResultToPythonFile("../Plotting/solution.py", N, solution, dataFileName);

    printf("It took %d clicks (%f seconds).\n", duration, ((float) duration) / CLOCKS_PER_SEC);

    return 0;
}