#include "bst.h"

/*
 * new_bst
 * Creates a new bst with a given key
 *
 * Note: don't forget to free
 */
struct bst *new_bst(double key) {
    struct bst *b;

    b = (struct bst *) calloc(sizeof(struct bst), 1);
    b->key = key;
    b->left = NULL;
    b->right = NULL;

    return b;
}

/*
 * free_bst
 * Free the memory for a given bst
 */
void free_bst(struct bst *b) {
    if (b == NULL) return;

    free_bst(b->left);
    free_bst(b->right);
    free(b);
}

/*
 * append_bst
 * Append a new element (double) in the bst
 */
void append_bst(struct bst *b, double to_append) {
    struct bst *current_node, *previous_node;
    bool went_left;

    current_node = b;

    while (current_node != NULL) {
        previous_node = current_node;

        if (to_append <= current_node->key) {
            current_node = current_node->left;
            went_left = true;
        } else {
            current_node = current_node->right;
            went_left = false;
        }
    }

    if (went_left) {
        previous_node->left = new_bst(to_append);
    } else {
        previous_node->right = new_bst(to_append);
    }
}

void print_offset(FILE* stream, int offset)
{
    int i;
    for (i = 0; i < offset; ++i)
    {
        fprintf(stream, " ");
    }
}

void print_bst(struct bst *root) {
    static int offset = 0;

    print_offset(stdout, offset);

    if (root == NULL)
    {
        fprintf(stdout, "-\n");
        return;
    }
    fprintf(stdout, "%.2f\n", root->key);

    offset += 3;
    print_bst(root->left);
    print_bst(root->right);
    offset -= 3;
}

bool contains_bst(struct bst *b, double to_find) {
    struct bst *current_node;

    current_node = b;

    while (current_node != NULL) {
        if (to_find == current_node->key) {
            return true;
        } else if (to_find < current_node->key) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    return false;
}

