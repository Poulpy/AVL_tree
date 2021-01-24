#include "avl_tree.h"

struct avl_tree *new_avl(double key) {
    struct avl_tree *root;

    b = (struct avl_tree *) calloc(sizeof(struct avl_tree), 1);
    b->key = key;
    b->left = NULL;
    b->right = NULL;

    return root;
}


#if 1==2
struct avl_tree *bst_to_avl_tree(struct bst *b) {
    struct avl_tree *at;
    int diff;
    struct doublev *dv;

    // get values as a sorted array
    // dv = create avl tree from array
    // at = new_avl_tree_from_array();

    return at;
}
#endif

struct avl_tree *new_avl_tree_from_array(struct doublev *dv) {
    struct avl_tree *root;

    if (dv->len == 1) {
        root = new_avl_tree(dv->v[0]);
    } else {
        medium = dv->len / 2;
        bottom_part = slice_doublev(dv, 0, m - 1);
        upper_part = slice_doublev(dv, m - 1, dv->len - 1);

        root = new_avl_tree(dv->v[m]);
        root->left = new_avl_tree_from_array(bottom_part);
        root->right = new_avl_tree_from_array(upper_part);
    }

    return root;
}
