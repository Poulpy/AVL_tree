#include "stack.h"

struct stack *new_stack(struct iia triplet) {
    struct stack *s;

    s = malloc(sizeof(struct stack));
    s->len = 1;
    s->triplets = malloc(sizeof(struct iia));
    s->triplets[0] = triplet;

    return s;
}

void push_stack(struct stack *s, struct iia triplet) {
    s->triplets = realloc(s->triplets, sizeof(struct iia) * (s->len + 1));
    s->triplets[s->len] = triplet;
    s->len++;
}

struct iia pop(struct stack *s) {
    struct iia triplet;

    triplet = s->triplets[s->len - 1];
    s->triplets = realloc(s->triplets, sizeof(struct iia) * (s->len - 1));
    s->len--;

    return triplet;
}

void free_stack(struct stack *s) {
    free(s->triplets);
    free(s);
}

void print_stack(struct stack *s) {
    for (size_t i = 0; i != s->len; i++) {
        print_iia(s->triplets[i]);
    }
}
