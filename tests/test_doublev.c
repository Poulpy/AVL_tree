#include <stdio.h>
#include <assert.h>
#include "doublev.h"

void test_new_doublev() {
    struct doublev *v1;

    v1 = new_doublev(0);

    free_doublev(v1);
}

void test_concat_doublev() {
    struct doublev *v1, *v2, *v3;

    v1 = new_doublev(1);
    v2 = new_doublev(1);
    v1->v[0] = 1.0;
    v2->v[0] = 4.0;

    concat_doublev(v1, v2);

    assert(v1->len == 2 && v2->v[0] == 4.0 && v1->v[0] == 1.0);

    v3 = new_doublev(0);
    concat_doublev(v3, v1);

    assert(eql_doublev(v3, v1));

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

    assert(v1->v[0] == 0.0 && v1->v[1] == 4.0);

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

    assert(!eql_doublev(v1, v2));

    copy_doublev(v2, v1);
    assert(eql_doublev(v1, v2));

    assert(!eql_doublev(v3, v1));

    assert(eql_doublev(v4, v5));

    free_doublev(v1);
    free_doublev(v2);
    free_doublev(v3);
    free_doublev(v4);
    free_doublev(v5);
}

void test_new_doublev_and_fill() {
    struct doublev *v1;

    v1 = new_doublev_and_fill(3, 2.0, 3.0, 4.0);

    assert(v1->v[0] == 2.0 && v1->v[1] == 3.0 && v1->v[2] == 4.0);

    free_doublev(v1);
}

void test_append_doublev() {
    struct doublev *vector;

    vector = new_doublev_and_fill(4, 1.0, 1.0, 2.0, 3.0);
    append_doublev(vector, 2.0);

    assert(vector->len == 5 && vector->v[4] == 2.0);

    free_doublev(vector);
}

void test_clear_doublev() {
    struct doublev *vector, *empty_vector;

    vector = new_doublev_and_fill(2, 2.0, 2.0);

    empty_vector = new_doublev(0);
    clear_doublev(vector);

    assert(eql_doublev(vector, empty_vector));

    free_doublev(vector);
    free_doublev(empty_vector);
}

void test_slice_doublev() {
    struct doublev *dv, *slice;

    dv = new_doublev_and_fill(7, 2.0, 3.0, 4.0, 5.0, 5.0, 6.0, 8.0);
    slice = slice_doublev(dv, 2, 1);

    assert(slice == NULL);

    slice = slice_doublev(dv, 2, 2);

    assert(slice->len == 1 && slice->v[0] == 4.0);
    free_doublev(slice);

    slice = slice_doublev(dv, 2, 9);
    assert(slice == NULL);

    slice = slice_doublev(dv, 2, 5);
    assert(slice->len == 4 && slice->v[1] == 5.0 && slice->v[2] == 5.0);

    free_doublev(dv);
    free_doublev(slice);
}

void test_random_doublev() {
    struct doublev *dv, *dv2;
    dv = random_doublev(10);
    dv2 = random_doublev(10);
    print_doublev(dv);
    print_doublev(dv2);
    free_doublev(dv);
    free_doublev(dv2);
}

int main()
{
    test_new_doublev();
    test_concat_doublev();
    test_copy_doublev();
    test_eql_doublev();
    test_new_doublev_and_fill();
    test_append_doublev();
    test_clear_doublev();
    test_slice_doublev();
    test_random_doublev();

    return 0;
}
