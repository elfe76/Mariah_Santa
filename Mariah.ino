#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <AudioFileSourceSD.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2S.h>

// Broches SD
#define SD_CS_PIN 5

// Broches I2S
#define I2S_BCLK 26
#define I2S_LRC 25
#define I2S_DOUT 22

// Broches LED, MOSFET et bouton
#define LED_PIN 2
#define MOSFET_PIN 15
#define BUTTON_PIN 4

// Gestion audio
AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;

// Variables pour la gestion de l'état
bool isPlaying = false;      // Indique si la lecture est en cours
bool lastButtonState = HIGH; // État précédent du bouton

void setup() {
  Serial.begin(115200);
  Serial.println("Démarrage de l'ESP32...");

  // Configuration des broches LED et MOSFET
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOSFET_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);     // LED éteinte au départ
  digitalWrite(MOSFET_PIN, LOW); // MOSFET éteint au départ

  // Configuration du bouton
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Bouton avec résistance de pull-up

  // Initialisation de la carte SD
  Serial.println("Initialisation de la carte SD...");
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Erreur : Carte SD introuvable !");
    while (1); // Boucle infinie si erreur
  }
  Serial.println("Carte SD initialisée avec succès.");

  // Initialisation des sorties audio
  Serial.println("Initialisation des sorties audio...");
  out = new AudioOutputI2S();
  out->SetPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  out->SetGain(1.0); // Volume à 100%
  Serial.println("Sorties audio initialisées.");

  // Création des objets audio
  file = new AudioFileSourceSD("/alliwant.mp3");
  if (!file) {
    Serial.println("Erreur : Impossible d'ouvrir le fichier MP3 !");
    while (1); // Boucle infinie si erreur
  }
  mp3 = new AudioGeneratorMP3();
  Serial.println("Fichier MP3 chargé et prêt !");
}

void loop() {
  // Lire l'état actuel du bouton
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Détecte un changement d'état du bouton (appui ou relâchement)
  if (currentButtonState == LOW && lastButtonState == HIGH) { // Transition haut -> bas
    if (isPlaying) {
      // Arrête la lecture si elle est en cours
      Serial.println("Bouton appuyé, arrêt de la lecture...");
      isPlaying = false;          // Marque la lecture comme inactive
      mp3->stop();                // Stoppe la lecture MP3
      digitalWrite(LED_PIN, LOW);  // Éteint la LED
      digitalWrite(MOSFET_PIN, LOW); // Désactive le MOSFET
      // Réinitialise le fichier pour une prochaine lecture
      file->close();
      file = new AudioFileSourceSD("/alliwant.mp3");
    } else {
      // Démarre la lecture si elle n'est pas en cours
      Serial.println("Bouton appuyé, lancement de la lecture...");
      isPlaying = true;           // Marque la lecture comme active
      mp3->begin(file, out);      // Démarre la lecture MP3
      digitalWrite(LED_PIN, HIGH); // Allume la LED
      digitalWrite(MOSFET_PIN, HIGH); // Active le MOSFET
    }
    delay(300); // Antirebond pour éviter les détections multiples
  }

  // Mémorise l'état du bouton pour la prochaine itération
  lastButtonState = currentButtonState;

  // Si la lecture est active, vérifie l'état du fichier MP3
  if (isPlaying) {
    if (mp3->isRunning()) {
      mp3->loop(); // Continue la lecture
    } else {
      Serial.println("Lecture terminée.");
      isPlaying = false;          // Marque la lecture comme inactive
      mp3->stop();
      digitalWrite(LED_PIN, LOW);  // Éteint la LED
      digitalWrite(MOSFET_PIN, LOW); // Désactive le MOSFET
      // Réinitialise le fichier pour une prochaine lecture
      file->close();
      file = new AudioFileSourceSD("/alliwant.mp3");
    }
  }
}
