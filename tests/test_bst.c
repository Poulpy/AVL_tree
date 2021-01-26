#include <stdio.h>
#include <assert.h>

#include "bst.h"

void test_new_bst() {
    struct bst *b;

    b = new_bst(3.0);

    free_bst(b);
}

void test_append_bst() {
    struct bst *b;

    b = new_bst(3.0);
    assert(contains_bst(b, 3.0));

    append_bst(b, 5.4);

    assert(contains_bst(b, 5.4));
    assert(!contains_bst(b, 34.4));

    append_bst(b, 34.4);
    assert(contains_bst(b, 34.4));

    free_bst(b);
}

void test_height() {
    struct bst *b;

    b = new_bst(5.0);
    assert(height(b) == 0);
    append_bst(b, 3.0);
    assert(height(b) == 1);
    assert(height(NULL) == -1);
    free_bst(b);
}

int main() {
    test_new_bst();
    test_append_bst();
    test_height();

    return 0;
}
