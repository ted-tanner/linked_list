#include "linkedlist.h"

linkedlist* create_linked_list() {
    linkedlist_meta_node* meta_node = malloc(sizeof(linkedlist_meta_node));
    #ifdef MAX_PERFORMANCE
        check_alloc_fail(meta_node);
    #else
        check_alloc_fail(meta_node, __func__);
    #endif

    linkedlist_node* first_node = calloc(1, sizeof(linkedlist_node));
    #ifdef MAX_PERFORMANCE
        check_alloc_fail(first_node);
    #else
        check_alloc_fail(first_node, __func__);
    #endif

    meta_node->element_count = 0;
    meta_node->first_node = first_node;
    meta_node->last_node = first_node;
    meta_node->node_size = sizeof(void*) + sizeof(linkedlist_data);

    return meta_node;
}

unsigned long int add_to_linked_list(const linkedlist_data value, linkedlist* list) {
    if (list->element_count == 0) {
        list->first_node->data = value;
        ++(list->element_count);
        return 0;
    }
    
    linkedlist_node* new_node = malloc(sizeof(linkedlist_node));
    #ifdef MAX_PERFORMANCE
        check_alloc_fail(new_node);
    #else
        check_alloc_fail(new_node, __func__);
    #endif

    new_node->data = value;
    list->last_node->next_node = new_node;
    list->last_node = new_node;
    ++(list->element_count);

    return list->element_count - 1;
}

void remove_from_linked_list(const unsigned long int element, linkedlist* list) {
    linkedlist_node* current_node = list->first_node;

    if (element == 0) {
        list->first_node = current_node->next_node;
        --(list->element_count);
        free(current_node);

        return;
    }

    for (unsigned long int i = 0; i < element - 1; current_node = current_node->next_node, ++i);
    linkedlist_node* previous_node = current_node;
    current_node = current_node->next_node;
    
    if (current_node != list->last_node)
        previous_node->next_node = current_node->next_node;
    --(list->element_count);
    free(current_node);

    return; 
}

void delete_linked_list(linkedlist* list) {
    linkedlist_node* previous_node = list->first_node;
    linkedlist_node* current_node = previous_node->next_node;

    for (unsigned long int i = 0; i < list->element_count - 2; current_node = current_node->next_node, ++i) {
        free(previous_node);
        previous_node = current_node;
    }
    free(previous_node);
    free(current_node);
    free(list);

    return;
}

int get_element_at(const unsigned long int element, const linkedlist* list) {
    if (element >= list->element_count) {
        fprintf(stderr, "ERROR in function '%s': Element does not exist\n", __func__);
        return 0;
    }

    linkedlist_node* current_node = list->first_node;
    for (unsigned long int i = 0; i < element; current_node = current_node->next_node, ++i);

    return current_node->data;
}

bool linked_list_contains(const linkedlist_data value, const linkedlist* list) {
    bool value_in_linked_list = false;

    linkedlist_node* current_node = list->first_node;
    for(unsigned long int i = 0; i < list->element_count; current_node = current_node->next_node, ++i) {
        if (current_node->data == value)
            return true;
    }

    return false;
}

unsigned long int where_in_linked_list(const linkedlist_data value, const linkedlist* list) {
    linkedlist_node* current_node = list->first_node;
    for(unsigned long int i = 0; i < list->element_count; current_node = current_node->next_node, ++i) {
        if (current_node->data == value)
            return i;
    }

    return -1;
}

// void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
//     int i, last;
//     void swap(void *v[], int, int);

//     if (left >= right)
//         return;
//     swap(v, left, (left + right)/2);
//     last = left;
//     for (i = left+1; i <= right; ++i)
//         if ((*comp)(v[i], v[left]) < 0) /* Here's the function call */
//             swap(v, ++last, i);
//     swap(v, left, last);
//     qsort(v, left, last-1, comp);
//     qsort(v, last+1, right, comp);
// }