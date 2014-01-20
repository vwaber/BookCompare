set autoscale
set xtic auto
set ytic auto
set title "Book Comparisons"
set xlabel "Processors"
set ylabel "Seconds"
set terminal postscript portrait color blacktext
set size 1.0, 0.7
#default for postscript is 10 by 7
set output "graph.ps"
plot "graph.dat" using 1:2 with linespoints lt 1 title 'Books = 40'

