#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Número de elementos"
set ylabel "Tiempo en microsegundos"
plot 'Datos.txt' using 1:2 t "Datos columna 2 frente a 1" w l
_end_
