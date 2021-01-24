#include<stdio.h>
#include "doublev.h"

void test_new_doublev() {
    struct doublev *v1;

    v1 = new_doublev(0);

    free_doublev(v1);
    puts("OK");
}

void test_concat_doublev() {
    struct doublev *v1, *v2, *v3;

    v1 = new_doublev(1);
    v2 = new_doublev(1);
    v1->v[0] = 1.0;
    v2->v[0] = 4.0;

    concat_doublev(v1, v2);

    if (v1->len == 2 && v2->v[0] == 4.0 && v1->v[0] == 1.0) {
        puts("OK");
    } else {
        puts("KO");
    }

    v3 = new_doublev(0);
    concat_doublev(v3, v1);

    if (eql_doublev(v3, v1)) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(v1);
    free_doublev(v2);
    free_doublev(v3);
}

void test_copy_doublev() {
    struct doublev *v1, *v2;

    v1 = new_doublev(2);
    v2 = new_doublev(2);
    v1->v[0] = 1.0;
    v1->v[1] = 1.0;
    v2->v[0] = 0.0;
    v2->v[1] = 4.0;

    copy_doublev(v1, v2);

    if (v1->v[0] == 0.0 && v1->v[1] == 4.0) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(v1);
    free_doublev(v2);
}

void test_eql_doublev() {
    struct doublev *v1, *v2, *v3, *v4, *v5;

    v1 = new_doublev(2);
    v2 = new_doublev(2);
    v3 = new_doublev(3);
    v4 = new_doublev(0);
    v5 = new_doublev(0);
    v1->v[0] = 1.0;
    v1->v[1] = 1.0;
    v2->v[0] = 0.0;
    v2->v[1] = 4.0;

    if (!eql_doublev(v1, v2)) {
        puts("OK");
    } else {
        puts("KO");
    }

    copy_doublev(v2, v1);
    if (eql_doublev(v1, v2)) {
        puts("OK");
    } else {
        puts("KO");
    }

    if (!eql_doublev(v3, v1)) {
        puts("OK");
    } else {
        puts("KO");
    }

    if (eql_doublev(v4, v5)) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(v1);
    free_doublev(v2);
    free_doublev(v3);
    free_doublev(v4);
    free_doublev(v5);
}

void test_new_doublev_and_fill() {
    struct doublev *v1;

    v1 = new_doublev_and_fill(3, 2.0, 3.0, 4.0);

    if (v1->v[0] == 2.0 && v1->v[1] == 3.0 && v1->v[2] == 4.0) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(v1);
}

void test_append_doublev() {
    struct doublev *vector;

    vector = new_doublev_and_fill(4, 1.0, 1.0, 2.0, 3.0);
    append_doublev(vector, 2.0);
    if (vector->len == 5 && vector->v[4] == 2.0) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(vector);
}

void test_clear_doublev() {
    struct doublev *vector, *empty_vector;

    vector = new_doublev_and_fill(2, 2.0, 2.0);

    empty_vector = new_doublev(0);
    clear_doublev(vector);
    if (eql_doublev(vector, empty_vector)) {
        puts("OK");
    } else {
        puts("KO");
    }

    free_doublev(vector);
    free_doublev(empty_vector);
}

int main()
{
    test_new_doublev();
    test_concat_doublev();
    test_copy_doublev();
    test_eql_doublev();
    test_new_doublev_and_fill();
    test_append_doublev();
    // test_clear_doublev();

    return 0;
}
