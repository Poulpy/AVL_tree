#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <math.h>
#include <stdbool.h>

#include "doublev.h"
#include "bst.h"

/*
 * AVL tree
 *
 * It's a self-balancing binary search tree
 * Named after inventors Adelson-Velsky and Landis (Wikipedia)
 *
 * Notes: Why create another struct equivalent to bst ?
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
bool is_balanced(struct avl_tree *root);

// TODO is_right_heavy
// TODO is_left_heavy

#endif
