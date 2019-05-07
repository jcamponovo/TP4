//declaration des constantes (avec valeur)
#  define USEcho 3 //echo sur le pin digital 3
#  define USTrig 2 //trig sur le pin digital 2

//declaration des variables (nom et type)
unsigned long duree;

void setup() //réalisé une fois à la mise sous tension de la carte
{
  Serial.begin(115200);//initialisation de la connexion série (cable USB) et choix du débit
  pinMode(USTrig, OUTPUT); //on envoie des pulses sur le trig
  pinMode(USEcho, INPUT); //on lit les retour sur echo
}

void loop() //realisé en boucle ensuite
{
  digitalWrite(USTrig,HIGH); //Crée un pulse creneau de 10 microsecondes
  delayMicroseconds(10); //suite
  digitalWrite(USTrig,LOW); //suite

  duree = pulseIn(USEcho,HIGH,30000); //On attend le retour. Delai maxi 30000 microsecondes
  Serial.println(duree); //On ecrit la valeur dans le moniteur série
  
  delay(1000); //on attend 1000ms avant la prochaine mesure
}
