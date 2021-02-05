BIN_DIR=bin
BUILDDIR=build
FLAGS=-W -O2 -g -std=c99
CC=gcc
INC=-Isrc

.PHONY: tests benchmark plots check

all: tests benchmark


build/doublev.o: src/doublev.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

bin/test_doublev: build/doublev.o tests/test_doublev.c
	$(CC) $(FLAGS) $(INC) $^ -o $@

build/bst.o: build/doublev.o src/bst.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

bin/test_bst: build/bst.o build/doublev.o tests/test_bst.c
	$(CC) $(FLAGS) $(INC) $^ -o $@


build/avl_tree.o: src/avl_tree.c build/bst.o build/stack.o build/doublev.o
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

build/iia.o: src/iia.c build/avl_tree.o
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

build/stack.o: build/iia.o
	$(CC) $(FLAGS) $(INC) -c $^ src/stack.c -o $@
bin/test_stack: build/stack.o
	$(CC) $(FLAGS) $(INC) $^ tests/test_stack.c -o $@


tests:
	mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) $(INC) src/doublev.c tests/test_doublev.c -o $(BIN_DIR)/test_doublev
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c tests/test_bst.c -o $(BIN_DIR)/test_bst
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_avl_tree.c -o $(BIN_DIR)/test_avl_tree
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_stack.c -o $(BIN_DIR)/test_stack

benchmark:
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c src/runner.c -o $(BIN_DIR)/runner
	./bin/runner

plots:
	gnuplot -c create_plots_bw.gp > data/plots/plots.png

check: tests
	./$(BIN_DIR)/test_doublev
	./$(BIN_DIR)/test_stack
	./$(BIN_DIR)/test_bst
	./$(BIN_DIR)/test_avl_tree

clean:
	rm $(BIN_DIR)/*
	rm $(BUILDDIR)/*
	rmdir $(BUILDDIR)
	rmdir $(BIN_DIR)

