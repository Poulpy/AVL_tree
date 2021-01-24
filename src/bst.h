#ifndef

struct bst {
    struct bst *left;
    struct bst *right;
    double *key;
};

struct bst *new_bst(double *key);
struct bst *new_bst_from_adjacency_list(struct doublevv **adjacency_list);
void destroy_bst(struct bst *b);

#endif
