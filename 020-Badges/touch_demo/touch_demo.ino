int threshold = 40;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  printf("\n ESP32 Touch Interrupt Test\n");
  touchAttachInterrupt(12, gotTouch12, threshold);
  touchAttachInterrupt(13, gotTouch13, threshold);
  touchAttachInterrupt(14, gotTouch14, threshold);
  touchAttachInterrupt(15, gotTouch15, threshold);
  touchAttachInterrupt(27, gotTouch27, threshold);
}

void loop() 
{
}

void gotTouch12()
{
  Serial.println("RIGHT\n");
}

void gotTouch13()
{
  Serial.println("DOWN\n");
}

void gotTouch14()
{
  Serial.println("UP\n");
}

void gotTouch15()
{
  Serial.println("FIRE\n");
}
void gotTouch27()
{
  Serial.println("LEFT\n");
}