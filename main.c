#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

int main() {
    srand(time(NULL));
    
    int rand_age = rand() % 100;

    int len = (rand() % 95) + 1;
    
    struct cat *cat_chain = 0;
    
    int i;
    int len_chain = (rand() % 20) + 1;
    
    int rand_cat = rand() % (len_chain - 1);
    char chosen_name[100];
    int chosen_age;
    
    for (i = 0; i < len_chain; i++) {
        int name_len = (rand() % 20) + 1;
        char name[name_len];
        populate_random_arr(name, name_len);
        
        int age = rand() % 100;
        
        cat_chain = insert_front(cat_chain, name, age);
        
        if (i == rand_cat) {
            strcpy(chosen_name, name);
            chosen_age = age;
        }
    }

    print_list(cat_chain);
    
    printf("\nRemoving Cat with name: %s and age: %d\n\n", chosen_name, chosen_age);
    cat_chain = remove_node(cat_chain, chosen_name, chosen_age);
    
    print_list(cat_chain);
    
    printf("\nFreeing list\n");
    cat_chain = free_list(cat_chain);
    print_list(cat_chain);
}
