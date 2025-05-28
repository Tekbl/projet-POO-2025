 set title "Trajectoire 3D du point materiel" 
set xlabel "X" 
set ylabel "Y" 
set zlabel "Z" 
set grid
set ticslevel 0
splot "test_integrateur_1.dat" using 1:2:3 with lines title "Trajectoire"
pause -1
