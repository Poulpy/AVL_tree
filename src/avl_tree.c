#include "avl_tree.h"

/*
 * new_empty_avl_tree
 *
 * Creates a new AVL tree with no value for the root node
 * Note: don't forget to free_avl_tree
 */
struct avl_tree *new_empty_avl_tree() {
    struct avl_tree *root;

    root = (struct avl_tree *) calloc(sizeof(struct avl_tree), 1);
    root->left = NULL;
    root->right = NULL;

    return root;
}


/*
 * new_avl_tree
 *
 * Creates a new AVL tree with a given key for the first node
 *
 * Note: don't forget to free
 */
struct avl_tree *new_avl_tree(double key) {
    struct avl_tree *root;

    root = (struct avl_tree *) calloc(sizeof(struct avl_tree), 1);
    root->key = key;
    root->left = NULL;
    root->right = NULL;

    return root;
}


/*
 * free_avl_tree
 *
 * Free the memory for a given avl_tree
 */
void free_avl_tree(struct avl_tree *root) {
    if (root == NULL) return;

    free_avl_tree(root->left);
    free_avl_tree(root->right);
    free(root);
}

/*
 * bst_to_avl_tree
 *
 * Converts a BST to an AVL tree (balanced BST)
 *
 * Note: don't forget to free
 */
struct avl_tree *bst_to_avl_tree(struct bst *b) {
    struct avl_tree *at;
    int diff;
    struct doublev *dv;

    // get values as a sorted array
    dv = bst_to_doublev(b);
    // dv = create avl tree from array
    at = doublev_to_avl_tree(dv);

    free_doublev(dv);

    return at;
}

struct avl_tree *doublev_to_avl_tree(struct doublev *dv) {
    if (NULL == dv) return NULL;

    return doublev_to_avl_tree_aux(dv, 0, dv->len - 1);
}

/*
 * doublev_to_avl_tree
 *
 * Converts a sorted array to an AVL tree
 * Assumption: the array given is sorted
 * TODO: check array is sorted, or sort the array ?
 *
 * Note: don't forget to free_avl_tree
 */
struct avl_tree *doublev_to_avl_tree_aux(struct doublev *dv, size_t l, size_t h) {
    //struct doublev *bottom_part, *upper_part;
    struct avl_tree *root;
    size_t middle;

    if (h < l) return NULL;
    printf("l %d h %d \n", l, h);

    if (h == l) {
        root = new_avl_tree(dv->v[h]);
    } else {
        middle = (h - l + 1) / 2 + l;
        printf("m %d\n", middle);
        //bottom_part = slice_doublev(dv, 0, middle - 1);
        //upper_part = slice_doublev(dv, middle + 1, dv->len - 1);

        root = new_avl_tree(dv->v[middle]);
        root->left = doublev_to_avl_tree_aux(dv, l, middle - 1);
        root->right = doublev_to_avl_tree_aux(dv, middle + 1, h);
        puts("=========");
        print_avl_tree(root);

        //free_doublev(bottom_part);
        //free_doublev(upper_part);
    }

    return root;
}

/*
 * bst_to_avl_tree_it
 *
 * Create an AVL tree from a BST (iterative version using stack)
 *
 * Note: don't forget to free
 */
struct avl_tree *bst_to_avl_tree_it(struct bst *b) {
    struct avl_tree *a, *root;
    struct doublev *dv;
    struct stack *s;
    struct iia triplet;
    size_t l, h, m;

    // get values as a sorted array
    dv = bst_to_doublev(b);

    root = new_avl_tree(0.0);
    s = new_stack((struct iia) { 0, dv->len - 1, root });

    while (!is_empty_stack(s)) {
        triplet = pop_stack(s);
        l = triplet.i;
        h = triplet.j;
        a = triplet.a;

        if (h - l == 0) {
            a->key = dv->v[h];
        } else {
            m = ((h - l + 1) / 2) + l;
            a->key = dv->v[m];

            if (h >= m + 1) {
                a->right = new_empty_avl_tree();
                push_stack(s, (struct iia) {m + 1, h, a->right});
            }
            if (m - 1 >= l) {
                a->left = new_empty_avl_tree();
                push_stack(s, (struct iia) {l, m - 1, a->left});
            }
        }
    }

    free_stack(s);
    free_doublev(dv);

    return root;
}


/*
 * print_avl_tree
 *
 * Prints a avl_tree in the console
 */
void print_avl_tree(struct avl_tree *root) {
    static int offset = 0;

    print_offset(stdout, offset);

    if (root == NULL)
    {
        fprintf(stdout, "-\n");
        return;
    }
    fprintf(stdout, "%.2f\n", root->key);

    offset += 3;
    print_avl_tree(root->left);
    print_avl_tree(root->right);
    offset -= 3;
}

/*
 * height_avl_tree
 *
 * Calculates the height of an avl_tree
 * Special cases (ref wikipedia):
 * No nodes: -1
 * 1 node: 0
 */
int height_avl_tree(struct avl_tree *root) {
    int left_height, right_height;

    if (root == NULL) return -1;

    left_height = height_avl_tree(root->left);
    right_height = height_avl_tree(root->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

/*
 * is_balanced
 *
 * Check if the BF (balance factor) of each node is in {0, -1, 1}
 */
bool is_balanced(struct avl_tree *root) {
    int balance_factor;

    if (NULL == root) return true;

    balance_factor = height_avl_tree(root->left) - height_avl_tree(root->right);

    if (balance_factor == 1 || balance_factor == 0 || balance_factor == -1) {
        return is_balanced(root->left) || is_balanced(root->right);
    } else {
        return false;
    }
}

/**
 * eql_avl_tree
 *
 * Checks if 2 given AVL trées are equal
 */
bool eql_avl_tree(struct avl_tree *a1, struct avl_tree *a2) {
    if (NULL == a1 && NULL != a2 || NULL != a1 && NULL == a2) {
        return false;
    } else if (NULL == a1 && NULL == a2) {
        return true;
    } else {
        return a1->key == a2->key && eql_avl_tree(a1->left, a2->left)
               && eql_avl_tree(a1->right, a2->right);
    }
}
