// This Arduino code was clean copy from " PokeBot – Catch Pokémon’s in your sleep (and at work) "
// And Written by the author " Johan von Konow "
// Thanks for his Arduino code and circuit diagram concept

#include <SPI.h>
//Input SPI library
#include "LCD_Functions.h"
//Input Nokia 5110 LCD library

const int vibratePin = A0;
const int switchPin = A1;
const int bluePin = A2;
const int redPin = A3;
const int greenPin = A4;
// Pokemon Go Plus 

const int cfg2Pin = 2;
const int cfg1Pin = 3;
const int maxCol = 14;
//IF NOKIA 5110 LCD_WIDTH 6;
//const int ledPin =  13;

//PokeStop Maximum Spinning Limited
int maxSpin=200;
//PokeStop Spinning, Starting/Currently Numbers
int curSpin=124;

//PokeBall Maximum Throwing Limited
int maxBall=200;
//PokeBall Starting/Currently Numbers
int curBall=56;

void setup() {
  pinMode(vibratePin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(cfg1Pin, INPUT);
  pinMode(cfg2Pin, INPUT);
  pinMode(redPin, INPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin, INPUT);
  digitalWrite(vibratePin, INPUT_PULLUP);
  digitalWrite(cfg1Pin, INPUT_PULLUP);
  digitalWrite(cfg2Pin, INPUT_PULLUP);
  digitalWrite(greenPin, INPUT_PULLUP);
  digitalWrite(redPin, INPUT_PULLUP);
  digitalWrite(bluePin, INPUT_PULLUP);

  randomSeed(analogRead(5));
  
  Serial.begin(9600);
  while (!Serial) {}

  lcdBegin(); // This will setup our pins, and initialize the LCD
  setContrast(40); // Good values range from 40-60
  clearDisplay(WHITE);
  setCircle (LCD_WIDTH/2,23, 23, BLACK, 16);
  setRect(0, 24, LCD_WIDTH,LCD_HEIGHT, 1, WHITE);
  setCircle (LCD_WIDTH/2,23, 23, BLACK, 1);
  setCircle (LCD_WIDTH/2,23, 8, BLACK, 1);
  updateDisplay();
  delay(1000);

  clearDisplay(WHITE);
  printStr("POKEBOT ONLINE",0);
  printStat();
//  analogWrite(blPin, 0);
}

void loop() {
  if (digitalRead(vibratePin) == LOW) {
//    printStr("Vibration",0);
  }
  if (digitalRead(redPin) == LOW) {
    printStr("Red LED",0);
  } 
  if (digitalRead(greenPin) == LOW) {
    if(curBall<=maxBall && digitalRead(cfg1Pin) == LOW){    
      analogWrite(blPin, 255);
      printStr("Pokemon found",4);      //green led
      curBall++;
      rndW8(100,2000);
      printStr("Throwing ball",4);
      pressKey();
      printStat();
      rndW8(10000,30000);
      printStr("",4);
      analogWrite(blPin, 0);
    } 
  } 
  if (digitalRead(bluePin) == LOW) {
    if(curSpin<=maxSpin && digitalRead(cfg2Pin) == LOW){
      analogWrite(blPin, 255);
      printStr("Stop found",4);     //blue led
      curSpin++;
      rndW8(100,2000);
      printStr("Spinning stop",4);
      pressKey();
      printStat();
      rndW8(10000,30000);
      printStr("",4);
      updateDisplay();
      analogWrite(blPin, 0);
    } 
  }
  printStat();
  delay(100); 
}

void printStat(){
  String str1;
  if (digitalRead(cfg1Pin) == HIGH){
    curBall=0;
    str1 = "";
  } else {  
    str1 = "Ball ";
    str1 += String(curBall,DEC);
    str1 += " / ";
    str1 += String(maxBall,DEC);
  }
    printStr(str1,1);
  if (digitalRead(cfg2Pin) == HIGH){
    curSpin=0;
    str1 = "";
  } else {
    str1 = "Spin ";
    str1 += String(curSpin,DEC);
    str1 += " / ";
    str1 += String(maxSpin,DEC);
  }
    printStr(str1,2);
}

void pressKey(){
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, LOW);
  delay(250);
  pinMode(switchPin, INPUT);
}

void rndW8(long minVal,long maxVal){
  long rndNumber = random(minVal, maxVal);      
  String str1;
  str1 = "Waiting ";
  str1 += String(rndNumber,DEC);
  printStr(str1,5);

  int rndSec;
  for(rndSec = rndNumber / 1000; rndSec>0; rndSec--){
    str1 = "Waiting ";
    str1 += String(rndSec,DEC);
    printStr(str1,5);
    delay(1000);
  }      
  delay(rndNumber % 1000);
  printStr("",5);           //clear row
}

void printStr(String str1,int row){
  Serial.println(str1);
  str1 += "                 ";
  for(int i=0; i<maxCol;i++){
    setChar(str1.charAt(i), i*6, row << 3, BLACK);
  }
  updateDisplay();
}
