#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    srand(time(NULL));
        
    int rand_age = rand() % 100;
        
    int len = (rand() % 95) + 1;
    char rand_name[len];
    populate_random_arr(rand_name, len);
    
    struct cat test;
    test.age = rand_age;
    strcpy(test.name, rand_name);
    test.next = 0;
    
    struct cat *cat_chain = &test;
    
    int i;
    int len_chain = (rand() % 20) + 1;
    for (i = 0; i < len_chain; i++) {
        int name_len = (rand() % 95) + 1;
        char name[name_len];
        populate_random_arr(name, name_len);
        
        int age = rand() % 100;
        
        cat_chain = insert_front(cat_chain, name, age);
    }

    print_list(cat_chain);

    free_list(cat_chain);
}
