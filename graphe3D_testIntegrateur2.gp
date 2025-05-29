 set title "Comparaison Euler, RungeKutta et Newmark pour un point materiel dans une trajectoire parabolique" 
set xlabel "X" 
set ylabel "Y" 
set zlabel "Z" 
set grid
set ticslevel 0
splot \
  "test_integrateur_2.dat" using 1:2:3 with linespoints lt rgb "red" pt 9 ps 0.8 lw 1.2 title "Euler", \
  "test_integrateur_2.dat" using 4:5:6 with linespoints lt rgb "blue" pt 9 ps 0.8 lw 1.2 title "RungeKutta4", \
  "test_integrateur_2.dat" using 7:8:9 with linespoints lt rgb "green" pt 9 ps 0.8 lw 1.2 title "Newmark"
pause -1
