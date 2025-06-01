set title "ExerciceP11-spherique"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid
set ticslevel 0
splot \
  "pendule.dat" using 1:2:3 with linespoints lt rgb "red" pt 9 ps 0.8 lw 1.2 title "Pendule", 
pause mouse close
