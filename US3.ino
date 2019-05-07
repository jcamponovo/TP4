#  define USEcho 3 //echo sur le pin digital 3
#  define USTrig 2 //trig sur le pin digital 2

unsigned long duree;
float distance=0.;
float vitesse = 0.; //A modifier

void setup(){
  Serial.begin(115200);//initialisation de la connexion série et choix du débit
  pinMode(USTrig, OUTPUT); //on envoie des pulses sur le trig
  pinMode(USEcho, INPUT); //on lit les retour sur echo
}

void loop(){
digitalWrite(USTrig,HIGH); //un pulse creneau de 10 microsecondes
delayMicroseconds(10); //suite
digitalWrite(USTrig,LOW); //suite

duree = pulseIn(USEcho,HIGH,30000); //on attend le retour delai maxi 30000 microsecondes

distance = vitesse*(float)duree; //A modifier
Serial.println(distance);
delay(1000);
}
