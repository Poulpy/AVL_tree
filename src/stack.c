#include "stack.h"

/*
 * new_stack
 *
 * Creates a stack
 * Note: don't forget to free_stack
 */
struct stack *new_stack(struct iia triplet) {
    struct stack *s;

    s = malloc(sizeof(struct stack));
    s->len = 1;
    s->triplets = malloc(sizeof(struct iia));
    s->triplets[0] = triplet;

    return s;
}

/*
 * is_empty_stack
 *
 * Check if a stack is empty
 */
bool is_empty_stack(struct stack *s) {
    return 0 == s->len;
}

/*
 * push_stack
 *
 * Appends a new value at the top of the stack
 */
void push_stack(struct stack *s, struct iia triplet) {
    s->triplets = realloc(s->triplets, sizeof(struct iia) * (s->len + 1));
    s->triplets[s->len] = triplet;
    s->len++;
}

/*
 * pop_stack
 *
 * Take out last item from the stack
 * Exception: can't pop if stack is empty
 */
struct iia pop_stack(struct stack *s) {
    struct iia triplet;

    if (is_empty_stack(s)) {
        perror("Can't pop empty stack");
    }

    triplet = s->triplets[s->len - 1];
    s->triplets = realloc(s->triplets, sizeof(struct iia) * (s->len - 1));
    s->len--;

    return triplet;
}

/*
 * free_stack
 *
 * Free the memory allocated by new_stack
 */
void free_stack(struct stack *s) {
    if (NULL == s) return;

    free(s->triplets);
    free(s);
}

/*
 * print_stack
 *
 * Print in the console the stack
 */
void print_stack(struct stack *s) {
    if (NULL == s) return;

    for (size_t i = 0; i != s->len; i++) {
        print_iia(s->triplets[i]);
    }
}
