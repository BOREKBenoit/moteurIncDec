/* 
  Commande MLI d'un moteur avec alimentation +15V
  
  Programme basique sur Arduino Mega
  IDE Visual Studio Code 1.95.2
  
  Constituants :
  -  PCB
  -  Moteur +15V

  Version 1 : 13/11/2024

  Benoit BOREK
  */


#include <Arduino.h> // Inclusion de la bibliothèque Arduino pour avoir les fonctions de base.

// Variables pour pouvoir changer les couleurs de la LED RGB du PCB.
int const red = 6;  
int const green = 7;
int const blue = 5;

// Variables pour pouvoir recevoir l'information d'incrémentation et de décrémentation.
int const inc = 3;
int const dec = 2;

// Variable pour commander le transistor et donc le moteur indirectement.
int const mli = 4;

// Variable du "curseur" c'est à dire :
// si il est à 0 alors le moteur tournera à 0%
// si il est à 1 alors le moteur tournera à 25%
// etc...
int curseur = 0; // Je met sa valeur par défaut à 0 pour que ce soit confortable.

void setup() {
// Déclaration des variables de la LED RGB en tant que PIN de l'Arduino.
// Les PINS seront en OUTPUT pour dire que l'Arduino sera prêt à envoyer du courant dans ces PINS.
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

// Déclaration des variables d'incrémentation et de décrémentation en tant que PIN de l'Arduino.
// Ces PINS sont en INPUT ce qui veut dire que l'Arduino sera prêt à recevoir du courant des ces PINS.
pinMode(inc, INPUT);
pinMode(dec, INPUT);

  Serial.begin(9600); // Initialisation de la liaison Arduino <----> PC.
}

void loop() {


  if (digitalRead(inc) == HIGH) // Condition si j'appuie sur le bouton incrémentation alors le curseur va s'incrémenter de 1.
  {
    curseur = curseur + 1; // Incrémentation du curseur.

     if(curseur > 4) { // Condition de sécurité, si j'incrémente et que le curseur est supérieur à 4 (valeur max).
                       // Alors je remet la valeur du curseur à 4.
      curseur = 4;
    }
  }

  if (digitalRead(dec) == LOW) // Même chose mais pour le bouton décrémentation.
                               // Si j'appuie sur le bouton de décrémentation alors le curseur va se décrémenter de 1.
  {
    curseur = curseur - 1;
    if(curseur < 0) { // Condition de sécurité qui permet de ne pas avoir un valeur de curseur négatif.
      curseur = 0;
    }
  }
  

  if(curseur == 0) {
    analogWrite(green, 255);
  }

  if(curseur == 1) {
    analogWrite(green, 0);
    analogWrite(red, 255);
  }

  




}

