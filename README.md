# AVL_tree
 Implementation in C of binary search tree + avl tree.
 An AVL tree is a self-balancing binary search tree, named after inventors Adelson-Velsky and Landis (Wikipedia).

!(Plots)[plots.png]

# Tests

To compile the tests, run
```
make
```

To run the tests :
```
./bin/test_doublev
./bin/test_bst
./bin/test_avl_tree
```

# Want to contribute ?

```
find * -name *.[ch] -type f | xargs grep -n TODO
```

# Notes

` gnuplot -c create_plots_bw.gp > plots.png` 
