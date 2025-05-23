
<br/>
<p align="center">
  <img src="assets/captures/logo.png" alt="Logo Depth Delve" width="450"/>
</p>

<br/>

> *Explorez les profondeurs. Survivez à l’enfer. Récupérez des trésors oubliés.*

Bienvenue à **HeavenlydeepHell**, une ville bâtie sur des mines aussi riches que mortelles. Dans cet univers souterrain infesté de créatures hostiles et de pièges, vous incarnez un jeune mineur prêt à braver les ténèbres pour découvrir les plus précieux minerais.

---

## 🎮 À propos du jeu

**Depth Delve** est un jeu vidéo 2D en vue **axonométrique**, développé en **C++** avec la bibliothèque **SFML**. Vous devez explorer des grottes générées aléatoirement, combattre des monstres, éviter les pièges, et collecter un maximum de ressources avant que vos cœurs ne s’épuisent.

---

## 🧭 Objectifs

- Descendre les différents étages via des portes ou des échelles
- Revenir aux niveaux précédents si nécessaire
- Récupérer les minerais les plus rares
- Survivre le plus longtemps possible

---

## 📦 Fonctionnalités

- 🧱 Étages générés de manière **aléatoire**
- 👾 Ennemis à affronter avec une **pioche**
- 💎 Système de **ressources** à collecter
- 🧭 **Missions** à remplir pour vos supérieurs
- 📦 **Inventaire** avec minerais, stats et informations

---

## 🕹️ Commandes du jeu

| Action                      | Touche                |
|----------------------------|-----------------------|
| Se déplacer                | ZQSD                  |
| Utiliser une échelle       | E                     |
| Ouvrir l’inventaire        | Échap                 |
| Équiper/Déséquiper la pioche | Ctrl gauche         |
| Sauvegarder / Charger      | C                     |
| Lancer une partie          | Entrée (depuis menu)  |

---

## 🎬 Aperçus visuels

### 📌 Vue du menu principal  
![Vue du menu principal](assets/captures/menu.png)

### 📌 Exploration d’un étage avec ennemis  
![Exploration d’un étage avec ennemis](assets/captures/exploration.png)

### 📌 Inventaire avec les ressources collectées  
![Inventaire avec les ressources collectées](assets/captures/inventaire.png)

### 📌 Combat contre une créature souterraine  
![Combat contre une créature souterraine](assets/captures/combat.png)

### 📌 Scène de minage avec la pioche  
![Scène de minage](assets/captures/minage.png)

---

## 🛠️ Installation

1. Assurez-vous d’avoir installé **CMake** et **SFML** sur votre système.
2. Depuis un terminal, exécutez les commandes suivantes :
   ```bash
   cd Depth-Delve/build
   cmake ..
   make
   ```

---

## ▶️ Lancement

Une fois la compilation terminée, exécutez le jeu avec :
```bash
../bin/DepthDelve
```

---
## 📁 Arborescence du projet

```
Depth-Delve/
├── assets/              # Ressources du jeu (images, sons, etc.)
│   ├── captures/        # Captures d’écran pour la documentation 
│   └── sauvegardes/     # Fichier de sauvegarde de partie
├── bin/                 # Exécutable compilé du jeu
├── build/               # Dossier de compilation (généré par CMake)
├── doc/                 # Documentation du code visible dans index.html
├── src/                 # Code source du jeu en C++
├── CMakeLists.txt       # Script de configuration pour CMake
└── README.md            # Présentation et explication du projet
```


---

## 🔧 Technologies utilisées

- C++
- [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
- CMake

---

## ⚙️ Contraintes techniques et choix de développement

Le développement de **Depth Delve** s’est fait avec une approche volontairement bas niveau :

- 🔄 **Séparation claire entre l’IHM et le modèle** : la logique du jeu est indépendante de l’affichage, pour un code plus propre et modulaire.
- 🧵 **Programmation en C++ natif** : sans outils modernes complexes, afin de mieux maîtriser les bases du langage et la gestion mémoire.
- 🧱 **Utilisation minimale de SFML** : seules les fonctionnalités essentielles ont été utilisées. Le reste (rendu, collisions, inventaire, etc.) a été codé à la main pour apprendre à tout construire soi-même.

Ce projet m’a permis de mieux comprendre les fondations d’un moteur de jeu simple et les défis du développement bas niveau.

---

## 👥 Contributeurs

| Nom                  | Rôle                                             |
|----------------------|--------------------------------------------------|
| **Rayen Ben Ammar**  | Modélisation du jeu, implémentation complète en C++ |
| **Loris Bouvier**    | Création des sprites, documentation du code      |
