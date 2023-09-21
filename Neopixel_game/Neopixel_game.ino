#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 32

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
unsigned long int oldmillis=0;

void startup(){
    pixels.setPixelColor(15,pixels.Color(255,0,0));
    pixels.setPixelColor(16,pixels.Color(0,0,255));
    pixels.show();
    delay(1000);
    for (int i=0; i<3; i++){
        pixels.clear();
        pixels.show();
        delay(100);
        pixels.setPixelColor(15,pixels.Color(255,0,0));
        pixels.setPixelColor(16,pixels.Color(0,0,255));
        pixels.show();
        delay(300);
    }
    for (int i=0; i<NUMPIXELS/2; i++){
        pixels.setPixelColor(15-i,pixels.Color(255,0,0));
        pixels.setPixelColor(16+i,pixels.Color(0,0,255));
        pixels.show();
        delay(50);
        pixels.clear();
        pixels.show();
    }
    pixels.setPixelColor(0,pixels.Color(255,0,0));
    pixels.setPixelColor(31,pixels.Color(0,0,255));
    pixels.show();
}

void pong(){
    oldmillis=millis();
    
}

void setup() {
    pixels.begin();
    startup();
}

void loop(){
}