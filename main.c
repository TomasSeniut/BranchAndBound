
#include "structures.h"

void PrintPointArray(point *array, int n);
void PrintDistanceMatrix(int n, double distanceMatrix[][n]);
void PrintDistanceMatrixToFile(char *fileName, int n, double distanceMatrix[][n]);
void PrintResult(double totalPath, int n, int solution[]);
void WriteResultToPythonFile(char *fileName, int n, int solution[], char *dataFileName);

void LoadFileToPointArray(char *fileName, point *array);
void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]);

double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]);
double BestOfNNearestNeighbourMethod(int T, int n, double distanceMatrix[][n], int solution[]);


int main() {

    int n = N;

    char dataFileName[20] = "dj38.tsp";

    point coordinates[N];
    LoadFileToPointArray(dataFileName, coordinates);

    double distanceArray[N][N] = { 0 };
    PopulateDistanceMatrix(coordinates, n, distanceArray);

    int solution[N] = { 0 };
    //double path = BestOfNNearestNeighbourMethod(5, N, distanceArray, solution);
    double path = SimpleBranchAndBound(n, distanceArray, solution);

    PrintResult(path, N, solution);
    WriteResultToPythonFile("../Plotting/solution.py", N, solution, dataFileName);

    return 0;
}