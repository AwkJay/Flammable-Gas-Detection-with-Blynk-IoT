/************************************************/
/*

                                    PROGRAMMING DONE BY : AWNIKANT 29/12/18
*/
/*************************************************/
#include <BlynkSimpleStream.h>
#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h> 
SoftwareSerial SwSerial(3, 4);
char auth[] = "9af4b603a79f4b1bae0aedd050490f62";
int redled = 8;
int greenled = 9;
int buzzer = 10;
int streetled = 11;
int streetred = 12;
int smokeA0 = A5;
int sensorThres = 250; //Change
int flamePin = 13;
#define BLYNK_GREEN "#23C48E"
#define BLYNK_RED "#D3435C"
int Flame = HIGH;
WidgetLED led1(V0);
WidgetLED led2(V1);
WidgetLED led3(V2);
WidgetLED led4(V3);
BlynkTimer timer;


void TweetEmailAndNotification()
{
{
Flame = digitalRead(flamePin);
if (Flame == LOW)
{

}
    }
}

void sensorData()
{
int sensorValue = analogRead(A5);
Blynk.virtualWrite(V5, sensorValue);
}
void setup() {
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(streetled, OUTPUT);
pinMode(streetred, OUTPUT);
digitalWrite(streetled,HIGH);
pinMode(smokeA0, INPUT);
pinMode(flamePin, INPUT);
timer.setInterval(100L, sensorData);
SwSerial.begin(9600);
Serial.begin(9600);
Blynk.begin(Serial, auth);
timer.setInterval(60000L, TweetEmailAndNotification);
timer.setInterval(60000L, TweetEmailAndNotification);
Blynk.tweet("Flame & Gas SYSTEM STARTED :-) ");
}
void loop()
  {
    {
int analogSensor = analogRead(smokeA0);
if (analogSensor > sensorThres)
{
digitalWrite(redled, HIGH);
digitalWrite(greenled, LOW);
digitalWrite(streetred, HIGH);
led3.on();
led3.setColor(BLYNK_RED);
led4.off();
delay(100);
tone(buzzer, 1000,500);
Blynk.tweet("DANGER! GAS LEAKAGE DETECTED, location link- maps.app.goo.gl/link");
Blynk.notify("GAS LEAKAGE!!{FLAME & GAS DETECTION SYSTEM} HAS DETECTED GAS LEAKAGE ALERT!");
}
else
{
digitalWrite(redled, LOW);
digitalWrite(greenled, HIGH);
led3.off();
led4.on();
led4.setColor(BLYNK_GREEN); 
noTone(buzzer);
digitalWrite(streetred, LOW);
}
    }
    {
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  { 
    led1.on();
   led1.setColor(BLYNK_RED);
    led2.off();  
    tone(buzzer, 1000,500);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    Blynk.tweet("DANGER! Flame DETECTED, LOCATION link- maps.app.goo.gl/link");
Blynk.notify("DANGER! {FLAME & GAS DETECTION SYSTEM} HAS DETECTED FIRE IN APARTMENT, ALERT!!!!! maps.app.goo.gl/link");
  }
  else
  {
    led1.off();
     led2.on();
    led2.setColor(BLYNK_GREEN);
    noTone(buzzer);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
}
}
{
Blynk.run();
}
{
timer.run();
}
}
