#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "memorysafety.h"

typedef double linkedlist_data;

typedef struct _linkedlist_node 
{
    linkedlist_data data;
    void* next_node;
} linkedlist_node;

typedef struct _linkedlist_meta_node
{
    unsigned long int element_count;
    linkedlist_node* last_node;
    linkedlist_node* first_node;
    int node_size;
} linkedlist_meta_node;

typedef linkedlist_meta_node linkedlist;

linkedlist* create_linked_list();
unsigned long int add_to_linked_list(const linkedlist_data value, linkedlist* list);
void remove_from_linked_list(const unsigned long int element, linkedlist* list);
void delete_linked_list(linkedlist* list);
int get_element_at(const unsigned long int element, const linkedlist* list);
bool linked_list_contains(const linkedlist_data value, const linkedlist* list);
unsigned long int where_in_linked_list(const linkedlist_data value, const linkedlist* list);

//set unsorted
//find in list

#endif