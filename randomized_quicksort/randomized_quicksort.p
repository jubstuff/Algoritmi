# prove grafico insertion sort
set title "Randomized Quicksort" 
set xlabel "Dimensioni Input"
set ylabel "Tempo Impiegato"
#set yrange [0:400]
set pointsize 1.5
plot "dati_randomized_quicksort_0_100_Array.dat" using 2:3 with linespoint 3,0.000000035*x*(log(x)/log(2)),0.0000001*x*log(x)
