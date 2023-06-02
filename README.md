# Projet de LIFAPCD, printemps 2023.
Travail de groupe réalisé en C++ en deuxième année de prépa.

Il s'agit d'un jeu de plateforme vu de côté. L'objectif est de s'enfuir dans un temps limité en évitant les ennemis (rats et araignées) et les obstacles (barbelés).

Plusieurs niveaux de difficultés sont proposés en début de partie (facile, moyen, difficile).


## Participants :
- [ARNAUD Ivan](https://github.com/IvanSonCode)
- [THOMAS Virginie](https://github.com/jrivvv)
- [TONNIS Dorian](https://github.com/Dorian-T)


## Manuel

### Prérequis :
Il faut au préalable avoir installé la bibliothèque SFML avec la commande : `sudo apt-get install libsfml-dev`.

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

### Contrôles :
- Z : haut
- Q : gauche
- S : bas
- D : droite
