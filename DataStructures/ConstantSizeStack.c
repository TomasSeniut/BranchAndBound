//
// Created by Tomas on 2017.10.01.
//

#include <stdio.h>
#include "definitions.h"

#define STATIC_STACK_MAXSIZE 1000

constant_stack_node stack[STATIC_STACK_MAXSIZE];
int top = -1;

int constant_stack_isEmpty() {

    if (top == -1)
        return 1;
    else
        return 0;
}

int constant_stack_isFull() {

    if (top == STATIC_STACK_MAXSIZE)
        return 1;
    else
        return 0;
}

constant_stack_node constant_stack_pop() {
    constant_stack_node data;

    if (!constant_stack_isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

void constant_stack_push(constant_stack_node data) {

    if (!constant_stack_isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}