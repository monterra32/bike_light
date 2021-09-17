// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?  
#define NUMPIXELS 9
w 
.     // Popular NeoPixel ring sizedf

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  // put your setup code here, to run once:
// These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
   
  //setup for buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leftTurn = digitalRead(2); 
  int rightTurn = digitalRead(4);
  delay(10);
  if (leftTurn == 0 && rightTurn == 1) {
    pixels.clear(); // Set all pixel colors to 'off'

    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=NUMPIXELS-1;i>=0; i--) { // For each pixel...
  
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(250, 50, 0));
  
      pixels.show();   // Send the updated pixel colors to the hardware.
  
      delay(DELAYVAL); // Pause before next pass through loop
   } 
  }
 else if (rightTurn == 0 && leftTurn == 1) {
      
    pixels.clear(); // Set all pixel colors to 'off'
      
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(250, 50, 0));
  
      pixels.show();   // Send the updated pixel colors to the hardware.
  
      delay(DELAYVAL); // Pause before next pass through loop
    }}
    else if (rightTurn ==0 && leftTurn ==0) {
      pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      
  }
      pixels.show();
      delay(DELAYVAL);
    pixels.clear();
    pixels.show();
    delay(DELAYVAL);
    }else {
      pixels.clear();
      pixels.show();
    }
  }
