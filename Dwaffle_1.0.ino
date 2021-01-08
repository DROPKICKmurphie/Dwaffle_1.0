#include <Wire.h>
#include "rgb_lcd.h"
#define LIGHT_SENSOR A1

rgb_lcd lcd;

int delaytime = 200;
int LED1 = 3;
int LED2 = 4; //whole number type variable 0, 1, 2 ....
int LCD = 12;
int flash = 500;
int pause = 300;
int lcdpause = 2000;


float sensor;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Baud Rate "9600" Uno Board runs this rate
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LCD, OUTPUT);
  
  
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
   sensor = analogRead(1);
   Serial.println(sensor);
   if(sensor >= 185) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(flash);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    delay(pause);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    lcd.setRGB(255, 0, 0);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Hello my name");
    lcd.setCursor(1, 1);
    lcd.print("is Dwaffle!");
    delay(lcdpause);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Is it tea");
    lcd.setCursor(1,1);
    lcd.print("time?!");
    delay(lcdpause);
    lcd.clear();
   }else if(sensor <= 150) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    lcd.setRGB(0, 0, 204);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Dwaffle is");
    lcd.setCursor(1, 1);
    lcd.print("sleeping zZzZz");
    delay(lcdpause);
    lcd.clear();
  }
}
