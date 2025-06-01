# projet-POO-2025 PH BA2 | Assistant : Arthur Wurhmann | https://github.com/Tekbl/projet-POO-2025
Binôme : Matthias Calatroni & Valentino Lekimpe 

# Questions

## QUESTION 1  

Simulations et Tests effectués :
- VecteurTestV
- testPointMateriel
- testIntegrateur1 (Euler)
- ExerciceP9 (chute de pomme)
- ExerciceP9-LeCorbeauEtLeRenard
- gnuplot_test (testIntegrateur1 avec un graphe gnuplot)
- TestIntegrateur2 (comparaison de Euler, Runge-Kutta 4 et Newmark en affichant les graphes sur gnuplot)
- ExerciceP11-magnetique
- ExerciceP11-pendule

Intégrateur ajouté à l'étape 8 : Runge Kutta 4

Extensions effectuées :
- Second Intégrateur -> Newmark (les résultats sont très proches des résultats attendus mais ne sont pas exacts)
- Second exercice de physique avancé : ExerciceP11-pendule
- Sauvegarde des données sur les deux exerciceP11, test_integrateur 1&2, Pomme et ExerciceP9 le corbeau et le Renard.
- Ajout personnel : affichage gnuplot pour visualiser les trajectoires.

## QUESTION 2 

Nous n'avons malheureusement pas eu le temps d'adresser le graphisme dans notre projet. 
Pour palier à ça nous avons décidé de rajouter des graphes gnuplot aux simulations pour au moins avoir une manière de visualier les données simulées 

Celà est du au temps perdu sur le débuggage. En effet nous avons pris la mauvaise approche concernant le projet en ne faisant aucun tests entre le moment où nous avons testé la classe vecteur et le moment ou nous devions commencer à simuler des exercices comme le P9.
Pour notre défense nous étions un peu perdu avec les instructions et à chaque étape il était indiqué que le code était incomplet et ne pouvait pas tourner en tant que tel. Nous nous sommes donc résolus à attendre les instructions des semaines suivantes pour pouvoir tester, sauf que cette instant était constamment repoussé par du nouveau code incomplet.
Nous avons donc entrepris d'attendre les nouvelles instructions sans essayer de faire fonctionner un code incomplet en comblant les trous, se disant que c'était une perte de temps. Il se trouve que c'était une grave erreur nous retiendrons cette leçon.  

_Note personnelle de Valentino : j'ai vraiment envie de faire le graphisme, je le ferais après les examens._


## QUESTION 3 

Temps moyen estimé par personne par semaine : 6h  
Semaine 1 : rien  
Semaines 2-3-4-5-6-7-8-9 : 4h/personnne  
Vacances de Pâques : 12h par personne  
Semaines 10-11-12-13-14 : 8h/personne  

# Organisation du Projet 

Fichiers :
Tout les fichiers sont dans un seul dossier.
- Le Makefile génère l'édition des liens et nous permet de créér les fichiers .o et .exe.
- Les fichiers .cc et .h sont les fichiers de code c++ avec les définitions et déclarations.
- Les fichiers .dat sont les enregistrement des données des exercices simulés.
- Les fichiers .gp contiennent les données et les informations permettant d'afficher les simulations avec gnuplot.


la logique derrière l'assemblage des différentes classes est quand à elle expliquée dans le fichier CONCEPTION

# Exécution des simulations 

1. Ouvrir VM IC-CO-IN-SC
2. Unzip le dossier du projet rendu. 
3. Ouvrir le terminal de commande dans le répertoire du dossier unzipped  
 _vous pouvez également clone la repository github et delete tout les fichiers.o_
4. Écrire et entrer la commande : make       
/!\ Si une simulation utilisant un affichage gnuplot est ouvert, la commande make génère des erreurs. Pour régler ça, il faut fermer la fenêtre gnuplot et relancer la commande make.

5. Pour tester les simulations et fichiers test, entrer la commande **.\nom_de_la_simulation.exe** dans le terminal pour l'executer  
Voici les commandes dans l'ordre à ctrl_C/ctrl_V dans le terminal :   
    .\VecteurTestV  
    .\testPointMateriel  
    .\testIntegrateur1  
    .\gnuplot_test  
    .\ExerciceP9  
    .\ExerciceP9-LeCorbeauEtLeRenard _**je vous conseille de mettre la fenetre gnuplot en plein écran pour celui la**_  
    .\TestIntegrateur2  
    .\ExerciceP11-magnetique  
    .\ExerciceP11-pendule  

6. Observer et admirer les résultats

>**/!\ :** Normalement gnuplot est installé de base sur les VM, si ce n'est pas le cas sur votre VM, voici le lien d'installation http://www.gnuplot.info/download.html


