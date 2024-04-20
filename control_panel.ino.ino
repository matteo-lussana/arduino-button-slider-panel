#define PIN1 3
#define PIN2 4
#include "Keyboard.h"
int state = 1;
const int NUM_SLIDERS = 3;
const int analogInputs[NUM_SLIDERS] = {A1,A2,A3};
int analogSliderValues[NUM_SLIDERS];
int pinArray[] = {2,3,4,5,6,7,8,9};

void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  //slider function source: https://github.com/omriharel/deej
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
  
  for(int i=0; i<8; i++){
    pinMode(pinArray[i], INPUT_PULLUP);
  }
}

void loop() {
  //slider function source: https://github.com/omriharel/deej
  updateSliderValues();
  sendSliderValues();

  state = digitalRead(2);
  if(state == LOW){
    //send to PC ALT+SHIFT+1
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('1');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(3);
  if(state == LOW){
    //send to PC ALT+SHIFT+2
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('2');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(4);
  if(state == LOW){
    //send to PC ALT+SHIFT+3
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('3');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(5);
  if(state == LOW){
    //send to PC ALT+SHIFT+4
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('4');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(6);
  if(state == LOW){
    //send to PC ALT+SHIFT+5
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('5');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(7);
  if(state == LOW){
    //send to PC ALT+SHIFT+6
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('6');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(8);
  if(state == LOW){
    //send to PC ALT+SHIFT+7
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('7');
    delay(200);
    Keyboard.releaseAll();
  }
  state = digitalRead(9);
  if(state == LOW){
    //send to PC ALT+SHIFT+8
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('8');
    delay(200);
    Keyboard.releaseAll();
  }
  

  delay(100);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}