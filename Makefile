all:
	gcc -std=c99 -O3 -g -Isrc/ src/doublev.c tests/test_doublev.c -o test_doublev
	gcc -std=c99 -O3 -g -Isrc/ src/bst.c tests/test_bst.c -o test_bst

