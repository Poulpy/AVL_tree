#include <time.h>
#include <stdlib.h>

#include "bst.h"
#include "avl_tree.h"

#define MEM_BEGIN 10000
#define MEM_END 50000
#define MEM_STEP 100
#define MEM_ITERATIONS (MEM_END / MEM_STEP)
#define REPETITIONS 100
#define TYPESIZE 64

unsigned g_mem_begin;
unsigned g_mem_end;
unsigned g_mem_step;
unsigned g_mem_iterations;

void dump_run(float records[], int sizes[], size_t len, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) return;

    for (size_t j = 0; j != len; j++) {
        fprintf(f, "%d,%f\n", sizes[j], records[j]);
    }

    fclose(f);
}

void run_test_it(const char *filename) {
    //float records[MEM_ITERATIONS];
    //int sizes[MEM_ITERATIONS];
    struct bst *rnd_bst;
    struct avl_tree *rnd_avl_tree;
    float *records;
    int *sizes;

    records = calloc(g_mem_iterations, sizeof(float));
    sizes = calloc(g_mem_iterations, sizeof(int));

    for (size_t i = g_mem_begin, j = 0; j != g_mem_iterations; i += g_mem_step, j++) {
        rnd_bst = random_bst(i);

        clock_t start = clock();
        rnd_avl_tree = bst_to_avl_tree_it(rnd_bst);
        clock_t end = clock();

        records[j] = (float) (end - start) / CLOCKS_PER_SEC;
        sizes[j] = TYPESIZE * i;

        free_bst(rnd_bst);
        free_avl_tree(rnd_avl_tree);
    }
    dump_run(records, sizes, g_mem_iterations, filename);

    free(sizes);
    free(records);
}

void run_test(const char *filename) {
    //float records[MEM_ITERATIONS];
    //int sizes[MEM_ITERATIONS];

    struct bst *rnd_bst;
    struct avl_tree *rnd_avl_tree;
    float *records;
    int *sizes;

    records = calloc(g_mem_iterations, sizeof(float));
    sizes = calloc(g_mem_iterations, sizeof(int));

    for (size_t i = g_mem_begin, j = 0; j != g_mem_iterations; i += g_mem_step, j++) {
        rnd_bst = random_bst(i);

        clock_t start = clock();
        rnd_avl_tree = bst_to_avl_tree(rnd_bst);
        clock_t end = clock();

        records[j] = (float) (end - start) / CLOCKS_PER_SEC;
        sizes[j] = TYPESIZE * i;

        free_bst(rnd_bst);
        free_avl_tree(rnd_avl_tree);
    }
    dump_run(records, sizes, g_mem_iterations, filename);

    free(sizes);
    free(records);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        perror("./<exe> <begin> <end> <step>");
        return 1;
    }

    g_mem_begin = atoi(argv[1]);
    g_mem_end = atoi(argv[2]);
    g_mem_step = atoi(argv[3]);
    g_mem_iterations = g_mem_end / g_mem_step;

    printf("Running benchmarks for \n %d -> %d, step %d\n", g_mem_begin, g_mem_end, g_mem_step);
    printf("for %d\n", g_mem_iterations);

    run_test("data/csv/bsttoavlt_rec.dat");
    run_test_it("data/csv/bsttoavlt_ite.dat");

    return 0;
}