7. Apprécier ce portrait de M.Chappelier 
```
<3                                                          
                                                  :*@@@%#*: ..                                              
                                            :*@@@@@@@@@@@@@@@@@@@@@+                                        
                                        -%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-                                    
                                   .+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.                                
                                -@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@@@@@@@+.                             
                              =%@@@@@@@@@@@@@@%#**#%%#**####%#%@@@%%@@@@@@@@@@@%:                           
                            -*##%@@@@%%%@@@@%#+=-=+++++=++****+*####%#@@@@@@@@@@@@=                         
                           =+++###@%**++#%@@%*+-:::-=+====+++++++*##%@@@@@@@@@@@@@@@=                       
                          -+=-=**%%**+==+***%#*+:...:-====++*****+*%%@@@@@@@@@@@@@@@@*                      
                         :*++-=**%#+*=::------=*##=:...:-==-==+***###%%@@@@@@@@@@@@@@@=                     
                         ++++-=*#%#**+-:::::::......::::.::::--==++*###%@@@@@@@@@@@@@@*                     
                         **#*=*%%%#+*+-:.....  .............:::--====+*#%@@@%@@@@@@@@@+                     
                         =##*+#%%%#++==++++++-::.  ..:.....:-=+*##%%%%#*#%@@###**##%%%*                     
                          +#**#%%@*++#%#%%%%#*==-:------=-=+**#%@@@%%@@@@%@@@****####%=                     
                           *+*#@@@=+***+=--=+****+++=---+#%@%#**++++*##%@@@@@%+######*                      
                           +#*#@@%***+=+@@@@@@@@%%%+-.:+@@@%##%@@@@@%*#%@@@@@%*%%%*##=                      
                           +###@@++#*+#*=-:-=++++-*+-::-#%=-=+==+++**%#%@@%@@@%@%%#%%.                      
                            =#%@@*+**==------=====#=:::-+@@#*++==+++***#%%%@@@@@@%@@=                       
                             :-*@#+=++=-:......:-*=--::=*%@#+--------=+#*#%@@@@@@@%                         
                              :--**+--=*+-:::-=*+----::-+*###*++=---=+++*%%@@@@@@*                          
                               :-+*+=-:.......::-----:.-+###*-:::--==++*#%@@%@@@*                           
                               :-=++==-::::--==:-*%#+==*%@@@%*=-::--==+*#%@@@@@+                            
                                .:-**+++++#*=-:::-==+#@@@@@@@#*+*#****#%%@@@@%+                             
                                   +*+=-+*=----------==++*###*****#%###@@@@:                                
                                   =+++=--+###++==--====+*###%%@@@@+-+#@%@*                                 
                                   .+==+=-=----=++*#%%%@@@@@@@@%##=-=*%@%@-                                 
                                     =+===-------===+++***#####**+=+*%@@@@-                                 
                                      -++==-----------==++++++++++*#%@@@@@-                                 
                                       ####+=----:::::---=====++#%%@@@@@@@#-                                
                                     :+**#%@@%*====-====+++***#%@@@@@@@@@@@@@%.                             
                                  .+##%+++*#%%@@%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@%-                            
                                 +*#@@*+++=+*****#%@@@@@@@@@@@@@@@@@@@@@@@@@@%%%*                           
                               -**#@%+*++====*+++++#%%@%%%@@@@@@@@@@@@@@@@@@%%%%%%=                         
                          .=******%%==++=+===+++==++*#%%%%%@@@@@@@@@@@@@@@%###%%%%%%##*:                    
                    :=************#*--==========-=++**####%%%@@%%%@@@%%@%####%%###%#######*=.               
             .-+*************#******---===========-===+++*########%%%%%####################****=.           
        .-+******************##*****=::-===---===-----==+++++++*##%%%################*##***********=:       
     -+**********************####****=::--==---===++++++=====++*#%%#**#########*##**********************=-. 
  -+**************************#####***=:::-==--===+========++*###****#######****#***************************
+********************************###***+:.::----------------=+++***######******##***************************
************************************##***+:..::::------------=+***#####*******##****************************
********************************************+-:--::::::::::=*****#####*******%******************************
**************************************##%@@@@@#***#=:::::=*%%%########*****#%*******************************
##*******************************##%%%%%%#####%%#####=-=**#@@%%%%%%%##****##******************************#*
##******************************#%##***#****#@@@#******##%@@%%#############******************************##*
###******************************************@@@%**##%@@@@@@@%###***************************************###*
###******************************************#@%%%%@@@@@%%%%%###***************************************####*
##*******************************************#%%%%%###########***************************************######*
##******************************************##%###************************************************#########*
##*****************************************####***************************************************########**
#******************************************##**#************************************************##########**