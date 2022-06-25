#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

char auth[] = "C3o43Kd7gSQr9TuGH3voFdNr2fPXzUy-";// replace with your blynk token
char ssid[] = "BOLT! SUPER 4G-C2B2"; //replace eith your wifi ssid
char pass[] = "B6D8C2B2"; //replace with your wifii pass

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  servo.attach(2); // nodemcu D4 pin
  servo.write(0); // move to 0•
 }
  
void loop()
{
  
  Blynk.run();
  
}


BLYNK_WRITE(V2) // virtual pin 2 on blynk app
{
    int pinValue = param.asInt();
         if (pinValue == 1) //if button on
 { servo.write(58);// move servo to 58•
    }
           else // if button off
            
  servo.write(0); // move servo to 0•
}