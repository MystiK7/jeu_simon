#include "pitches.h"

/* CONFIGURATION */
// LEDS
const int LED_ROUGE = 8;
const int LED_JAUNE = 9;
const int LED_VERTE = 10;
const int LED_BLEUE = 11;
// BUTTONS
const int BUTTON_ROUGE = 3;
const int BUTTON_JAUNE = 4;
const int BUTTON_VERT = 5;
const int BUTTON_BLEU = 6;
// BUZZER
const int BUZZER = 2;
// DELAI
const int delai_animation = 500;
const int delai_buzzer = 200;
const int delai_note = 1000;
// MONITEUR SERIE
String input = "";
bool demande = false;
// SEQUENCE NOTES
String sequence_jeu = "";
String sequence_joueur = "";

void setup() {
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
  // RANDOM 
  randomSeed(analogRead(0));
  // TERMINAL SERIE
  Serial.begin(9600);
}

void loop() {
  // Afficher "Niveau :" seulement une fois
  if (!demande) {
    animationDebut();
    Serial.print("Niveau : ");
    demande = true;
  }

  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {  // touche Entrée
      if (input.length() > 0) {
        int niveau = input.toInt();
        Serial.println(niveau);
        jeu(niveau);
      }
      input = "";     // reset
      sequence_jeu = "";
      demande = false; // redemander un niveau
    } else {
      input += c;  // <-- très important : on ajoute chaque caractère saisi
    }
  }
}


void animationDebut() {
  for(int i=0; i<3; i++) {
    tone(BUZZER, NOTE_C4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_D4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_E4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_F4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_G4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_A4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_B4, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(1);
    tone(BUZZER, NOTE_C5, 200);
    toutesLeds(0);
    delay(delai_animation);
    toutesLeds(0);
  }
  for(int i=0; i<5; i++) {
    toutesLeds(0);
    delay(500);
    toutesLeds(1);
    delay(500);
  }
  toutesLeds(0);
}

void jeu(int niveau) {
  switch (niveau) {
    case 1:
      for(int i=0; i<8; i++) 
        jouer_couleur();
      Serial.println("Séquence jeu : " + sequence_jeu);
      for(int j=0; j<8; j++)
        tour_joueur();
      Serial.println("Séquence joueur : " + sequence_joueur);
      break;
    case 2:
      for(int i=0; i<14; i++)
        jouer_couleur();
      break;
    case 3:
      for(int i=0; i<20; i++)
        jouer_couleur();
      break;
    case 4:
      for(int i=0; i<31; i++)
        jouer_couleur();
      break;
    default:
      break;
    delay(10000);
  }
}

String jouer_couleur() {
  int random_couleur = random(4);
    if(random_couleur == 0)
      rouge();
    else if (random_couleur == 1) 
      jaune();
    else if (random_couleur == 2)
      vert();
    else
      bleu();
    return sequence_jeu += char('0' + random_couleur);
}

String tour_joueur() {
  int bouton = lireBouton();
  Serial.println("bouton = " + String(bouton)); // Correction : conversion de bouton en String
  switch (bouton) {
    case 0: rouge(); sequence_joueur += '0'; break;
    case 1: jaune(); sequence_joueur += '1'; break;
    case 2: vert(); sequence_joueur += '2'; break;
    case 3: bleu(); sequence_joueur += '3'; break;
  }
  return sequence_joueur;
}

int lireBouton() {
  int resultatBouton = -1; // Valeur initiale invalide
  while (resultatBouton == -1) {
    // Lire l'état de tous les boutons
    int etatRouge = digitalRead(BUTTON_ROUGE);
    int etatJaune = digitalRead(BUTTON_JAUNE);
    int etatVert = digitalRead(BUTTON_VERT);
    int etatBleu = digitalRead(BUTTON_BLEU);
    Serial.println("rouge = " + String(etatRouge));
    Serial.println("jaune = " + String(etatJaune));
    Serial.println("vert = " + String(etatVert));
    Serial.println("bleu = " + String(etatBleu));


    // Vérifier chaque bouton avec anti-rebond
    if (etatRouge == LOW) {
      delay(50); // Attendre 50ms
      if (digitalRead(BUTTON_ROUGE) == LOW) { // Confirmer l'appui
        resultatBouton = 0;
        while (digitalRead(BUTTON_ROUGE) == LOW); // Attendre le relâchement
      }
    }
    if (etatJaune == LOW) {
      delay(50);
      if (digitalRead(BUTTON_JAUNE) == LOW) {
        resultatBouton = 1;
        while (digitalRead(BUTTON_JAUNE) == LOW);
      }
    }
    if (etatVert == LOW) {
      delay(50);
      if (digitalRead(BUTTON_VERT) == LOW) {
        resultatBouton = 2;
        while (digitalRead(BUTTON_VERT) == LOW);
      }
    }
    if (etatBleu == LOW) {
      delay(50);
      if (digitalRead(BUTTON_BLEU) == LOW) {
        resultatBouton = 3;
        while (digitalRead(BUTTON_BLEU) == LOW);
      }
    }
    delay(10); // Délai pour éviter de saturer le microcontrôleur
  }
  return resultatBouton;
}

void toutesLeds(int etat) {
  if(etat == 0) {
    digitalWrite(LED_ROUGE, LOW);
    digitalWrite(LED_JAUNE, LOW);
    digitalWrite(LED_VERTE, LOW);
    digitalWrite(LED_BLEUE, LOW);
  }
  else {
    digitalWrite(LED_ROUGE, HIGH);
    digitalWrite(LED_JAUNE, HIGH);
    digitalWrite(LED_VERTE, HIGH);
    digitalWrite(LED_BLEUE, HIGH);
  }
}

void rouge() {
  digitalWrite(LED_ROUGE, HIGH);
  tone(BUZZER, NOTE_C4, delai_buzzer); // DO
  digitalWrite(LED_ROUGE, LOW);
  delay(delai_note);
}

void jaune() {
  digitalWrite(LED_JAUNE, HIGH);
  tone(BUZZER, NOTE_E4, delai_buzzer); // MI
  digitalWrite(LED_JAUNE, LOW);
  delay(delai_note);
}

void vert() {
  digitalWrite(LED_VERTE, HIGH);
  tone(BUZZER, NOTE_G4, delai_buzzer); // SOL
  digitalWrite(LED_VERTE, LOW);
  delay(delai_note);
}

void bleu() {
  digitalWrite(LED_BLEUE, HIGH);
  tone(BUZZER, NOTE_G4, delai_buzzer); // SI
  digitalWrite(LED_BLEUE, LOW);
  delay(delai_note);
}

