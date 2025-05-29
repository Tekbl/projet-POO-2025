set encoding utf8
set title "Le Corbeau et le Renard"

set label 1 "Maître corbeau, sur un arbre perché,\nTenait en son bec un fromage.\nMaître renard, par l'odeur alléché,\nLui tint à peu près ce langage :\n« Hé ! bonjour, Monsieur du Corbeau.\nQue vous êtes joli ! que vous me semblez beau !\nSans mentir, si votre ramage\nSe rapporte à votre plumage,\nVous êtes le phénix des hôtes de ces bois. »\nÀ ces mots, le corbeau ne se sent pas de joie ;\nEt pour montrer sa belle voix,\nIl ouvre un large bec, laisse tomber sa proie.\nLe renard s’en saisit, et dit : « Mon bon monsieur,\nApprenez que tout flatteur\nVit aux dépens de celui qui l’écoute.\nCette leçon vaut bien un fromage sans doute. »\nLe corbeau honteux et confus,\nJura, mais un peu tard, qu’on ne l’y prendrait plus." at screen 0.5,0.9 center
set xlabel "X" 
set ylabel "Y" 
set zlabel "Z" 
set grid
set ticslevel 0
splot \
  "exerciceP9_corbeau_renard.dat" using 1:2:3 with linespoints lt rgb "yellow" pt 9 ps 0.8 lw 1.2 title "fromage", \
  "exerciceP9_corbeau_renard.dat" using 4:5:6 with linespoints lt rgb "gray" pt 9 ps 0.8 lw 1.2 title "pierre", 
pause -1
