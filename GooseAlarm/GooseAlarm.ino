/***************************************************
 * Goose Alarm
 * 
 * Unit test experiment to see if PIR sensor tower
 * would be reliable in detecting 360 degrees of 
 * heat motion for the goose alarm project.
 * 
 * Author: Aidan Fadool
 * 06/16/2021
 * 
 **************************************************/
#include "pitches.h"

#define PIR1_PIN 2
#define PIR2_PIN 3
#define PIR3_PIN 4

#define LED1_PIN 5
#define LED2_PIN 6
#define LED3_PIN 7

#define BUZZ_PIN 8
int pir1, pir2, pir3 = 0;
bool buzzer =  false;

void setup() {
  // Set pinmodes
  pinMode(PIR1_PIN, INPUT);
  pinMode(PIR2_PIN, INPUT);
  pinMode(PIR3_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  // Set initial output states
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);

  Serial.begin(9600);
}

void loop() {
  // Read the pir outputs
  pir1 = digitalRead(PIR1_PIN);
  pir2 = digitalRead(PIR2_PIN);
  pir3 = digitalRead(PIR3_PIN);

  // Logic for pir states 
  if (pir1 == HIGH) {
    digitalWrite(LED1_PIN, HIGH);
  } else {
    digitalWrite(LED1_PIN, LOW);
  }

  if (pir2 == HIGH) {
    digitalWrite(LED2_PIN, HIGH);
  } else {
    digitalWrite(LED2_PIN, LOW);
  }

  if (pir3 == HIGH) {
    digitalWrite(LED3_PIN, HIGH);
  } else {
    digitalWrite(LED3_PIN, LOW);
  }

  if (pir1 == HIGH || pir2 == HIGH || pir3 == HIGH) {
    buzzer = true;
  } else {
    buzzer = false;
  }

  if (buzzer == true) {
    tone(BUZZ_PIN, NOTE_A3, 20);
  }

  Serial.print(pir1);
  Serial.print(", ");
  Serial.print(pir2);
  Serial.print(", ");
  Serial.println(pir3);
//  delay(100);

}
