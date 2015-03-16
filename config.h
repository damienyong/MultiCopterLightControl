#define INPUT_RC            // use rc inputs to control lightning mode
#define NUM_ARMS 8             // number of arms on the multicopter
#define LEDS_PER_ARM 7         // leds per arm
#define ihue = 0;
#define LED_PIN 12             // led pin => data of led strip

#if defined (INPUT_RC)
  #define RC_PIN_1                10            // PIN for RC input channel 1

  #define MODE_RC_1             MODE_0
  #define MODE_RC_2             MODE_1
  #define MODE_RC_3             MODE_2
  #define MODE_RC_4             MODE_3
  #define MODE_RC_5             MODE_4
  #define MODE_RC_6             MODE_5
  #define MODE_RC_7             MODE_6
  #define MODE_RC_off           MODE_7
#elif defined (INPUT_MSP)

#endif



/////////////////////////////////////////////////////////////////////////////////
// !!! Do not modify anything below this line, except you know what you do !!! //
/////////////////////////////////////////////////////////////////////////////////

#define MODE_0 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4
#define MODE_5 5
#define MODE_6 6
#define MODE_7 7
#define NUM_LEDS (NUM_ARMS * LEDS_PER_ARM) // calculate total number of leds
