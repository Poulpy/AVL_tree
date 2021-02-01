#ifndef STACK_H
#define STACK_H

#include "iia.h"

struct stack {
    struct iia *triplets;
    size_t len;
};

bool is_empty_stack(struct stack *s);
struct iia pop_stack(struct stack *s);
struct stack *new_empty_stack();
struct stack *new_stack(struct iia triplet);
void free_stack(struct stack *s);
void print_stack(struct stack *s);
void push_stack(struct stack *s, struct iia triplet);

#endif
