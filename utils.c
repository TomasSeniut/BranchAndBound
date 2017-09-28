//
// Created by Tomas on 2017.09.24.
//

#include <stdio.h>
#include <math.h>
#include "structures.h"

void CopyArray(int n, int from[], int to[]) {
    for (int i = 0; i < n; ++i) {
        to[i] = from[i];
    }
}

void InitializeArray(int n, int array[]) {
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
}

int IsAllCitiesVisited(int n, int cityArray[]) {
    for (int i = 0; i < n; ++i) {
        if (!cityArray[i]) {
            return 0;
        }
    }

    return 1;
}

double calculate_distance(point point1, point point2) {
    return sqrt(pow(point1.y - point2.y, 2) + pow(point1.x - point2.x, 2));
}

void LoadFileToPointArray(char *fileName, point *coordinate) {
    FILE *fp;

    fp = fopen(fileName, "r");

    int i = 0;
    while (!feof (fp)) {
        fscanf(fp, "%f %f", &(coordinate[i].x), &(coordinate[i].y));
        i++;
    }

    fclose(fp);
}

void PopulateDistanceMatrix(point *array, int n, double distanceMatrix[][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double temp = calculate_distance(array[i], array[j]);
            distanceMatrix[i][j] = temp;
        }
    }
}

void PrintResult(double totalPath, int n, int solution[]) {
    printf("Length of the path found: %10.4f\n", totalPath);
    printf("Cities visited in this order:\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", solution[i]);
    }
}

void WriteResultToPythonFile(char *fileName, int n, int solution[], char *dataFileName) {
    FILE* resultsFile = fopen(fileName, "w");

    fprintf(resultsFile, "solution = [ ");
    for (int i = 0; i < n - 1; ++i) {
        fprintf(resultsFile, "%d, ", solution[i]);
    }
    fprintf(resultsFile, "%d ]\n", solution[n-1]);

    fprintf(resultsFile, "dataFileName = \"%s\"", dataFileName);
}

void PrintPointArray(point *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%4d %10.4f %10.4f\n", i, array[i].x, array[i].y);
    }
}

void PrintDistanceMatrix(int n, double distanceMatrix[][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%10.4f ", distanceMatrix[i][j]);
        }
        printf("\n");
    }
}

void PrintDistanceMatrixToFile(char *fileName, int n, double distanceMatrix[][n]) {
    FILE* distance_matrix = fopen(fileName, "w");

    for(int i = 0; i < n; ++i) {
        for (int k = 0; k < i; ++k) {
            fprintf(distance_matrix, "            ");
        }

        for (int j = i; j < n; ++j) {
            fprintf(distance_matrix, " %10.4f ", distanceMatrix[i][j]);
        }

        fprintf(distance_matrix, "\n");
    }

    fclose(distance_matrix);
}