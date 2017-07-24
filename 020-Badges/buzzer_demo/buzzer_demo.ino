
const int f = 349;
const int gS = 415;
const int a = 440;
const int cH = 523;
const int eH = 659;
const int fH = 698;
const int e6 = 1319;
const int g6 = 1568;
const int a6 = 1760;
const int as6 = 1865;
const int b6 = 1976;
const int c7 = 2093;
const int d7 = 2349;
const int e7 = 2637;
const int f7 = 2794;
const int g7 = 3136;

const int buzzerPin = 18;
 
void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
}
 
void loop()
{
  MarioTheme();
  delay(3000);
  ImperialMarch();
  delay(3000);
}

void beep(int tone, int duration)
{
  for (long i = 0; i < duration * 900L; i += tone * 1)
  {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone*(.50));
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone*(.50));
  }
  delay(30);
}
 
void  ImperialMarch()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(500);
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
}

void  MarioTheme()
{
  beep(e7,150);
  beep(e7,150);
  delay(150);
  beep(e7,150);  
  delay(150);
  beep(c7,150);
  beep(e7,150);
  delay(150);
  beep(g7,150);
  delay(450);
  beep(g6,150);
  delay(450);
  beep(c7,150);
  delay(300);
  beep(g6,150);
  delay(300);
  beep(e6,150);
  delay(300);
  beep(a6,150);
  delay(150);
  beep(b6,150);
  delay(150);
  beep(as6,150);
  beep(a6,150);
  delay(150);
  beep(g6,112);
  beep(e7,112); 
  beep(g7,112);
  beep(a6,150);
  delay(150);
  beep(f7,150);
  beep(g7,150);
  delay(150);
  beep(e7,150);
  delay(150); 
  beep(c7,150);
  beep(d7,150);
  beep(b6,150);
}
