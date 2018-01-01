
#include <time.h>
#include <stdio.h>
#include "InputOutput/InputOutput.h"
#include "Algorithms/algorithms.h"
#include "utils.h"

int main() {
    char dataFileName[50] = "../tsp_data/" DATA_FILE_NAME ".tsp";

    point coordinates[N];
    LoadFileToPointArray(dataFileName, coordinates);

    double distanceArray[N][N] = {0};
    PopulateDistanceMatrix(coordinates, N, distanceArray);

    int solution[N] = {0};
    double pathEstimate = BestOfNNearestNeighbourMethod(5, N, distanceArray, solution);
    printf("Best estimate from heuristics: %f\n", pathEstimate);

    clock_t start1 = clock();
    double path0 = SimpleBranchAndBoundLinkedStack(0, pathEstimate, N, distanceArray, solution);
    clock_t duration1 = clock() - start1;

    clock_t start = clock();
    double path = ParallelBranchAndBound(0, pathEstimate, N, distanceArray, solution);
    clock_t duration = clock() - start;

    printf("It took %ld clicks (%f seconds) for sequential algorithm.\n", duration1, ((float) duration1) / CLOCKS_PER_SEC);
    printf("It took %ld clicks (%f seconds) for parallel algorithm.\n", duration, ((float) duration) / CLOCKS_PER_SEC);

    PrintResult(path, N, solution);
    WriteResultToPythonFile("../Plotting/solution.py", N, solution, dataFileName);
    return 0;
}