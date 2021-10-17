#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cat {
    char name[100];
    int age;
    struct cat *next;
};

void print_list(struct cat *c);
struct cat * insert_front(struct cat *next, char *name, int age);
struct cat * free_list(struct cat *c);

void populate_random_arr(char *arr, int len);

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

void print_list(struct cat *c) {
    printf("[  ");
    while (c) {
        printf("Cat {Name: %s, Age: %d} ", c->name, c->age);
        c = (c->next);
    }
    printf("]\n");
}

struct cat * insert_front(struct cat *next, char *name, int age) {
    struct cat *new_cat = malloc(sizeof(struct cat));
    strcpy(new_cat->name, name);
    new_cat->age = age;
    new_cat->next = next;
    return new_cat;
}

struct cat * free_list(struct cat *c) {
    struct cat *next = (c->next);
    free(c);
    c = next;
    while (c->next) {
        next = c->next;
        free(c);
        c = next;
    }
    return c;
}

void populate_random_arr(char *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = (rand() % 24) + 65;
    }
    
    arr[len - 1] = '\0';
}
