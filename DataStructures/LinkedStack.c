//
// Created by Tomas on 2017.10.19.
//
#include <malloc.h>
#include <stdio.h>
#include "definitions.h"

#define LINKED_NODE_SIZE 200

struct linked_node
{
    linked_stack_data data[LINKED_NODE_SIZE];
    int index;
    struct linked_node *next;
};

struct linked_node* linked_stack_init() {
    struct linked_node* head = (struct linked_node*)malloc(sizeof(struct linked_node));
    if(head == NULL)
    {
        printf("Could not allocate more memory");
        exit(0);
    }

    head->index = -1;
    head->next = NULL;
    return head;
}

struct linked_node* linked_stack_push(struct linked_node *head, linked_stack_data element) {
    if (head->index == LINKED_NODE_SIZE - 1) {
        struct linked_node* tmp = linked_stack_init();

        tmp->next = head;
        tmp->index++;
        tmp->data[tmp->index] = element;
        return tmp;
    }

    head->index++;
    head->data[head->index] = element;
    return head;}

struct linked_node* linked_stack_pop(struct linked_node *head, linked_stack_data *element){
    if (head->index == -1) {
        struct linked_node* tmp = head;
        head = head->next;
        free(tmp);
    }

    *element = head->data[head->index];
    head->index--;

    return head;
}

int linked_stack_isempty(struct linked_node *head) {
    if (head->index == -1)
        return 1;
    else
        return 0;
}