#include "doublev.h"

/**
 * Initialize an array of double
 *
 * Note: don't forget to free
 */
struct doublev *new_doublev(size_t len) {
    struct doublev *dv;

    dv = (struct doublev *) calloc(sizeof(struct doublev), 1);
    dv->v = (double *) calloc(sizeof(double), len);
    dv->len = len;

    return dv;
}

/**
 * Initialize a doublev of double of length len and fill it with the values
 * given (variable number of arguments)
 *
 * Example: new_doublev_and_fill(3, 1, 0, 8) gives [1, 0, 8]
 * Note: don't forget to free
 */
struct doublev *new_doublev_and_fill(size_t len, ...) {
    struct doublev *dv;
    va_list ap;

    dv = new_doublev(len);

    // filling the array with the values ...
    va_start(ap, len);
    for (size_t i = 0; i != len; i++)  {
        dv->v[i] = va_arg(ap, double);
    }
    va_end(ap);

    return dv;
}

/**
 * Checks if 2 arrays are equal
 *
 * Note: Both arrays must be of same length
 */
bool eql_doublev(struct doublev *double_vector1, struct doublev *double_vector2) {
    if (double_vector1->len != double_vector2->len) return false;
    // TODO weird
    if (double_vector1->len == 0 && double_vector2->len == 0) return true;

    return (memcmp(double_vector1->v, double_vector2->v, sizeof(double_vector1->len)) == 0);
}

/**
 * Free the struct doublev
 */
void free_doublev(struct doublev *dv) {
    free(dv->v);
    free(dv);
}

/**
 * Prints in the console the values of the array
 */
void print_doublev(struct doublev *dv) {
    printf("[");
    if (dv->len == 0) {
        printf("]\n");
        return;
    }

    for (size_t i = 0; i != dv->len - 1; i++) {
        printf("%f, ", dv->v[i]);
    }
    printf("%f]\n", dv->v[dv->len - 1]);
}

/**
 * Copy the values of an array into another
 *
 * Note: both arrays must be of same length
 */
void copy_doublev(struct doublev *to, struct doublev *from) {
    if (to->len != from->len) return;

    memcpy(to->v, from->v, sizeof(double *) * from->len);
}

/**
 * concat_doublev
 *
 * Concatenate the doublev to_add to the doublev doublev
 * Example: concat_doublev([1, 2], [4, 2]) gives [1, 2, 4, 2]
 */
void concat_doublev(struct doublev *dv, struct doublev *to_add) {
    size_t new_len, old_len;

    if (dv->len == 0 && to_add->len == 0) return;

    old_len = dv->len;
    new_len = old_len + to_add->len;
    dv->v = (double *) realloc(dv->v, sizeof(double) * new_len);
    dv->len = new_len;

    memcpy(&dv->v[old_len], to_add->v, sizeof(to_add->v));
}

/**
 * append_doublev
 *
 * Append a new element at the end of the doublev
 */
void append_doublev(struct doublev *dv, double to_append) {
    size_t new_len;

    new_len = dv->len + 1;
    dv->v = (void *) realloc(dv->v, sizeof(void) * new_len);
    dv->len++;
    dv->v[new_len - 1] = to_append;
}

/**
 * clear_doublev
 *
 * Remove all elements of a doublev
 */
void clear_doublev(struct doublev *dv) {
    dv->v = (void *) realloc(dv->v, sizeof(void) * 0);
    dv->len = 0;
}


