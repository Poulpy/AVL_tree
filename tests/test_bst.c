#include "bst.h"
#include <stdio.h>

void test_new_bst() {
    struct bst *b;

    b = new_bst(3.0);

    free_bst(b);

    puts("OK");
}

void test_append_bst() {

}

int main() {
    test_new_bst();
    return 0;
}
