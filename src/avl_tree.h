#ifndef AVL_TREE_H
#define AVL_TREE_H

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

struct avl_tree *balance_bst(struct bst *b);

#endif
