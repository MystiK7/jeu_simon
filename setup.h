#ifndef SETUP_H
#define SETUP_H

// --- HEADERS ---
#include "pitches.h"
#include "led.h"
#include <Arduino.h>

// --- LEDS ---
#define LED_ROUGE 8
#define LED_JAUNE 9
#define LED_VERTE 10
#define LED_BLEUE 11

// --- BUTTONS ---
#define BUTTON_ROUGE 3
#define BUTTON_JAUNE 4
#define BUTTON_VERT 5
#define BUTTON_BLEU 6

// --- BUZZER ---
#define BUZZER 2

// --- DELAIS ---
#define DELAI_ANIMATION 500
#define DELAI_BUZZER 200
#define DELAI_NOTE 1000

// --- NOTES NIVEAU ---
#define NB_NOTES_NIVEAU_1 8
#define NB_NOTES_NIVEAU_2 14
#define NB_NOTES_NIVEAU_3 20
#define NB_NOTES_NIVEAU_4 31

// --- VARIABLES GLOBALES ---
extern String input;
extern bool demande;
extern String sequence_jeu;
extern String sequence_joueur;
extern bool dernierEtatRouge;
extern bool dernierEtatJaune;
extern bool dernierEtatVert;
extern bool dernierEtatBleu;

// --- FONCTIONS ---
void setup_config();
void boutonActiveLed(int bouton, int led);
void animationDebut();

#endif
