#include <assert.h>

#include "stack.h"
#include "avl_tree.h"

void test_new_stack() {
    struct avl_tree *root;
    struct stack *s;
    root = new_avl_tree(3.0);
    struct iia triplet = {1, 1, root};

    s = new_stack(triplet);
    assert(s->len == 1 && s->triplets[0].a->key == 3.0);

    free_stack(s);
    free_avl_tree(root);
}

void test_push_stack() {
    struct avl_tree *root;
    struct stack *s;
    root = new_avl_tree(3.0);
    struct iia triplet = {1, 1, root};
    struct iia triplet2 = {1, 2, root};

    s = new_stack(triplet);
    push_stack(s, triplet2);
    assert(s->len == 2);

    free_stack(s);
    free_avl_tree(root);
}

void test_pop_stack() {
    struct avl_tree *root;
    struct stack *s;
    root = new_avl_tree(3.0);
    struct iia triplet = {1, 1, root};
    struct iia triplet2 = {5, 2, root};

    s = new_stack(triplet);
    push_stack(s, triplet2);
    struct iia triplet3 = pop_stack(s);
    assert(s->len == 1 && triplet3.i == 5 && triplet3.j == 2);

    free_stack(s);
    free_avl_tree(root);
}

int main() {
    test_new_stack();
    test_push_stack();
    test_pop_stack();

    return 0;
}
