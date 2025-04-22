# Depths Delve PROJECT

## Description
Ce projet est un jeu vidéo 2D en vue isonométrique dans lequel l'objectif est d'explorer des grottes afin de trouver et récolter des gisements de minerais, tout en combattant les ennemis qui peuplent les souterrains.
Ce projet utilise la bibliothèque SFML pour l'affichage.

### Utilisation
---
1. Depuis un terminal, dirigez vous dans le dossier build et entrez la commande `cmake ..`
```
cd depths-delve-project
cd build
cmake ..
```
2. Pour exécuter, depuis le dossier build, entrez ensuite :
```
../bin/DepthDelve
```

### Comment jouer
---
Au lancement du jeu, le menu s'affiche.
Dans le menu, vous pouvez appuyer sur C pour charger une partie sauvegardée. Appuyez ensuite sur entrée pour lancer une partie.

Utilisez les touches ZQSD pour vous déplacer respectivement en haut, à gauche, en bas et à droite. Équipez ou déséquipez la pioche avec la touche ctrl gauche et empruntez les échelles avec la touche E. La touche Echap permet d'ouvrir l'inventaire et la touche C permet de charger la dernière partie sauvegardée si l'on se trouve au menu de démarrage et sinon, de sauvegarder l'état de la partie en cours.

### Doxygen
---
Depuis le dossier parent, entrer la commande suivante afin de lancer la documentation générée par Doxygen :
```
firefox doc/html/index.html
```

### Organisation de l'archive
---
* `assets` : Contient les sprites
* `bin` : Contient l'éxecutable
* `doc` : Documentation de doxygen
* `src` : Contient les fichiers sources (.h et .cpp)

### Membres
---
[BEN AMMAR RAYEN - p2210996](https://forge.univ-lyon1.fr/p2210996)
[BOUVIER LORIS - p2204514](https://forge.univ-lyon1.fr/p2204514)





