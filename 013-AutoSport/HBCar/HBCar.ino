

#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5
#define RightMotorDir   0
#define LeftMotorSpeed  4
#define LeftMotorDir    2


char auth[] = "52584d18d17e49578fc21b70f56a12a6";
char ssid[] = "batatuchas24";
char pass[] = "atireiopauaogatoto";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);
}

void loop()
{
  Blynk.run();
  
}

void halt()
{
  Serial.println("halt");
  digitalWrite(RightMotorSpeed, LOW); 
  digitalWrite(LeftMotorSpeed, LOW);
}

void forward()
{
  Serial.println("forward");
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void reverse()
{
  Serial.println("reverse");
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
  Serial.println("right");
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void left()
{
  Serial.println("left");
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

BLYNK_WRITE(V0)
{
  if (param[0])
    forward();
  else
    halt();
}

BLYNK_WRITE(V1)
{
  if (param[0])
    reverse();
  else
    halt();
}

BLYNK_WRITE(V2)
{
  if (param[0])
    right();
  else
    halt();
}

BLYNK_WRITE(V3)
{
  if (param[0])
    left();
  else
    halt();
}
