#include "iia.h"

void print_iia(struct iia triplet) {
    printf("(%d %d %.2f)\n", triplet.i, triplet.j, triplet.a->key);
}
