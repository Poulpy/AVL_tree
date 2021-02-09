BIN_DIR=bin
BUILDDIR=build
FLAGS=-W -O2 -g -std=c99
CC=gcc
INC=-Isrc

.PHONY: tests benchmark plots check run_fat_benchmark run_local_benchmark plots dummy_plots massif_analysis

all: tests benchmark

build/doublev.o: src/doublev.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

bin/test_doublev: build/doublev.o tests/test_doublev.c
	$(CC) $(FLAGS) $(INC) $^ -o $@

build/bst.o: build/doublev.o src/bst.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

bin/test_bst: build/bst.o build/doublev.o tests/test_bst.c
	$(CC) $(FLAGS) $(INC) $^ -o $@

tests:
	mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) $(INC) src/doublev.c tests/test_doublev.c -o $(BIN_DIR)/test_doublev
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c tests/test_bst.c -o $(BIN_DIR)/test_bst
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_avl_tree.c -o $(BIN_DIR)/test_avl_tree
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c tests/test_stack.c -o $(BIN_DIR)/test_stack

benchmark:
	$(CC) $(FLAGS) $(INC) src/doublev.c src/bst.c src/iia.c src/stack.c src/avl_tree.c src/runner.c -o $(BIN_DIR)/runner

run_fat_benchmark:
	./bin/runner 1000 70000 100

run_local_benchmark:
	sudo cpupower -c 3 frequency-set --governor performance
	taskset -c 3 ./bin/runner 1000 50000 100

massif_analysis:
	valgrind --tool=massif ./bin/runner 1000 50000 1000

plots:
	gnuplot -c create_plots_bw.gp > data/plots/plots_$(shell date +%d_%H_%M_%S).png

dummy_plots:
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

