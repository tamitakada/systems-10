#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cat {
    char name[100];
    int age;
    struct cat *next;
};

void print_list(struct cat *c);
struct cat * insert_front(struct cat *next, char *name, int age);
struct cat * free_list(struct cat *c);

int main() {
    struct cat test;
    test.age = 10;
    strcpy(test.name, "Cat 1");
    test.next = 0;

    struct cat *cat_chain = &test;
    
    cat_chain = insert_front(cat_chain, "Cat 0", 2);
    cat_chain = insert_front(cat_chain, "Cat -1", 5);

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
    while (c->next) {
        free(c);
        c = (c->next);
    }
    return c;
}
