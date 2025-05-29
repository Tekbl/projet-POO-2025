# Réponses aux questions sur le projet
## [Question P1.1] Comment représentez-vous ces vecteurs ? Comment sont-ils organisés : quels attributs ? quelles méthodes ? quels droits d'accès ?
On représente les vecteurs dans la classe vecteur avec un simple vector de double en private.  Nous avons 3 constructeurs par valeur et avons gardé le constructeur par défaut par défaut.
Les 3 constructeurs par valeur font respectivement où l’on donne un int en argument, ce qui crée un vecteur de la taille de cet int, rempli de 0. Un autre ou on passe 3 double, ce qui initialise un vecteur de dimension 3 avec ces doubles comme coordonnées. Le dernier copie simplement un vector déjà initialisé dans le vector de la classe.   

Nous avons un setter et un getter sur les coordonnées du vecteur, une méthode pour donner la dimension du vecteur, une pour augmenter la dimension de ce vecteur, les méthodes who am I et affiche héritée de printable pour dire quelle classe c’est et afficher le vecteur.   

Nous avons une méthode pour comparer 2 vecteurs entre eux qui renvoie true s’ils sont égaux, false sinon. Des méthodes pour additionner et soustraire des vecteurs et qui retournent le résultat. Une méthode oppose qui retourne l’inverse du vecteur. Une méthode mult pour multiplier toutes les coordonnées du vecteur par un scalaire. Une méthode qui permet de calculer le produit scalaire avec un autre vecteur. Une méthode pour faire le produit vectoriel de 2 vecteurs, uniquement si les 2 sont de dimension 3, sinon contraint les vecteur à être de dimension 3.   

Les méthodes norme et norme au carré permettant de calculer la norme, la méthode norme ne fait que calculer la racine de norme au carré. Finalement une méthode unitaire qui renvoie le vecteur normalisé.

## [Question P1.2] Quel choix avez vous fait pour les opérations entre vecteurs de dimensions différentes ?
Nous avons choisi d’augmenter la dimension du plus petit vecteur, c’est à dire : si on ajoute un vecteur de dimension 2 à un vecteur de dimension 3, celui de dimension 2 sera converti en vecteur de dimension 3 par la méthode augmente
[Question P4.1] Avez-vous ajouté un constructeur de copie ? Pourquoi (justifiez votre choix) ?
N’ayant pas de pointeurs, nous n’avons pas la nécessité de faire une copie en profondeur. La copie de surface fournie par le constructeur de copie suffit.

## [Question P4.2] Si l'on souhaitait ajouter un constructeur par coordonnées sphériques (deux angles et une longueur) pour les vecteurs de dimension 3, 
### a.  que cela impliquerait-il au niveau des attributs de la classe ?
### b. quelle serait la difficulté majeure (voire l'impossibilité) de sa réalisation en C++ ? (C'est d'ailleurs pour cela qu'on ne vous demande pas de faire un tel constructeur !)
  
**a.**  Il faudrait rajouter un vector pour les coordonnées sphériques, car si on en utilise qu’un seul on ne pourra pas savoir si on veut faire des modification via les coordonnées sphériques ou les coordonnées polaires   

**b.**  On ne pourrait jamais savoir si l’utilisateur souhaite créer un Vecteur en coordonnées sphériques ou en coordonnées cartésienne car les 2 constructeurs auraient vraisemblablement le même prototype.
[Question P4.3] Quels opérateurs avez vous introduits ?
Nous avons introduit les opérateurs de comparaison == et !=. Les opérateurs d’addition et de soustraction de vecteur +, +=, -, -=. Les opérateurs associé à la multiplication scalaire * et *=. L’opérateur pour le produit vectoriel ^ et l’opérateur unaire ~.

## [Question P6.1] Comment avez vous conçu votre classe Integrateur ?

On a conçu la classe intégrateur pour que ce soit une super classe abstraite sans attribut, qui définit uniquement des méthodes, car essentiellement c’est tout ce dont on a besoin. On a donc la méthode virtuelle pure évolue, qui sera redéfinie dans les sous classes de la classe intégrable. En plus de ça on l’a fait hériter de la classe Printable pour que l’on puisse afficher le type d’intégrateur utilisé.  

