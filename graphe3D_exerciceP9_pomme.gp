 set title "Chute d'une pomme vers la terre" 
set xlabel "X" 
set ylabel "Y" 
set zlabel "Z" 
set grid
set ticslevel 0
splot "exerciceP9_pomme.dat" using 1:2:3 with linespoints lt rgb "red" pt 9 ps 0.8 lw 1.2 title "particule chargee"
pause -1
