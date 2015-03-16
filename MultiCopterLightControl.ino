#include <FastSPI_LED2.h>
#include <EEPROM.h>
#include "config.h"

struct CRGB leds[NUM_LEDS];

int mode = MODE_0;
boolean reverse = false;
int DELAY = 100;
int config = 0;
int idex = 0;


void setup(){
  LEDS.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  clearLeds();
  readColors();
  readLeds();
   #if defined (INPUT_RC)
    setupInputRC();
  
  #endif
}

unsigned long delayTime = millis();
boolean checkDelay(int DELAY){
  unsigned long newMillis = millis();
  if (newMillis - delayTime >= DELAY){
    delayTime = newMillis;
    return true;
  }
  if (newMillis < delayTime) delayTime = 0;
  return false;
}

void clearLeds(){
  memset(leds, 0, NUM_LEDS * sizeof(struct CRGB));
}

void allLeds(CRGB color){
  for (int i=0; i<NUM_LEDS; i++) leds[i] = color;
}

void setLed(int iLed, CRGB color){
  leds[iLed] = color;
}

int getLedIdx(int arm, int armLed){
  return arm * LEDS_PER_ARM + armLed;
}

void setArmLed(int iArm, int iLed, CRGB color){
  int i = iArm * LEDS_PER_ARM + iLed;
  leds[i] = color;
}

void setArm(int iArm, CRGB color){
  for (int i=0; i<LEDS_PER_ARM; i++) setArmLed(iArm, i, color);
}

void show(){
  LEDS.show();
}

void show(int brightness){
  LEDS.show(brightness);
}

int lastMode = -1;
void loop(){
  #if defined (INPUT_RC)
    loopInputRC();
  #endif

  if (lastMode != mode) delayTime = 0;
  switch(mode){
    case MODE_0:{
      //Stabilize
    oneColor(CRGB::Green, DELAY);
        

      break;
    }
    case MODE_1:{
      //Loiter
      rainbow_loop(1,1);
   break;
    }
    case MODE_2:{
      //AltHold 
      oneColor(CRGB::Blue, DELAY);
      break;
    }
    case MODE_3:{
      //Drift //colorsnotworking
   runningLed(CRGB::Green, NULL, 0, true, LEDS_PER_ARM, DELAY); 
      int arms1[] = {0,1,6,7};
      int arms2[] = {2,3,4,5};
      runningLed2(CRGB::Blue, arms1, sizeof(arms1)/sizeof(int), arms2, sizeof(arms2)/sizeof(int), 2, DELAY);
     
      break;
    }
	case MODE_4:{
        //Acro
         police (CRGB::Blue,CRGB::Red,DELAY);
      break;
    }
	case MODE_5:{
  //Land
pulseBrightness(CRGB::Red,0,128,4,1);

      break;
    }
	case MODE_6:{
  //noconnection
      oneColor(CRGB::Red, DELAY);
      break;
    }

  }
  lastMode = mode;
}

