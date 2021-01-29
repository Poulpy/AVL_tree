#include "bst.h"

/*
 * new_bst
 *
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
 *
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
 *
 * Append a new element (double) in the bst
 */
void append_bst(struct bst *b, double to_append) {
    struct bst *current_node, *previous_node;
    bool went_left;

    if (NULL == b) return;

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

/*
 * print_offset
 *
 * Prints space in a stream offset-times
 *
 * Example:
 * print_offset(stdin, 5);
 */
void print_offset(FILE* stream, int offset)
{
    int i;
    for (i = 0; i < offset; ++i)
    {
        fprintf(stream, " ");
    }
}

/*
 * print_bst
 *
 * Prints a bst in the console
 */
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

/*
 * contains_bst
 *
 * Check if a bst contains an element; returns a boolean
 */
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

/*
 * height
 *
 * Calculates the height of a bst
 * Special cases (ref wikipedia):
 * No nodes: -1
 * 1 node: 0
 */
int height(struct bst *b) {
    int left_height, right_height;

    if (b == NULL) return -1;

    left_height = height(b->left);
    right_height = height(b->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}


/*
 * bst_to_doublev
 *
 * Convert a bst into a sorted array
 *
 * Note: don't forget to free
 */
struct doublev *bst_to_doublev(struct bst *b) {
    struct doublev *dv;

    if (b == NULL) return new_doublev(0);

    dv = new_doublev(0);
    bst_to_doublev_aux(b, dv);

    return dv;
}

/*
 * bst_to_doublev_aux
 *
 * Iterate through a bst, and append the values met to an array
 * The iteration is done so that the array is already sorted (forgot the name
 * there's a name to this kind of iteration)
 *
 * Note: the array MUST be initialized
 */
void bst_to_doublev_aux(struct bst *b, struct doublev *dv) {
    if (b->left != NULL) {
        bst_to_doublev_aux(b->left, dv);
    }

    append_doublev(dv, b->key);

    if (b->right != NULL) {
        bst_to_doublev_aux(b->right, dv);
    }
}
