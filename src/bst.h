#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "doublev.h"

/*
 * bst
 *
 * Binary Search Tree
 */
struct bst {
    struct bst *left;
    struct bst *right;
    double key;
};

bool contains_bst(struct bst *b, double to_find);
int height(struct bst *b);
struct bst *new_bst(double key);
struct bst *new_bst_and_fill(size_t nodes_count, ...);
struct bst *new_empty_bst();
struct bst *random_bst(size_t nodes);
struct doublev *bst_to_doublev(struct bst *b);
void append_bst(struct bst *b, double to_append);
void bst_to_doublev_aux(struct bst *b, struct doublev *dv);
void free_bst(struct bst *b);
void print_bst(struct bst *b);

void print_offset(FILE* stream, int offset);

#endif
