#set term png size 1900,1000 enhanced font "Terminal,10"
set term png

set grid

set key left top

set style fill solid border -1
set boxwidth 0.9

set xtic rotate by -45 scale 0

set datafile separator ','
set xlabel "Memory (B)"
set ylabel "Time (s)"

plot "data/bsttoavlt_rec.dat" using 1:2 with lines t "Recursive version", "data/bsttoavlt_ite.dat" using 1:2 with lines t "Iterative version"

# set title "Intel(R) Pentium(R) bandwidth (in GiB/s) for a Load benchmark on a single array"
#unset multiplot

#set multiplot layout 5, 2 rowsfirst
