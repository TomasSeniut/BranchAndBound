
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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

    clock_t start = clock();
    double path = ParallelBranchAndBound(0, pathEstimate, realN, distanceArray, solution);
    clock_t duration = clock() - start;

    printf("It took %ld clicks (%f seconds) for parallel algorithm.\n", duration, ((float) duration) / CLOCKS_PER_SEC);

    PrintResult(path, realN, solution);
    WriteResultToPythonFile("../Plotting/solution.py", realN, solution, dataFileName);
    return 0;
}