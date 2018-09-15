#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo en microsegundos"
plot 'sacudida.txt' using 1:2 t "Metodo Sacudida" w l
plot 'quicksort.txt' using 1:2 t "Metodo Quicksort" w l
_end_
