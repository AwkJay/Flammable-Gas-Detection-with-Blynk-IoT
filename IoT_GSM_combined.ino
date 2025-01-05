/************************************************************************************************************************************************/
                                                                 /* 
🄿🅁🄾🄶🅁🄰🄼🄼🄸🄽🄶
🄳🄾🄽🄴 
🄱🅈
🄰🅆🄽🄸🄺🄰🄽🅃
*/
/***********************************************************************************************************************************************/
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
int sensorThres = 400;
int flamePin = 11;
#define BLYNK_GREEN "#23C48E"
#define BLYNK_RED "#D3435C"
int Flame = HIGH;
WidgetLED led1(V0);
WidgetLED led2(V1);
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  SwSerial.print("V3 Slider value is: ");
  SwSerial.println(pinValue);
}
void TweetEmailAndNotification()
{
int analogSensor = analogRead(smokeA0);
if (analogSensor > sensorThres)
{
Blynk.tweet("DANGER! GAS LEAKAGE DETECTED, location link- maps.app.goo.gl/LINK");
Blynk.email("GAS LEAKAGE DETECTED!!", "GAS LEAKAGE HAS BEEN DETECTED!! Location -maps.app.goo.gl/LINK");
Blynk.notify("GAS LEAKAGE!!{FLAME & GAS DETECTION SYSTEM} HAS DETECTED GAS LEAKAGE ALERT!");
}
}
void TweetEmailAndNotificationFlame()
{
Flame = digitalRead(flamePin);
if (Flame == HIGH)
{
Blynk.tweet("DANGER! Flame DETECTED, location link-maps.app.goo.gl/LINK");
Blynk.email("FIRE DETECTED", "DANGET! FIRE HAS BEEN DETECTED IN THE APARTMENT. Location Link-maps.app.goo.gl/LINK");
Blynk.notify("DANGER! {FLAME & GAS DETECTION SYSTEM} HAS DETECTED FIRE IN APARTMENT, ALERT!!!!!maps.app.goo.gl/LINK");
}
}
void setup() {
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(streetled, OUTPUT);
pinMode(streetred, OUTPUT);
pinMode(smokeA0, INPUT);
pinMode(flamePin, INPUT);
Serial.begin(9600);
Blynk.begin(Serial, auth);

delay(100);
}
void loop() {
    { if (digitalRead(8)==HIGH) { led1.setColor(BLYNK_RED); 
} else 
 {  
led1.off();  
      }
        }
        { if (digitalRead(8)==LOW) { led2.setColor(BLYNK_GREEN); 
} else 
 {  
led2.off();  
      }
        }
  {
int analogSensor = analogRead(smokeA0);
Serial.print("Pin A0: ");
Serial.println(analogSensor);
if (analogSensor > sensorThres)
{
digitalWrite(redled, HIGH);
digitalWrite(greenled, LOW);
digitalWrite(streetled, HIGH);
digitalWrite(streetred, HIGH);

Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to the module
delay(100);
tone(buzzer, 1000,500);
Serial.println("ATDxxxxxxxx;");
}
else
{
digitalWrite(redled, LOW);
digitalWrite(greenled, HIGH);
noTone(buzzer);
digitalWrite(streetled, HIGH);
digitalWrite(streetred, LOW);
}
delay(50);
{
Flame = digitalRead(flamePin);
if (Flame == HIGH)
{
 Serial.println("ATDxxxxxxxxx;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
tone(buzzer, 1000,500);
digitalWrite(redled, HIGH);
digitalWrite(greenled, LOW);
digitalWrite(streetled, LOW);
digitalWrite(streetred, HIGH);
Serial.println((char)26);
//delay(100);
}
else
{

noTone(buzzer);
digitalWrite(greenled, HIGH);
digitalWrite(redled, LOW);
digitalWrite(streetled, HIGH);
digitalWrite(streetred, LOW);
}
}
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
 Serial.println("ATDxxxxxxxxx;");
    tone(buzzer, 1000,500);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
     Serial.println((char)26);
 delay(100);
  }
  else
  {
    noTone(buzzer);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
}

{
Blynk.run();
}
}
    }

    
