

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5
#define RightMotorDir   0
#define LeftMotorSpeed  4
#define LeftMotorDir    2


char auth[] = "110fb480a5ff465a8578677e6d571f15";
//char ssid[] = "AgileVisitor";
//char pass[] = "desc491jjK";
char ssid[] = "RB";
char pass[] = "atireiopauaogato";

void setup()
{
  Serial.begin(115200);
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


BLYNK_WRITE(V0) // Stearing
{
  int stear = (param[0]);
  int thro  = (param[1]);
  float comL = 0;
  float comR = 0;

  if (thro >= 0) { // forward
    digitalWrite(RightMotorDir, HIGH);
    digitalWrite(LeftMotorDir, HIGH);
  } else {
    digitalWrite(RightMotorDir, LOW);
    digitalWrite(LeftMotorDir, LOW);
  }

  if (stear >= 0) { // LEFT
    comL = (thro * (100 - abs(stear)) / 100);
    comR = thro;
  } else {  // RIGHT
    comL = thro;
    comR = (thro * (100 - abs(stear)) / 100);
  }

//  Serial.print(comL);
//  Serial.print("   ");
//  Serial.print(comR);
//  Serial.println();

  analogWrite(RightMotorSpeed, abs(comL));
  analogWrite(LeftMotorSpeed, abs(comR));

}
