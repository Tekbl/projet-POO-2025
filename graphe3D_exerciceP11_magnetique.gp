 set title "Trajectoire 3D du point materiel dans un champ electromagnetique avec frottements" 
set xlabel "X" 
set ylabel "Y" 
set zlabel "Z" 
set grid
set ticslevel 0
splot "exerciceP11_magnetique.dat" using 1:2:3 with lines title "particule chargee"
pause -1
