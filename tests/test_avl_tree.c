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
    assert(height_avl_tree(root) == 2 && is_balanced(root));
    free_avl_tree(root);

    root = doublev_to_avl_tree(NULL);
    assert(NULL == root);
    free_doublev(values);

    values = new_doublev_and_fill(7, 3.0, 4.0, 5.9, 6.0, 7.0, 8.1, 9.3);
    root = doublev_to_avl_tree(values);
    assert(height_avl_tree(root) == 2 && is_balanced(root));
    free_doublev(values);
    free_avl_tree(root);

    values = new_doublev_and_fill(1, 5.0);
    root = doublev_to_avl_tree(values);
    assert(height_avl_tree(root) == 0 && root->key == 5.0 && is_balanced(root));
    free_doublev(values);
    free_avl_tree(root);
}

void test_bst_to_avl_tree() {
    struct bst *b;
    struct avl_tree *root;

    b = new_bst(4.0);
    append_bst(b, 5.0);
    append_bst(b, 6.0);
    append_bst(b, 7.0);
    append_bst(b, 6.5);
    root = bst_to_avl_tree(b);

    assert(is_balanced(root) && height_avl_tree(root) <= 2 && height_avl_tree(root) > 0);

    free_avl_tree(root);
    free_bst(b);
}

void test_bst_to_avl_tree_it() {
    struct bst *b;
    struct avl_tree *a, *a2;

    //b = random_bst(20);
    b = new_bst(4.0);
    append_bst(b, 5.0);
    append_bst(b, 6.0);
    append_bst(b, 7.0);
    append_bst(b, 6.5);


    //print_bst(b);
    a = bst_to_avl_tree_it(b);
    a2 = bst_to_avl_tree(b);

    print_avl_tree(a2);
    puts("----");
    print_avl_tree(a);
    assert(is_balanced(a) && eql_avl_tree(a, a2));

    free_avl_tree(a);
    free_avl_tree(a2);
    free_bst(b);
}

int main() {
    test_new_avl_tree();
    test_doublev_to_avl_tree();
    test_bst_to_avl_tree();
    test_bst_to_avl_tree_it();

    return 0;
}
