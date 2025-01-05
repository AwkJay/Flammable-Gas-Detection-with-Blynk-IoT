/*Programmed by Awnikant*/
int redbulb = 13;
int greenbulb = 11;
int buzzer = 10;
int smokeA0 = A5;
// My threshold value
int sensorThres = 400;

void setup() {
  pinMode(redbulb, OUTPUT);
  pinMode(greenbulb, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redbulb, HIGH);
    digitalWrite(greenbulb, LOW);
    
     Serial.println("AT+CMGF=1");
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+91xxxxxxxxx\"\r");
     Serial.println("Gas Leakage Alert");
     Serial.println((char)26);
     delay(100);
     digitalWrite(buzzer,HIGH);
     Serial.println("ATDxxxxxxxx;");

  }
  else
  {
    digitalWrite(redbulb, LOW);
    digitalWrite(greenbulb, HIGH);
    digitalWrite(buzzer,HIGH);
  }
  delay(50);
}
