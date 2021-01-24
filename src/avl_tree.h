#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <math.h>
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

struct avl_tree *new_avl_tree_from_array(struct doublev *dv);
struct avl_tree *bst_to_avl_tree(struct bst *b);

#endif
