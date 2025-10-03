#include "WString.h"
#include "HardwareSerial.h"
#include "setup.h"
#include "jeu.h"

int notes_niveaux[4] = {
  NB_NOTES_NIVEAU_1,
  NB_NOTES_NIVEAU_2,
  NB_NOTES_NIVEAU_3,
  NB_NOTES_NIVEAU_4
};

int niveau_courant, score = 0;

bool jeu(int niveau) {
  int index = niveau - 1; // tableau commence à 0
  tour(notes_niveaux[index]);
  if (gagner_ou_perdu()) {
    notes_niveaux[index] += 1;
    return true;
  } else {
    // reset sur la valeur de départ
    if (niveau == 1) notes_niveaux[index] = NB_NOTES_NIVEAU_1;
    if (niveau == 2) notes_niveaux[index] = NB_NOTES_NIVEAU_2; 
    if (niveau == 3) notes_niveaux[index] = NB_NOTES_NIVEAU_3; 
    if (niveau == 4) notes_niveaux[index] = NB_NOTES_NIVEAU_4;
    return false;
  }
  delay(1000);
}


void tour(int nb_notes) {
  Serial.println("Nombre de notes à mémoriser : " + String(nb_notes));
  for(int i=0; i<nb_notes; i++) 
    jouer_couleur();
  // Serial.println("Séquence jeu : " + sequence_jeu);
  Serial.println("A vous de jouer !");
  while(sequence_joueur.length() < sequence_jeu.length())
    tour_joueur();
  // Serial.println("Séquence joueur : " + sequence_joueur);
}

bool gagner_ou_perdu() {
  if(sequence_jeu == sequence_joueur) {
    Serial.println("Séquence correcte !");
    return true;
  }
  Serial.println("Séquence incorrecte.");  
  return false;
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
  // ROUGE
  int etat = digitalRead(BUTTON_ROUGE);
  if (etat == LOW && dernierEtatRouge == HIGH) { // transition
    rouge();
    sequence_joueur += '0';
    Serial.println("Appui ROUGE détecté");
  }
  dernierEtatRouge = etat;

  // JAUNE
  etat = digitalRead(BUTTON_JAUNE);
  if (etat == LOW && dernierEtatJaune == HIGH) {
    jaune();
    sequence_joueur += '1';
    Serial.println("Appui JAUNE détecté");
  }
  dernierEtatJaune = etat;

  // VERT
  etat = digitalRead(BUTTON_VERT);
  if (etat == LOW && dernierEtatVert == HIGH) {
    vert();
    sequence_joueur += '2';
    Serial.println("Appui VERT détecté");
  }
  dernierEtatVert = etat;

  // BLEU
  etat = digitalRead(BUTTON_BLEU);
  if (etat == LOW && dernierEtatBleu == HIGH) {
    bleu();
    sequence_joueur += '3';
    Serial.println("Appui BLEU détecté");
  }
  dernierEtatBleu = etat;

  return sequence_joueur;
}



void lancer_jeu() {
  // Si aucun niveau sélectionné -> demander au joueur
  if (niveau_courant == 0 && !demande) {
    Serial.print("Niveau : ");
    demande = true;
  }

  // Lire entrée utilisateur UNIQUEMENT si on doit choisir un niveau
  if (niveau_courant == 0 && Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {  
      if (input.length() > 0) {
        niveau_courant = input.toInt(); // on mémorise le niveau choisi
        Serial.println(niveau_courant);
      }
      input = "";
      demande = false; 
    } else {
      input += c;
    }
  }

  // Si un niveau est sélectionné -> on joue
  if (niveau_courant > 0) {
    bool resultat = jeu(niveau_courant);
    if (resultat) {
      score += 1;
      Serial.println("GAGNE ! Score : " + String(score));
    }
    else {  
      // si perdu -> reset et on redemande
      niveau_courant = 0;
      score = 0;
      Serial.println("PERDU ! Score : " + String(score));
      animationPerdu();
    }
  }
  sequence_jeu = "";
  sequence_joueur = "";
}

void animationGagne() {
  for(int i=0; i<3; i++) {
    toutesLeds(1);
    delay(200);
    toutesLeds(0);
    delay(200);
  }
  tone(BUZZER, NOTE_C5, 1000);
}

void animationPerdu() {
  tone(BUZZER, NOTE_C4, DELAI_BUZZER);
  tone(BUZZER, NOTE_G4, DELAI_BUZZER);
  tone(BUZZER, NOTE_B5, DELAI_BUZZER);
  for(int i=0; i<5; i++) {
    toutesLeds(1);
    delay(200);
    toutesLeds(0);
    delay(200);
  }
  tone(BUZZER, NOTE_C5, 1000);
}