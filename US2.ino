#  define USEcho 3 //echo sur le pin digital 3
#  define USTrig 2 //trig sur le pin digital 2

unsigned long duree;
double dureemoy=0;
int n = 100;

void setup(){
   Serial.begin(115200);//initialisation de la connexion série et choix du débit
   pinMode(USTrig, OUTPUT); //on envoie des pulses sur le trig
   pinMode(USEcho, INPUT); //on lit les retour sur echo
}

void loop(){
   for (int i = 0; i<n; i++){
      duree = 0;
      while (duree==0){
         digitalWrite(USTrig,HIGH); //un pulse creneau de 10 microsecondes
         delayMicroseconds(10); //suite
         digitalWrite(USTrig,LOW); //suite
         duree = pulseIn(USEcho,HIGH,30000); //renvoie 0 si le retour n'est pas détecté
         dureemoy = dureemoy + (float)duree/(float)n;
         delay(10);
      }
   }
   Serial.println(dureemoy); //on ecrit la valeur dans le moniteur série
   dureemoy=0;
}
