int sensorTopf1Pin = A1;
int sensorTopf2Pin = A2;

int pumpeTopf1Pin = 12;
int pumpeTopf2Pin = 13;

//Unterhalb diser Sensorwerte wird nicht gegossen
int Topf1Soll = 300;
int Topf2Soll = 300;

int Topf1Ist = 700;
int Topf2Ist = 700;

//Wartezeit zwischen den Messungen [ms] 
//int Wartezeit = 3600000;  // eine Stunde
int Wartezeit = 60000;  // eine Minute

//Solang wird bei zu trockenem Boden gepumpt [ms]
int Pumpzeit = 25000;

void setup() {
  
  // Alle Sensoren sind Eingänge
  pinMode(sensorTopf1Pin, INPUT);
  pinMode(sensorTopf2Pin, INPUT);

  //Alle Pumpen sind Ausgänge
  pinMode(pumpeTopf1Pin, OUTPUT);
  pinMode(pumpeTopf2Pin, OUTPUT);

  //Pumpen zu Begin aus
  digitalWrite(pumpeTopf1Pin,LOW);
  digitalWrite(pumpeTopf2Pin,LOW);
  
  Serial.begin(9600);

  //Wartezeit für die Senoren zu Beginn
  delay(2000);
}
      
void loop() {

  //Messen...
  Topf1Ist = analogRead(sensorTopf1Pin);
  Topf2Ist = analogRead(sensorTopf2Pin);
  
  //... Werte seriell ausgeben...
  Serial.print("Feuchtigkeit Topf 1: ");
  Serial.print(Topf1Ist);
  Serial.print("\t");   
  Serial.print("Feuchtigkeit Topf 2: ");
  Serial.print(Topf2Ist);
  Serial.print("\t");   

  //...und bei Bedarf pumpen
  if(Topf1Ist > Topf1Soll) 
    {
      digitalWrite(pumpeTopf1Pin, HIGH);
      Serial.print("Topf1 zu trocken!!!"   );
      Serial.print("\t");
      delay(Pumpzeit);
      digitalWrite(pumpeTopf1Pin, LOW);
    } 
  else
    {
      Serial.print("Topf1 ist ok!"); 
      Serial.print("\t");
    }
    
  if(Topf2Ist > Topf2Soll) 
    {
      digitalWrite(pumpeTopf2Pin, HIGH);
      Serial.print("Topf2 zu trocken!!!"   );
      Serial.print("\n");
      delay(Pumpzeit);
      digitalWrite(pumpeTopf2Pin, LOW);
    } 
  else
    {
      Serial.print("Topf2 ist ok!"); 
      Serial.print("\n");
    }
   
delay(Wartezeit);
}
