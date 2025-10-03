#ifndef LED_H
#define LED_H

// --- HEADERS ---
#include "pitches.h"
#include "setup.h"
#include <Arduino.h>

// --- FONCTIONS ---
void rouge();
void jaune();
void vert();
void bleu();
void toutesLeds(int etat);

#endif