BIN_DIR=bin
FLAGS=-W -O2 -g -std=c99
CC=gcc
INC=-Isrc

all:
	mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) $(INC) src/doublev.c tests/test_doublev.c -o $(BIN_DIR)/test_doublev
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c tests/test_bst.c -o $(BIN_DIR)/test_bst
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/avl_tree.c tests/test_avl_tree.c -o $(BIN_DIR)/test_avl_tree
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/avl_tree.c src/runner.c -o $(BIN_DIR)/runner

clean:
	rm $(BIN_DIR)/*
	rmdir $(BIN_DIR)
