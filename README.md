# Projet de LIFAPCD, printemps 2023.

## Informations
### participants :
- ARNAUD Ivan p2101554
- THOMAS Virginie p2101474
- TONNIS Dorian p2104276
### ID du projet sur la forge :
[27905](https://forge.univ-lyon1.fr/p2104276/pedalo)

## Manuel
### Prérequis :
il faut au préalable avoir installé la bibliothèque SFML avec la commande : `sudo apt-get install libsfml-dev`
### Commandes de compilation :
`make`
### Commande d'éxecution :
- ensemble des tests de non-regression : `bin/test`
- version texte : `bin/mainTxt`
- version graphique : `bin/mainSFML`
### Commandes de nettoyage :
- supprimer les fichiers objets : `make clean`
- supprimer les fichiers objets et l'exécutable : `make veryclean`
### Commande de documentation :
`make doc`

## Règles du jeu
Il s'agit d'un jeu de plateforme vu de côté. L'objectif est de s'enfuir dans un temps limité en évitant les ennemis (rats et araignées) et les obstacles (barbelés).
Plusieurs niveaux de difficultés sont proposés en début de partie (facile, moyen, difficile).
### Contrôles :
- Z : haut
- Q : gauche
- S : bas
- D : droite

## Fonctionnalités du programme
- Différentes manières de perdre :
	- en n'ayant plus de points de vie à force de toucher des ennemis ou des obstacles
	- en n'ayant plus de temps
- Différents ennemis :
	- les rats : ils se déplacent de manière aléatoire jusqu'à ce qu'un joueur s'apporche d'eux, ils se mettent alors à le suivre
	- les araignées : elles se déplacent de haut en bas
- Différents obstacles :
	- les barbelés : ils font perdre des points de vie au joueur s'il les touche
	- les blocs : ce sont à la fois les murs et le sol
	- les faux blocs : ils ont l'apparence d'un block mais on peut passer à travers
	- les blocs fantômes : ce sont des sols qui disparraissent quand le joueur est dessus
	- les portes : elles permettent de passer d'un niveau à l'autre
	- les échelles : elles permettent de monter ou descendre
	- les trappes : elles permettent de monter ou descendre mais on peut également marcher dessus
	- les potions : elles rajoutent un peu de temps avant le game over
- Différentes salles :
	- la salle d'entrée
	- les salles intermédiaires qui sont générées aléatoirement
	- la salle de sortie
- Différents niveaux de difficulté :
	- facile : 3 salles intermédiaires, 5 coeur et 2 fois le temps minimal par salle
	- moyen : 5 salles intermédiaires, 3 coeur et 1,5 fois le temps minimal par salle
	- difficile : 8 salles intermédiaires, 1 coeur et le temps minimal par salle

## Organisation de l'archive
- bin : contient les exécutables
- data : contient les données
	- fonts : contient les polices de caractères
	- rooms : contient les fichiers des niveaux au format .txt
	- textures : contient les images des textures
- doc : contient la documentation
- obj : contient les fichiers objets
- src : contient les fichiers sources
	- core : contient les fichiers sources du moteur du jeu
		- building : contient les fichiers sources des niveaux
		- entity : contient les fichiers sources des entités
	- sfml : contient les fichiers sources de l'interface graphique
	- txt : contient les fichiers sources de l'interface texte