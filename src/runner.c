#include <time.h>

#include "bst.h"
#include "avl_tree.h"

#define MEM_BEGIN 10000
#define MEM_END 50000
#define MEM_STEP 1000
#define MEM_ITERATIONS (MEM_END / MEM_STEP)
#define REPETITIONS 100
#define TYPESIZE 64

void dump_run(float records[], int sizes[], size_t len, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) return;

    for (size_t j = 0; j != len; j++) {
        fprintf(f, "%d,%f\n", sizes[j], records[j]);
    }

    fclose(f);
}

void run_test_it(const char *filename) {
    float records[MEM_ITERATIONS];
    int sizes[MEM_ITERATIONS];
    struct bst *rnd_bst;
    struct avl_tree *rnd_avl_tree;

    for (size_t i = MEM_BEGIN, j = 0; j != MEM_ITERATIONS; i += MEM_STEP, j++) {
        rnd_bst = random_bst(i);

        clock_t start = clock();
        rnd_avl_tree = bst_to_avl_tree_it(rnd_bst);
        clock_t end = clock();

        records[j] = (float) (end - start) / CLOCKS_PER_SEC;
        sizes[j] = TYPESIZE * i;

        free_bst(rnd_bst);
        free_avl_tree(rnd_avl_tree);
    }
    dump_run(records, sizes, MEM_ITERATIONS, filename);
}

void run_test(const char *filename) {
    float records[MEM_ITERATIONS];
    int sizes[MEM_ITERATIONS];
    struct bst *rnd_bst;
    struct avl_tree *rnd_avl_tree;

    for (size_t i = MEM_BEGIN, j = 0; j != MEM_ITERATIONS; i += MEM_STEP, j++) {
        rnd_bst = random_bst(i);

        clock_t start = clock();
        rnd_avl_tree = bst_to_avl_tree(rnd_bst);
        clock_t end = clock();

        records[j] = (float) (end - start) / CLOCKS_PER_SEC;
        sizes[j] = TYPESIZE * i;

        free_bst(rnd_bst);
        free_avl_tree(rnd_avl_tree);
    }
    dump_run(records, sizes, MEM_ITERATIONS, filename);
}

int main() {
    run_test("data/bsttoavlt_rec.dat");
    run_test_it("data/bsttoavlt_ite.dat");

    return 0;
}
