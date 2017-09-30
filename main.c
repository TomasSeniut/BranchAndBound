
#include "structures.h"

void PrintPointArray(point *array, int n);
void PrintDistanceMatrix(int n, double distanceMatrix[][n]);
void PrintDistanceMatrixToFile(char *fileName, int n, double distanceMatrix[][n]);
void PrintResult(double totalPath, int n, int solution[]);
void WriteResultToPythonFile(char *fileName, int n, int solution[], char *dataFileName);

void LoadFileToPointArray(char *fileName, point *array);
void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]);
void LoadFileToDistanceMatrix(char *fileName, int n, double distanceMatrix[][n]);

double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]);
double BestOfNNearestNeighbourMethod(int T, int n, double distanceMatrix[][n], int solution[]);

int main() {
    char dataFileName[30] = "../tsp_data/" DATA_FILE_NAME ".tsp";

    point coordinates[N];
    LoadFileToPointArray(dataFileName, coordinates);

    double distanceArray[N][N] = { 0 };
    PopulateDistanceMatrix(coordinates, N, distanceArray);

    int solution[N] = { 0 };
    //double pathEstimate = BestOfNNearestNeighbourMethod(5, N, distanceArray, solution);
    //printf("%f\n", pathEstimate);

    double path = SimpleBranchAndBound(0, 0, N, distanceArray, solution);

    PrintResult(path, N, solution);
    WriteResultToPythonFile("../Plotting/solution.py", N, solution, dataFileName);

    return 0;
}