BIN_DIR=bin
FLAGS=-W -O2 -g -std=c99
CC=gcc
INC=-Isrc

.PHONY: tests benchmark plots check

all: tests benchmark

tests:
	mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) $(INC) src/doublev.c tests/test_doublev.c -o $(BIN_DIR)/test_doublev
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c tests/test_bst.c -o $(BIN_DIR)/test_bst
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_avl_tree.c -o $(BIN_DIR)/test_avl_tree
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_stack.c -o $(BIN_DIR)/test_stack

benchmark:
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c src/runner.c -o $(BIN_DIR)/runner

plots:
	gnuplot -c create_plots_bw.gp > data/plots/plots_$(date +%Y_%m_%d_%H_%M_%S).png

check: tests
	./$(BIN_DIR)/test_doublev
	./$(BIN_DIR)/test_stack
	./$(BIN_DIR)/test_bst
	./$(BIN_DIR)/test_avl_tree

clean:
	rm $(BIN_DIR)/*
	rmdir $(BIN_DIR)
