#include <assert.h>

#include "stack.h"
#include "avl_tree.h"

void test_new_stack() {
    struct avl_tree *root;
    struct stack *s;
    root = new_avl_tree(3.0);
    struct iia triplet = {1, 1, root};

    s = new_stack(triplet);
    print_stack(s);
    assert(s->len == 1);

    free_stack(s);
    free_avl_tree(root);
}

void test_push_stack() {

}

void test_pop_stack() {

}

int main() {
    test_new_stack();
    test_push_stack();
    test_pop_stack();

    return 0;
}
