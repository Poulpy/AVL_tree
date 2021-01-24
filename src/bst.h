#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

struct bst {
    struct bst *left;
    struct bst *right;
    double key;
};

struct bst *new_bst(double key);
void free_bst(struct bst *b);
void print_bst(struct bst *b);
void append_bst(struct bst *b, double to_append);
bool contains_bst(struct bst *b, double to_find);
unsigned int height(struct bst *b);

// struct bst *new_bst_from_adjacency_list(struct doublevv **adjacency_list);

#endif
