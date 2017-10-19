//
// Created by Tomas on 2017.10.01.
//

#ifndef CREATORTEST_STRUCTURE_H
#define CREATORTEST_STRUCTURE_H

#include "structs.h"

int constant_stack_isEmpty();
int constant_stack_isFull();
constant_stack_node constant_stack_pop();
void constant_stack_push(constant_stack_node n);

struct node* dynamic_stack_push(struct node *head, dynamic_stack_data data);
struct node* dynamic_stack_pop(struct node *head, dynamic_stack_data *element);
int dynamic_stack_isempty(struct node* head);

struct linked_node* linked_stack_push(struct linked_node* head, linked_stack_data data);
struct linked_node* linked_stack_pop(struct linked_node* head, linked_stack_data* element);
int linked_stack_isempty(struct linked_node* head);
struct linked_node* linked_stack_init();


#endif //CREATORTEST_STRUCTURE_H




