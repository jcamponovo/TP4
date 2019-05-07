#  define USEcho 3 //echo sur le pin digital 3
#  define USTrig 2 //trig sur le pin digital 2

unsigned long duree;
float distance=0.;
float vitesse = 341.2;

int n=64;
double moyenne=0;

void setup(){
  Serial.begin(115200);//initialisation de la connexion série et choix du débit
  pinMode(USTrig, OUTPUT); //on envoie des pulses sur le trig
  pinMode(USEcho, INPUT); //on lit les retour sur echo
}

void loop(){
  for (int i=0;i<n;i++){
    duree = 0;
    while (duree==0){
      digitalWrite(USTrig,HIGH); //un pulse creneau de 10 microsecondes
      delayMicroseconds(10); //suite
      digitalWrite(USTrig,LOW); //suite

      duree = pulseIn(USEcho,HIGH,30000); //on attend le retour delai maxi 30000 microsecondes

      moyenne = moyenne + (float)duree/(float)n;
      delay(10);
    }
  }
distance = vitesse*(float)duree/20000.; //duree en µs + AR + resultat en cm
Serial.println(distance); //on ecrit la valeur dans le moniteur série
delay(1000); //on attend 1000ms avant la prochaine mesure
}
