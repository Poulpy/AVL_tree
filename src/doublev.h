#ifndef DOUBLEV_H
#define DOUBLEV_H

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <stdarg.h>

// Vector of double
struct doublev {
    double *v;
    size_t len;
};

bool eql_doublev(struct doublev *double_vector1, struct doublev *double_vector2);
struct doublev *new_doublev(size_t len);
struct doublev *new_doublev_and_fill(size_t len, ...);
void append_doublev(struct doublev *double_vector, double to_append);
void clear_doublev(struct doublev *double_vector);
void concat_doublev(struct doublev *double_vector, struct doublev *to_add);
void copy_doublev(struct doublev *to, struct doublev *from);
void free_doublev(struct doublev *double_vector);
void print_doublev(struct doublev *double_vector);

#endif
