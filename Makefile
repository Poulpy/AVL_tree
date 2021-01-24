all:
	gcc -std=c99 -O3 -g -Isrc/ src/doublev.c tests/test_doublev.c
