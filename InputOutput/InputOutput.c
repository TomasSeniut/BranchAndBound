//
// Created by Tomas on 2017.09.30.
//

#include <stdio.h>
#include "../DataStructures/definitions.h"

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

void LoadFileToDistanceMatrix(char *fileName, int n, double distanceMatrix[][n]) {
    FILE *fp;

    fp = fopen(fileName, "r");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(fp, "%lf", &distanceMatrix[i][j]);
        }
    }

    fclose(fp);
}

void PrintResult(double totalPath, int n, int solution[]) {
    printf("Length of the path found: %10.4f\n", totalPath);
    printf("Cities visited in this order:\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", solution[i]);
    }

    printf("\n");
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