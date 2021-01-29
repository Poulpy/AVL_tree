#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <math.h>

#include "doublev.h"
#include "bst.h"

/*
 * Why create another struct equivalent to bst ?
 * Because the insertion of an element in a AVL tree is different
 * The tree must stay balanced :)
 */
struct avl_tree {
    struct avl_tree *left;
    struct avl_tree *right;
    double key;
};

int height_avl_tree(struct avl_tree *root);
struct avl_tree *bst_to_avl_tree(struct bst *b);
struct avl_tree *doublev_to_avl_tree(struct doublev *dv);
struct avl_tree *new_avl_tree(double key);
void print_avl_tree(struct avl_tree *root);
void free_avl_tree(struct avl_tree *root);
#endif
