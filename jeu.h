#ifndef JEU_H
#define JEU_H

// --- HEADERS ---
#include "pitches.h"
#include "setup.h"
#include "led.h"
#include <Arduino.h>

// --- FONCTIONS ---
bool jeu(int niveau);
String jouer_couleur();
String tour_joueur();
void tour(int nb_notes);
bool gagner_ou_perdu();
void lancer_jeu();
void animationGagne();
void animationPerdu();

#endif