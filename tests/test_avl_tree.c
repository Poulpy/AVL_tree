#include <assert.h>

#include "avl_tree.h"

void test_new_avl_tree() {
    struct avl_tree *root;
    root = new_avl_tree(3.0);
    free_avl_tree(root);
}

void test_doublev_to_avl_tree() {
    struct doublev *values;
    struct avl_tree *root;

    values = new_doublev_and_fill(5, 3.0, 4.0, 5.9, 6.0, 7.0);
    root = doublev_to_avl_tree(values);
    print_avl_tree(root);
    free_avl_tree(root);
    free_doublev(values);
}

void test_bst_to_avl_tree() {

}

int main() {
    test_new_avl_tree();
    test_doublev_to_avl_tree();
    test_bst_to_avl_tree();

    return 0;
}
