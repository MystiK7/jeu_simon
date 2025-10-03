# Jeu "Simon" sur Ardunio

Reproduction du jeu "Simon" avec une carte Arduino en guise d'entraînement.

Matériel nécessaire :
- 4 LEDs avec 4 résistances 220 ohms
- 4 boutons poussoirs avec 4 résistances 10k/20k ohms
- 1 buzzer avec 1 résistance 220 ohms
- Fils de cablâge

Une photo du cablâge est disponible dans le dossier au besoin.

## Fonctionnement du jeu

Le jeu "Simon" consiste à devoir mémoriser une suite de notes jouée aléatoirement puis la rejouer ensuite à l'identique en appuyant sur les boutons poussoirs.

Si la séquence jouée est exacte, le jeu continue et une nouvelle séquence est rejouée avec une note en plus. Le score du joueur augmente de 1.
Si la séquence jouée est incorrecte, le jeu s'arrête et revient au menu principal. Le score redescend à 0.

Il y a 4 niveaux de difficultés :
- Niveau 1 : 8 notes jouées
- Niveau 2 : 14 notes jouées
- Niveau 3 : 20 notes jouées
- Niveau 4 : 31 notes jouées

Lorsque l'animation de début se termine, ouvrez le moniteur série en 9600 bauds.
Saisissez ensuite le niveau auquel vous voulez jouer (1, 2, 3 ou 4). 
Une fois saisi, le jeu démarre.

Amusez-vous !
