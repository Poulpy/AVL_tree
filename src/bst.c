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


void print_bst_aux(struct bst *root, int space, int height) {
    // Base case
    if (root == NULL)
        return;

    // increase distance between levels
    space += height;

    // print right child first
    print_bst_aux(root->right, space, 10);
    puts("");

    // print the current node after padding with spaces
    for (int i = height; i < space; i++) {
        printf(" ");
    }
    printf("%f", root->key);

    // print left child
    puts("");
    print_bst_aux(root->left, space, 10);
}

void print_bst(struct bst *root) {
    print_bst_aux(root, 10, 10);
}
//struct bst *new_bst_from_adjacency_list(struct doublevv **adjacency_list);
