#include <assert.h>

#include "avl_tree.h"

void test_new_avl_tree() {
    struct avl_tree *root;
    root = new_avl_tree(3.0);
    free_avl_tree(root);
}

void test_doublev_to_avl_tree() {

}

void test_bst_to_avl_tree() {

}

int main() {
    test_new_avl_tree();
    test_doublev_to_avl_tree();
    test_bst_to_avl_tree();

    return 0;
}
