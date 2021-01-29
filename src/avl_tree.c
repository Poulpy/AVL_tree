#include "avl_tree.h"

/*
 * new_avl_tree
 *
 * Creates a new AVL tree with a given key for the first node
 *
 * Note: don't forget to free
 */
struct avl_tree *new_avl_tree(double key) {
    struct avl_tree *root;

    root = (struct avl_tree *) calloc(sizeof(struct avl_tree), 1);
    root->key = key;
    root->left = NULL;
    root->right = NULL;

    return root;
}


/*
 * free_avl_tree
 *
 * Free the memory for a given avl_tree
 */
void free_avl_tree(struct avl_tree *root) {
    if (root == NULL) return;

    free_avl_tree(root->left);
    free_avl_tree(root->right);
    free(root);
}

/*
 * bst_to_avl_tree
 *
 * Converts a BST to an AVL tree (balanced BST)
 *
 * Note: don't forget to free
 */
struct avl_tree *bst_to_avl_tree(struct bst *b) {
    struct avl_tree *at;
    int diff;
    struct doublev *dv;

    // get values as a sorted array
    dv = bst_to_doublev(b);
    // dv = create avl tree from array
    at = doublev_to_avl_tree(dv);

    return at;
}

/*
 * doublev_to_avl_tree
 *
 * Converts a sorted array to an AVL tree
 * Assumption: the array given is sorted
 *
 * Note: don't forget to free_avl_tree
 */
struct avl_tree *doublev_to_avl_tree(struct doublev *dv) {
    struct avl_tree *root;

    if (dv->len == 1) {
        root = new_avl_tree(dv->v[0]);
    } else {
        medium = dv->len / 2;
        bottom_part = slice_doublev(dv, 0, m - 1);
        upper_part = slice_doublev(dv, m - 1, dv->len - 1);

        root = new_avl_tree(dv->v[m]);
        root->left = doublev_to_avl_tree(bottom_part);
        root->right = doublev_to_avl_tree(upper_part);
    }

    return root;
}
