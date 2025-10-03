#include "setup.h"

// --- DEFINITIONS DES VARIABLES GLOBALES ---
String input = "";
bool demande = false;
String sequence_jeu = "";
String sequence_joueur = "";
bool dernierEtatRouge = digitalRead(BUTTON_ROUGE);
bool dernierEtatJaune = digitalRead(BUTTON_JAUNE);
bool dernierEtatVert  = digitalRead(BUTTON_VERT);
bool dernierEtatBleu  = digitalRead(BUTTON_BLEU);

void setup_config() {
  // LEDS
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_JAUNE, OUTPUT);
  pinMode(LED_VERTE, OUTPUT);
  pinMode(LED_BLEUE, OUTPUT);
  // BUTTONS
  pinMode(BUTTON_ROUGE, INPUT_PULLUP);
  pinMode(BUTTON_JAUNE, INPUT_PULLUP);
  pinMode(BUTTON_VERT, INPUT_PULLUP);
  pinMode(BUTTON_BLEU, INPUT_PULLUP);
  // BUZZER
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER, NOTE_C4, 200);
  // RANDOM 
  randomSeed(analogRead(0));
  // TERMINAL SERIE
  Serial.begin(9600);
  // ANIMATION DEBUT
  animationDebut();
}

void boutonActiveLed(int bouton, int led) {
  int etatButton = digitalRead(bouton);
  if(etatButton == HIGH)
    digitalWrite(led, HIGH);
  else
   digitalWrite(led, LOW);
  delay(10);
}

void animationDebut() {
  for(int i=0; i<5; i++) {
    tone(BUZZER, NOTE_C4, 200);
    toutesLeds(1);
    delay(DELAI_ANIMATION);
    toutesLeds(0);
    delay(DELAI_ANIMATION);
  }
}