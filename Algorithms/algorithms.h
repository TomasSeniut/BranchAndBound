//
// Created by Tomas on 2017.10.10.
//

#ifndef CREATORTEST_ALGORITHMS_H
#define CREATORTEST_ALGORITHMS_H

double NearestNeighbourMethod(int startCity, int n, double distanceMatrix[][n], int solution[]);
double BestOfNNearestNeighbourMethod(int T, int n, double distanceMatrix[][n], int solution[]);
double SimpleBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]);
double SimpleBranchAndBoundDynamicStack(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]);
double SimpleBranchAndBoundLinkedStack(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]);
double ParallelBranchAndBound(int startCity, double bound, int n, double distanceMatrix[][n], int solution[]);

#endif //CREATORTEST_ALGORITHMS_H
