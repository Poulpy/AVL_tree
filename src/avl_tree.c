#include "avl_tree.h"

struct avl_tree *balance_bst(struct bst *b) {
    int diff;
    struct doublev *dv;

    diff = abs(height(b->left) - height(b->right));


}