## [Question P6.2] Quelle est la relation entre les classes Integrateur et IntegrateurEulerCromer ?  
la classe IntegrateurEulerCromer hérite de la classe Integrateur, où IntegrateurEulerCromer voit un override sur la méthode évolue la rendant donc instanciable.   

## [Question P7.1] Comment avez vous traduit le fait que la GravitationConstante est un champs de force ? 
On a fait hériter GravitationConstante de Champforce, puis toutes les méthodes de GravitationConstante qui pouvaient être utilisées dans n’importe quel Champforce, on les a mis en virtuel pure dans Champforce et on les a override dans GravitationConstante.  

## [Question P7.2] Comment cela doit-il se traduire dans votre projet ?
on a fait hériter PointMateriel de ObjetPhysique, et on fait passer toutes les méthodes pouvant être utilisées par n’importe quels ObjetPhysique de point matrériel à ObjetPhysique en des méthodes virtuelles pure/ou pas dépendant de la nécessité puis on les override dans PointMateriel.
[Question P8.1] En termes de POO, quelle est donc la nature de la méthode dessine_sur() ?
La méthode dessine_sur() est une méthode virtuelle pure.
[Question P8.2] A quoi faut-il faire attention pour les classes contenant des pointeurs ? Quelle(s) solution(s) est/sont envisageable(s) ? 
On doit faire attention aux fuites de mémoire en utilisant la règle des trois : adapter les destructeurs, constructeur de copie et opérateur d’affectation =. On peut également utiliser des unique_ptr pour éviter ce problème. C’est pour cela que nous avons décidé d’utiliser des unique_ptr dans le projet.  

## [Question P8.3] Comment représentez vous la classe Systeme ? Expliquez votre conception (attributs, interface, ...).

La classe système est consituée de plusieurs collections hérérogènes (liste de pointeurs sur des classes abstraites). Elle contien donc une liste d’objet physique, une liste de contraintes ainsi qu’une liste de champs de force. En plus de ça le système possède un intégrateur pour faire évoluer les objets physiques soumis à des forces et des contraintes imposées par les ChampForces et les Contraintes. Pour cela la classe système s’occupe aussi de la gestion du temps, pour que tous les objets dans le système évoluent dans la même temporalité. Finalement la classe système possède des méthodes d’affichage sont aussi présentent pour nous permettre d’afficher le système et ses caractéristiques (intégrateur, caractéristiques des objets/champs/forces/contraintes) à l’instant t.

## [Question P10.1] Si vous souhaitez voir un champ ou encore une contrainte, c.-à-d. la faire dessiner, comment devez vous modifier (ou pas) votre conception/votre code ?  

La conception du projet reste inchangée. En effet, il suffit de rajouter une méthode dessine qui prend un champforce ou une contrainte en argument et de la définir de la même manière que pour PointMatériel ou Systeme. Nous pouvons faire celà en utilisant la surcharge de l’opérateur << car elle  est bien définie sur les classes ChampForces ou Contraintes vu que ce sont des classes héritant de la classe Printable. Il faudrait donc créer du code nouveau mais qui suit la même logique préétablie pour dessiner les autres objets déjà dessinables. 



## [Question P12.1] Où cela s'intègre-t-il dans votre projet/conception ? Quels changements cela engendre-t-il (ou pas)   

Ces nouveaux intégrateurs s’intègrent au projet de manière similaire à la classe IntegrateurEulerCromer. Ce sont des sous classes de Integrateur qui overrident les fonctions evolue() et whoami() pour être instanciables. dans le cas de Newmark sa méthode evolue() utilise la méthode de Newmark pour intégrer, et RungeKutta4 utilise la méthode d’intégration de Runge-Kutta du quatrième ordre. Cela engendre donc très peu de nouveautés, mis à part le besoin d’utiliser le polymorphisme pour utiliser ces intégrateurs à partir d’une collection hétérogène d’intégrateurs.




