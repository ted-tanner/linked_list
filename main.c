#define MAX_PERFORMANCE

#include "linkedlist.c"
#include <stdio.h>

int main(int argc, char* argv[]) {
    linkedlist* my_list = create_linked_list();
    int list_value = 0.01;

    for (unsigned long int i = 1; i <= 2000000; ++i) {
        if (i % 2 == 0)
            add_to_linked_list(i, my_list);
    }

    printf("Bytes required by each node: %ld\n", sizeof(my_list->node_size));
    printf("Memory consumed: %f MB\n", ((double) sizeof(linkedlist_meta_node) + ((double) sizeof(linkedlist_node) * 1000000.0)) / 1000000.0);

    // int myint = 200000;
    // printf("List contains %d: %s\n", myint, linked_list_contains(myint, my_list) ? "true" : "false");
    // printf("%d was found at: %lu\n", myint, where_in_linked_list(myint, my_list));
    // printf("Element count: %lu", my_list->element_count);

    // for (unsigned long int i = 0; i < my_list->element_count; ++i)
    //     get_element_at(i, my_list);

    // for (unsigned long int i = 0; i < 50000; ++i)
    //     remove_from_linked_list(0, my_list);

    delete_linked_list(my_list);

    return 0;
}