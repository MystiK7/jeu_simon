#include "setup.h"
#include "led.h"
#include "jeu.h"


void setup() {
  setup_config();

}

void loop() {
  lancer_jeu();
}


// void loop() {
//   // Afficher "Niveau :" seulement une fois
//   if (!demande) {
//     animationDebut();
//     Serial.print("Niveau : ");
//     demande = true;
//   }

//   if (Serial.available()) {
//     char c = Serial.read();
//     if (c == '\n' || c == '\r') {  // touche Entrée
//       if (input.length() > 0) {
//         int niveau = input.toInt();
//         Serial.println(niveau);
//         jeu(niveau);
//       }
//       input = "";     // reset
//       sequence_jeu = "";
//       demande = false; // redemander un niveau
//     } else {
//       input += c;  // <-- très important : on ajoute chaque caractère saisi
//     }
//   }
// }


// void animationDebut() {
//   for(int i=0; i<3; i++) {
//     tone(BUZZER, NOTE_C4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_D4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_E4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_F4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_G4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_A4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_B4, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(1);
//     tone(BUZZER, NOTE_C5, 200);
//     toutesLeds(0);
//     delay(delai_animation);
//     toutesLeds(0);
//   }
//   for(int i=0; i<5; i++) {
//     toutesLeds(0);
//     delay(500);
//     toutesLeds(1);
//     delay(500);
//   }
//   toutesLeds(0);
// }

// void jeu(int niveau) {
//   switch (niveau) {
//     case 1:
//       for(int i=0; i<8; i++) 
//         jouer_couleur();
//       Serial.println("Séquence jeu : " + sequence_jeu);
//       for(int j=0; j<8; j++)
//         tour_joueur();
//       Serial.println("Séquence joueur : " + sequence_joueur);
//       break;
//     case 2:
//       for(int i=0; i<14; i++)
//         jouer_couleur();
//       break;
//     case 3:
//       for(int i=0; i<20; i++)
//         jouer_couleur();
//       break;
//     case 4:
//       for(int i=0; i<31; i++)
//         jouer_couleur();
//       break;
//     default:
//       break;
//     delay(10000);
//   }
// }

// String jouer_couleur() {
//   int random_couleur = random(4);
//     if(random_couleur == 0)
//       rouge();
//     else if (random_couleur == 1) 
//       jaune();
//     else if (random_couleur == 2)
//       vert();
//     else
//       bleu();
//     return sequence_jeu += char('0' + random_couleur);
// }

// String tour_joueur() {
//   int bouton = lireBouton();
//   Serial.println("bouton = " + String(bouton)); // Correction : conversion de bouton en String
//   switch (bouton) {
//     case 0: rouge(); sequence_joueur += '0'; break;
//     case 1: jaune(); sequence_joueur += '1'; break;
//     case 2: vert(); sequence_joueur += '2'; break;
//     case 3: bleu(); sequence_joueur += '3'; break;
//   }
//   return sequence_joueur;
// }

// int lireBouton() {
//   int resultatBouton = -1; // Valeur initiale invalide
//   while (resultatBouton == -1) {
//     // Lire l'état de tous les boutons
//     int etatRouge = digitalRead(BUTTON_ROUGE);
//     int etatJaune = digitalRead(BUTTON_JAUNE);
//     int etatVert = digitalRead(BUTTON_VERT);
//     int etatBleu = digitalRead(BUTTON_BLEU);
//     Serial.println("rouge = " + String(etatRouge));
//     Serial.println("jaune = " + String(etatJaune));
//     Serial.println("vert = " + String(etatVert));
//     Serial.println("bleu = " + String(etatBleu));


//     // Vérifier chaque bouton avec anti-rebond
//     if (etatRouge == LOW) {
//       delay(50); // Attendre 50ms
//       if (digitalRead(BUTTON_ROUGE) == LOW) { // Confirmer l'appui
//         resultatBouton = 0;
//         while (digitalRead(BUTTON_ROUGE) == LOW); // Attendre le relâchement
//       }
//     }
//     if (etatJaune == LOW) {
//       delay(50);
//       if (digitalRead(BUTTON_JAUNE) == LOW) {
//         resultatBouton = 1;
//         while (digitalRead(BUTTON_JAUNE) == LOW);
//       }
//     }
//     if (etatVert == LOW) {
//       delay(50);
//       if (digitalRead(BUTTON_VERT) == LOW) {
//         resultatBouton = 2;
//         while (digitalRead(BUTTON_VERT) == LOW);
//       }
//     }
//     if (etatBleu == LOW) {
//       delay(50);
//       if (digitalRead(BUTTON_BLEU) == LOW) {
//         resultatBouton = 3;
//         while (digitalRead(BUTTON_BLEU) == LOW);
//       }
//     }
//     delay(10); // Délai pour éviter de saturer le microcontrôleur
//   }
//   return resultatBouton;
// }




