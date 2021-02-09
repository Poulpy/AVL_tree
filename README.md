# AVL_tree
 Implementation in C of binary search tree + avl tree.
 An AVL tree is a self-balancing binary search tree, named after inventors Adelson-Velsky and Landis (Wikipedia).

![](data/plots/plots.png)

# Tests

To compile the tests, run
```
make tests
```

To run the tests :
```
make check
```

# Run benchmark and draw plots

```
# make sure your os is quiesced for better results
make benchmark
# plot is under data/plots
# csv files are under data/csv
```

# Want to contribute ?

```
find * -name *.[ch] -type f | xargs grep -n TODO
```

# Notes

` gnuplot -c create_plots_bw.gp > data/plots/plots.png`
