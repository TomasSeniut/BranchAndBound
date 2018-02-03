
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "InputOutput/InputOutput.h"
#include "Algorithms/algorithms.h"
#include "utils.h"

int main(int argc, char *argv[]) {

    if (argc < 3 || argc > 3) {
        printf("Usage: BranchAndBound.exe filename problem_size");
        return 1;
    }

    char* dataFileName = argv[1];
    int realN = strtol(argv[2], NULL, 0);

    point coordinates[N];
    LoadFileToPointArray(dataFileName, coordinates);

    double distanceArray[N][N] = {0};
    PopulateDistanceMatrix(coordinates, realN, distanceArray);

    int solution[N] = {0};
    double pathEstimate = BestOfNNearestNeighbourMethod(5, realN, distanceArray, solution);
    printf("Best estimate from heuristics: %f\n", pathEstimate);

    double start = omp_get_wtime();
    double path = ParallelBranchAndBound(0, pathEstimate, realN, distanceArray, solution);
    double duration = omp_get_wtime() - start;

    printf("It took %f seconds for parallel algorithm.\n", duration);

    PrintResult(path, realN, solution);
    WriteResultToPythonFile("../Plotting/solution.py", realN, solution, dataFileName);
    return 0;
}