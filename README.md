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
### Commandes d'éxecution :
- ensemble des tests de non-regression : `bin/test`
- version texte : `bin/mainTxt`
- version graphique : `bin/mainSFML`
### Commandes de nettoyage :
- supprimer les fichiers objets : `make clean`
- supprimer les fichiers objets et l'exécutable : `make veryclean`
### Commandes de documentation :
`make doc`

## Règles du jeu
Il s'agit d'un jeu de plateforme vu de côté. L'objectif est de s'enfuir dans un temps limité en évitant les ennemis (rats et araignées) et les obstacles (barbelés).
Plusieurs niveaux de difficultés sont proposés en début de partie (facile, moyen, difficile).
### Contrôles :
- Z -> haut
- S : bas
- Q : gauche
- D : droite

## Fonctionnalités du programme
...

## Organisation de l'archive
- bin : contient les exécutables
- data : contient les données
    - fonts : contient les polices de caractères
    - rooms : contient les fichiers des niveaux
    - textures : contient les images des textures
- doc : contient la documentation
- obj : contient les fichiers objets
- src : contient les fichiers sources
    - core : contient les fichiers sources du moteur du jeu
        - building : contient les fichiers sources des niveaux
        - entity : contient les fichiers sources des entités
    - sfml : contient les fichiers sources de l'interface graphique
    - txt : contient les fichiers sources de l'interface texte