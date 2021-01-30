#ifndef STACK_H
#define STACK_H

#include "iia.h"

struct stack {
    struct iia *triplets;
    size_t len;
};

struct stack *new_stack(struct iia triplet);
void push_stack(struct stack *s, struct iia triplet);
struct iia pop_stack(struct stack *s);
void free_stack(struct stack *s);
void print_stack(struct stack *s);
bool is_empty_stack(struct stack *s);

#endif
