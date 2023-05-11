//Importing Libraries
#include <Adafruit_NeoPixel.h>
#include <FreeRTOS_AVR.h>
#include <LibPrintf.h>
//Define some global variables here:
#define LED_PIN 3
#define LED_COUNT 16
//Defining Led's using the above two variables
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

/***********************************************************************************/
//LED patterns/animation functions
/***********************************************************************************/

int sequentialUpDownLed(uint32_t color,int brightness, int sequenceDelayTime,int delayBetweenTransition, int endDelayTime){
  uint32_t pixelsOff = strip.Color(0, 0, 0, 0);  //Setting the NeoPixels to "off" by setting RGB color code to 0,0,0 (black)
  strip.setBrightness(brightness);
  while(true) {
    for (int i = 0; i <= LED_COUNT; i++) { //Looping through the NeoPixel array
      strip.setPixelColor(i, color); ode//Setting the color on the given pixel (i);
      strip.show(); //Turning each pixel on
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(delayBetweenTransition);
    for (int i = LED_COUNT; i >= 0; i--) { //Backwards looping through the NeoPixel array
      strip.setPixelColor(i, pixelsOff); //Setting the color to a noColor variable defined above
      strip.show(); //Turning each pixel off (because noColor is black)
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(endDelayTime);
    //Possibly add condition to break loop for later functionality
  }
}

int swipe(uint32_t color,int brightness, int sequenceDelayTime,int delayBetweenTransition, int endDelayTime){
  uint32_t pixelsOff = strip.Color(0, 0, 0, 0);  //Setting the NeoPixels to "off" by setting RGB color code to 0,0,0 (black)
  strip.setBrightness(brightness);
  while(true) {
    for (int i = 0; i <= LED_COUNT; i++) { //Looping through the NeoPixel array
      strip.setPixelColor(i, color); //Setting the color on the given pixel (i);
      strip.show(); //Turning each pixel on
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(delayBetweenTransition);
    for (int i = 0; i <= LED_COUNT; i++) { //Backwards looping through the NeoPixel array
      strip.setPixelColor(i, pixelsOff); //Setting the color to a noColor variable defined above
      strip.show(); //Turning each pixel off (because noColor is black)
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(endDelayTime);
    //Possibly add condition to break loop for later functionality
    //Add starting direction option using switch or if statements
  }
}

int scan(uint32_t color,int brightness, int sequenceDelayTime,int offDelay, int returnDelay, int endDelay){
  uint32_t pixelsOff = strip.Color(0, 0, 0, 0);  //Setting the NeoPixels to "off" by setting RGB color code to 0,0,0 (black)
  strip.setBrightness(brightness);
  while(true) {
    for (int i = -1; i <= LED_COUNT; i++) { //Looping through the NeoPixel array
      strip.setPixelColor(i, color); //Setting the color on the given pixel (i);
      strip.show(); //Turning each pixel on
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(offDelay);
    for (int i = -1; i <= LED_COUNT; i++) { //looping through the NeoPixel array
      strip.setPixelColor(i, pixelsOff); //Setting the color to a noColor variable defined above
      strip.show(); //Turning each pixel off (noColor is black)
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(returnDelay);
    for (int i = LED_COUNT; i >= -1; i--) { //Backwards looping through the NeoPixel array
      strip.setPixelColor(i, color); //Setting the color to a noColor variable defined above
      strip.show(); //Turning each pixel off (noColor is black)
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(offDelay);
    for (int i = LED_COUNT; i >= -1; i--) { //Backwards looping through the NeoPixel array
      strip.setPixelColor(i, pixelsOff); //Setting the color to a noColor variable defined above
      strip.show(); //Turning each pixel off (noColor is black)
      delay(sequenceDelayTime); //Adding delay between the activation of each pixel
    }
    delay(endDelay);
    //Possibly add condition to break loop for later functionality
    //Add starting direction option using switch or if statements
  }
}

int breathing(uint32_t color, int minBrightness, int maxBrightness, int inhaleTime = 0, int holdBreath = 0, int exhaleTime = 0, int endDelay = 0){
  while(true){
    int brightness = minBrightness;
    strip.setBrightness(minBrightness);
    strip.fill(color, 0, LED_COUNT); 
    strip.show();

    if(brightness >= minBrightness){
      while(brightness < maxBrightness){
        brightness++;
        strip.setBrightness(brightness);
        strip.show();
        delay(inhaleTime);
      }
    }
    delay(holdBreath);
    if(brightness == maxBrightness){
      while(brightness > minBrightness){
        brightness--;
        strip.setBrightness(brightness);
        strip.show();
        delay(exhaleTime);
      }
    }
    delay(endDelay);
  }
}

int staticColor(uint32_t color, int brightness) {
  strip.setBrightness(brightness);
  strip.fill(color, 0, LED_COUNT);   
  strip.show(); 
}

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to off
}

void loop() {
  uint32_t color = strip.Color(255, 50, 0, 0);
  // sequentialUpDownLed(color, 255, 30, 0, 200);
  swipe(color, 255, 15, 300, 10);
  // scan(color, 255, 20, 0, 0, 0);
  // breathing(color, 1, 255, 10, 10, 10, 10);
  // staticColor(color, 255);
}
