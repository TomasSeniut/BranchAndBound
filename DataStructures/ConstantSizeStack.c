//
// Created by Tomas on 2017.10.01.
//

#include <stdio.h>
#include "structures.h"

#define MAXSIZE 1000

stackData stack[MAXSIZE];
int top = -1;

int isEmpty() {

    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

stackData pop() {
    stackData data;

    if (!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

void push(stackData data) {

    if (!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}