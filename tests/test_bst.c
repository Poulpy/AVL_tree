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

void test_bst_to_doublev() {
    struct bst *b, *b2;
    struct doublev *dv, *dv2, *dv3;

    b = new_bst(3.0);
    append_bst(b, 2.0);
    append_bst(b, 2.0);
    append_bst(b, 5.0);
    append_bst(b, 290.4);
    append_bst(b, 290.04);
    dv = bst_to_doublev(b);
    dv2 = new_doublev_and_fill(5, 2.0, 3.0, 5.0, 290.4, 290.04);
    assert(eql_doublev(dv, dv2));

    dv3 = bst_to_doublev(NULL);
    assert(dv3->len == 0);

    free_doublev(dv);
    free_doublev(dv2);
    free_doublev(dv3);
    free_bst(b);
}

int main() {
    test_new_bst();
    test_append_bst();
    test_height();
    test_bst_to_doublev();

    return 0;
}
