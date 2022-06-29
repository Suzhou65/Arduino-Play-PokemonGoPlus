// Libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>
// SSD1306 config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// Pin config
// Pokemon Go Plus, onboard LED, cathode
const int red = A0;
const int green = A1;
const int blue = A2;
// Pokemon Go Plus, onboard tactile switch
const int tactile = A3;
// Pokemon Go Plus, onboard vibration motor
const int vibration = A6;
// Controller board, switch
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
  pinMode(tactile, INPUT);
  pinMode(vibration, INPUT);
  pinMode(enable_catch, INPUT);
  pinMode(enable_spin, INPUT);
  pinMode(manual_key, INPUT);
  // Using internal pullup resistance
  digitalWrite(red, INPUT_PULLUP);
  digitalWrite(green, INPUT_PULLUP);
  digitalWrite(blue, INPUT_PULLUP);
  digitalWrite(vibration, INPUT_PULLUP);
  digitalWrite(enable_catch, INPUT_PULLUP);
  digitalWrite(enable_spin, INPUT_PULLUP);
  digitalWrite(manual_key, INPUT_PULLUP);
  // RNG
  randomSeed(analogRead(5));
  // Serial
  Serial.begin(9600);
  // OLED display config
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  // Booting message
  status(3,15,2, 3,35,1, F("ARDUINO"), F("Play Pokemon GO"));
  message(F("BOOT_COMPLETE\n"));
  delay(1000);
}
// Main
void loop(){
  // Manual press the key
  if (digitalRead(manual_key) == LOW){
    status(3,15,2, 3,35,1, F("DETECT"), F("MANUAL PRESS"));
    message(F("MANUAL_PRESS\n"));
    delay(random(450,550));
    // Press the key
    presskey();
  }
  // Vibration motor active
  if (digitalRead(vibration) == LOW){
    // Blue LED active, PokeStop
    if (digitalRead(blue) == LOW){
      // Disable spin Pokestop
      if(digitalRead(enable_spin) == HIGH){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Skip PokeStop"));
        message(F("IGNORE_POKESTOP\n"));
      }
      // Enable spin Pokestop
      else if (digitalRead(enable_spin) == LOW){
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("SPINNING"));
        delay(random(500,1000));
        presskey();
        delay(random(4000,4500));
        // Resupply fail
        while (digitalRead(vibration) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,15,2, 3,35,1, F("FAIL"), F("Cannot resupply"));
          message(F("RESUPPLY_FAIL\n"));
        }
        // Storage is full
        while (digitalRead(vibration) == HIGH && digitalRead(red) == LOW && digitalRead(green) == LOW && digitalRead(blue) == LOW){
          status(3,15,2, 3,35,1, F("FULL BAG"), F("Cannot resupply"));
          message(F("RESUPPLY_FAIL\n"));
        }
        // Resupply success
        while (digitalRead(vibration) == HIGH && digitalRead(red) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW){
          counter_spin = counter_spin + 1;
          String m2 = "Total spin: " + String(counter_spin);
          status(3,15,2, 3,45,1, F("SUCCESS"), m2);
          message(F("RESUPPLY_SUCCESS\n"));
        }
      }
    }
    // Pokemon you have caught before
    else if (digitalRead(green) == LOW){
      // Ignore
      if (digitalRead(enable_catch) == HIGH){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Stop catching"));
        message(F("IGNORE_CATCH\n"));
      }
      // Enable catch Pokemon
      else if (digitalRead(enable_catch) == LOW){
        status(3,10,2, 3,40,2, F("FIND"), F("POKEMON"));
        delay(random(500,1000));
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("CATCHING"));
        presskey();
        delay(random(4000,4500));
        // Catch fail
        while (digitalRead(vibration) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,10,2, 3,40,1, F("OOPS"), F("Pokemon run away"));
          message(F("CATCH_FAIL\n"));
        }
        // Catch success
        while (digitalRead(vibration) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW  && digitalRead(blue) == HIGH){
          counter_catch = counter_catch + 1;
          String m2 = "Total catch: " + String(counter_catch);
          status(3,15,2, 3,45,1, F("GOTCHA"), m2);
          message(F("CATCH_SUCCESS\n"));
        }
      }
    }
    // Pokemon never caught
    else if ((digitalRead(green) == LOW && digitalRead(red) == LOW)){
      // Ignore
      if (digitalRead(enable_catch) == HIGH){
        status(3,15,2, 3,35,1, F("IGNORE"), F("Stop catching"));
        message(F("IGNORE_CATCH\n"));
      }
      // Enable catch Pokemon
      else if (digitalRead(enable_catch) == LOW){
        status(3,10,2, 3,40,2, F("FIND NEW"), F("POKEMON"));
        delay(random(500,1000));
        // Press the key
        status(3,10,2, 3,40,2, F("NOW"), F("CATCHING"));
        presskey();
        delay(random(4000,4500));
        // Catch fail
        while (digitalRead(vibration) == HIGH && digitalRead(red) == LOW && digitalRead(green) == HIGH && digitalRead(blue) == HIGH){
          status(3,10,2, 3,40,1, F("OOPS"), F("Pokemon run away"));
          message(F("CATCH_FAIL\n"));
        }
        // Catch success
        while (digitalRead(vibration) == HIGH && digitalRead(green) == LOW && digitalRead(blue) == LOW  && digitalRead(blue) == HIGH){
          counter_catch = counter_catch + 1;
          String m2 = "Total catch: " + String(counter_catch);
          status(3,15,2, 3,45,1, F("GOTCHA"), m2);
          message(F("CATCH_SUCCESS\n"));
        }
      }
    }
  }
  delay(100);
}

// Press the button
void presskey(){
  // Trans into output
  pinMode(tactile, OUTPUT);
  digitalWrite(tactile, LOW);
  delay(250);
  // Undo
  pinMode(tactile, INPUT);
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
  // Display text
  display.display();
}
// Serial message function
void message(String m3){
  Serial.print(m3);
}
