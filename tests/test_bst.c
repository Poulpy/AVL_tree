#include "bst.h"
#include <stdio.h>

void test_new_bst() {
    struct bst *b;

    b = new_bst(3.0);

    free_bst(b);

    puts("OK");
}

void test_append_bst() {
    struct bst *b;

    b = new_bst(3.0);
    if (contains_bst(b, 3.0)) {
        puts("OK");
    } else {
        puts("KO");
    }

    append_bst(b, 5.4);

    if (contains_bst(b, 5.4)) {
        puts("OK");
    } else {
        puts("KO");
    }
    if (!contains_bst(b, 34.4)) {
        puts("OK");
    } else {
        puts("KO");
    }

    append_bst(b, 34.4);
    if (contains_bst(b, 34.4)) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_bst(b);
}

int main() {
    test_new_bst();
    test_append_bst();

    return 0;
}
