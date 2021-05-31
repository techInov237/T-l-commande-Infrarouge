#include <IRremote.h>

const char DIN_RECEPTEUR_INFRAROUGE = 2; // definit la broche de connection du recepteur IR
int relais = 11;

IRrecv monRecepteurInfraRouge(DIN_RECEPTEUR_INFRAROUGE);

decode_results messageRecu; // variable qui va stocker le message recu par le recepteur IR
void setup() {
Serial.begin(9600);
monRecepteurInfraRouge.enableIRIn(); // activer le recepteur IR
monRecepteurInfraRouge.blink13(true); // Faire clignoter une LED lors de la reception des informations
pinMode(relais, OUTPUT); // initialise le relais en sortie
digitalWrite(relais, LOW); // permet de mettre le relais dans l'etat BAS 
}

void loop() {
if (monRecepteurInfraRouge.decode(&messageRecu)) // detecte la presence d'un nouveau message
{
delay(500); // une attente de 500ms pour eviter une redondance
if(messageRecu.value == 0xFF30CF){
      Serial.println("Touche 1");
      digitalWrite(relais, HIGH);
      }
if(messageRecu.value == 0xFF18E7){
      Serial.println("Touche 2");
      digitalWrite(relais, LOW);
      }

monRecepteurInfraRouge.resume(); //permet au recepteur de recevoir de nouveau message
delay(10);
}
}
