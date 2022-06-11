// Libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
// SSD1306 Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// LED Cathode
const int red = A0;
const int green = A1;
const int blue = A2;
// Diaphragm switch
const int diaphragm = A3;
// Vibration motor
const int vb = A6;
// Onboard switch
const int enable_catch = 2;
const int enable_spin = 3;
const int manual_key = 4;
// Counter
int counter_spin = 0;
int counter_catch = 0;

// Config
void setup(){
  // PinMode
  pinMode(red, INPUT);
  pinMode(green, INPUT);
  pinMode(blue, INPUT);
  pinMode(diaphragm, INPUT);
  pinMode(vb, INPUT);
  pinMode(enable_catch, INPUT);
  pinMode(enable_spin, INPUT);
  pinMode(manual_key, INPUT);
  digitalWrite(red, INPUT_PULLUP);
  digitalWrite(green, INPUT_PULLUP);
  digitalWrite(blue, INPUT_PULLUP);
  digitalWrite(vb, INPUT_PULLUP);
  digitalWrite(enable_catch, INPUT_PULLUP);
  digitalWrite(enable_spin, INPUT_PULLUP);
  digitalWrite(manual_key, INPUT_PULLUP);
  // RNG
  randomSeed(analogRead(5));
  // Serial 
  Serial.begin(9600);
  // OLED Display Config
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  status(3,15,2, 3,35,1, F("ARDUINO"), F("Play Pokemon GO"));
  delay(1000);
}
// Main
void loop(){
  // Vibration motor active
  if (digitalRead(vb) == LOW){

    // PokeStop
    if (digitalRead(blue) == LOW){
      // Enable spin Pokestop
      if (digitalRead(enable_spin) == HIGH){
        delay(random(1000,1500));
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("SPINNING"));
        presskey();
        delay(random(4000,4500));
        // Resupply fail
        while (digitalRead(vb) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,15,2, 3,35,1, F("FAIL"), F("Cannot resupply"));}
        // Storage is full
        while (digitalRead(vb) == HIGH && digitalRead(red) == LOW && digitalRead(green) == LOW && digitalRead(blue) == LOW){
          status(3,15,2, 3,35,1, F("FULL BAG"), F("Cannot resupply"));}
        // Resupply success
        while (digitalRead(vb) == HIGH && digitalRead(red) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW){
          counter_spin = counter_spin + 1;
          String m2 = "Total spin: " + String(counter_spin);
          status(3,15,2, 3,45,1, F("SUCCESS"), m2);}}
      // Disable spin Pokestop
      else if(digitalRead(enable_spin) == LOW){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Skip PokeStop"));}}

    // Pokemon you have caught before
    else if (digitalRead(green) == LOW){
      // Enable catch Pokemon
      if (digitalRead(enable_catch) == HIGH){
        status(3,10,2, 3,40,2, F("FIND"), F("POKEMON"));
        delay(random(1000,1500));
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("CATCHING"));
        presskey();
        delay(random(4000,4500));
        // Catch fail
        while (digitalRead(vb) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,10,2, 3,40,1, F("OOPS"), F("Pokemon run away"));}
        // Catch success
        while (digitalRead(vb) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW  && digitalRead(blue) == HIGH){
          counter_catch = counter_catch + 1;
          String m2 = "Total catch: " + String(counter_catch);
          status(3,15,2, 3,45,1, F("GOTCHA"), m2);}}
      // Ignored
      else if (digitalRead(enable_catch) == LOW){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Stop catching"));}}
    // Pokemon never caught
    else if ((digitalRead(green) == LOW && digitalRead(red) == LOW)){
      // Enable catch Pokemon
      if (digitalRead(enable_catch) == HIGH){
        status(3,10,2, 3,40,2, F("FIND NEW"), F("POKEMON"));
        delay(random(1000,1500));
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("CATCHING"));
        presskey();
        delay(random(4000,4500));
        // Catch fail
        while (digitalRead(vb) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,10,2, 3,40,1, F("OOPS"), F("Pokemon run away"));}
        // Catch success
        while (digitalRead(vb) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW  && digitalRead(blue) == HIGH){
          counter_catch = counter_catch + 1;
          String m2 = "Total catch: " + String(counter_catch);
          status(3,15,2, 3,45,1, F("GOTCHA"), m2);}}
      // Ignored
      else if (digitalRead(enable_catch) == LOW){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Stop catching"));}}}

  // Manual Press the key
  if (digitalRead(manual_key) == HIGH){
    status(3,15,2, 3,35,1, F("DETECT"), F("MANUAL MODE"));
    delay(random(1000,1500));
    presskey();}
}

// Desplay function
void status(int x1,int y1,int z1,int x2,int y2,int z2,String m1,String m2){
  display.clearDisplay();
  // Row 1
  display.setTextSize(z1);
  display.setTextColor(WHITE);
  display.setCursor(x1,y1);
  display.println(m1);
  // Row 2
  display.setTextSize(z2);
  display.setTextColor(WHITE);
  display.setCursor(x2,y2);
  display.println(m2);
  // Display Text
  display.display();
}
// Press the button
void presskey(){
  // Trans into output
  pinMode(diaphragm, OUTPUT);
  digitalWrite(diaphragm, LOW);
  delay(250);
  // Undo
  pinMode(diaphragm, INPUT);
}
