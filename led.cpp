#include "led.h"

void rouge() {
  digitalWrite(LED_ROUGE, HIGH);
  tone(BUZZER, NOTE_C4, DELAI_BUZZER); // DO
  digitalWrite(LED_ROUGE, LOW);
  delay(DELAI_NOTE);
}

void jaune() {
  digitalWrite(LED_JAUNE, HIGH);
  tone(BUZZER, NOTE_E4, DELAI_BUZZER); // MI
  digitalWrite(LED_JAUNE, LOW);
  delay(DELAI_NOTE);
}

void vert() {
  digitalWrite(LED_VERTE, HIGH);
  tone(BUZZER, NOTE_G4, DELAI_BUZZER); // SOL
  digitalWrite(LED_VERTE, LOW);
  delay(DELAI_NOTE);
}

void bleu() {
  digitalWrite(LED_BLEUE, HIGH);
  tone(BUZZER, NOTE_G4, DELAI_BUZZER); // SI
  digitalWrite(LED_BLEUE, LOW);
  delay(DELAI_NOTE);
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