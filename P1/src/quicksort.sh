#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "./../images/quicksort.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo en microsegundos"
plot './../images/quicksort.txt' using 1:2 t "Real" w l, './../images/quicksort.txt' using 1:3 t "Estimado" w l
_end_
