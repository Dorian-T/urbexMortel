# Projet de LIFAPCD, printemps 2023.

## Informations :
### participants :
- ARNAUD Ivan p2101554
- THOMAS Virginie p2101474
- TONNIS Dorian p2104276
### ID du projet sur la forge :
27905

## Manuel :
### Prérequis :
il faut au préalable avoir installé la bibliothèque SFML avec la commande : `sudo apt-get install libsfml-dev`
### Commandes de compilation :
`make`
### Commandes d'éxecution :
- ensemble des tests de non-regression : `bin/test`
- version texte : `bin/mainTxt`
- version graphique : `bin/mainSFML`
### Commandes de nettoyage :
- supprimer les fichiers objets : `make clean`
- supprimer les fichiers objets et l'exécutable : `make veryclean`
### Commandes de documentation :
`make doc`

règles du jeu : il s'agit d'un jeu de plateforme vu de côté. 
l'objectif est de s'enfuir dans un temps limité en évitant les ennemis (rats et araignées) et les obstacles (barbelés)
Plusieurs niveaux de difficultés sont possibles (facile, moyen, difficile)
contrôles -> haut : Z, bas : S, gauche : Q, droite : D

fonctionnalités du programme

organisation de l'archive


Le jeu est développé en C++. Il est jouable dans le terminal et une interface graphique est développé avec la bibliothèque SFML.


    un manuel : commandes de compilation et d'exécution, règles du jeu ou utilisation de l'application, la liste des fonctionnalités du programme
    une description de l'organisation de votre archive