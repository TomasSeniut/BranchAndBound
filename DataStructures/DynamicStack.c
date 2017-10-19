//
// Created by Tomas on 2017.10.10.
//

#include <stdio.h>
#include <malloc.h>
#include "definitions.h"

struct node
{
    dynamic_stack_data data;
    struct node* next;
};

struct node* dynamic_stack_push(struct node *head, dynamic_stack_data data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("Could not allocate more memory");
        exit(0);
    }

    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

struct node* dynamic_stack_pop(struct node *head, dynamic_stack_data *element)
{
    struct node* tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}

int dynamic_stack_isempty(struct node* head)
{
    return head == NULL ? 1 : 0;
}