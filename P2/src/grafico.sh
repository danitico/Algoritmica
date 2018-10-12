#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "prueba.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo en microsegundos"
plot 'SinRecursividad.txt  ' using 1:2 t "Real" w l
_end_
