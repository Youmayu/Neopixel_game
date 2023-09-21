#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 32

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
unsigned long int oldmillis=0;
unsigned long int interval=0;
bool start=0;

int PongStartInterval=500;
bool PongStart=false;
int x=0;

//These are functions used in the setup function
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

void pongrandom(){
    interval=PongStartInterval;
    start=random(0,2);
    Serial.println(start);
    if (start==0){
        while (x<11){
            pixels.setPixelColor(15, pixels.Color(255,255,255));
            pixels.setPixelColor(16, pixels.Color(0,0,0));
            pixels.show();
            delay(PongStartInterval);
            pixels.setPixelColor(15, pixels.Color(0,0,0));
            pixels.setPixelColor(16, pixels.Color(255,255,255));
            pixels.show();
            delay(PongStartInterval);
            x+=1;
            PongStartInterval-=50;
            Serial.println("I am here! - 1");
        }
        pixels.setPixelColor(16, pixels.Color(0,0,0));
        pixels.setPixelColor(15, pixels.Color(255,255,255));
        pixels.show();
        delay(1000);
        pixels.setPixelColor(15, pixels.Color(0,0,0));
        pixels.show();
    }
    if (start==1){
        while (x<11){
            pixels.setPixelColor(15, pixels.Color(0,0,0));
            pixels.setPixelColor(16, pixels.Color(255,255,255));
            pixels.show();
            delay(PongStartInterval);
            pixels.setPixelColor(15, pixels.Color(255,255,255));
            pixels.setPixelColor(16, pixels.Color(0,0,0));
            pixels.show();
            delay(PongStartInterval);
            x+=1;
            PongStartInterval-=50;
        }
        pixels.setPixelColor(15, pixels.Color(0,0,0));
        pixels.setPixelColor(16, pixels.Color(255,255,255));
        pixels.show();
        delay(1000);
        pixels.setPixelColor(16, pixels.Color(0,0,0));
        pixels.show();
    }
}

void getready(){
    Serial.println(start);
    if (start==0){
        Serial.println("Red");
        for (int i=14; i>0; i--){
            pixels.setPixelColor(i, pixels.Color(255,255,255));
            pixels.show();
            delay(50);
            pixels.setPixelColor(i, pixels.Color(0,0,0));
            pixels.show();
        }
    }
    if (start==1){
        Serial.println("Blue");
        for (int i=17; i<31; i++){
            pixels.setPixelColor(i, pixels.Color(255,255,255));
            pixels.show();
            delay(50);
            pixels.setPixelColor(i, pixels.Color(0,0,0));
            pixels.show();
        }
    }
}

void setup(){
    pixels.begin();
    Serial.begin(9600);
    startup();
    pongrandom();
    getready();
}

//These are functions used in the loop function
bool RedBall=false;
bool BlueBall=false;
int BallPosition=0;

void gameplay(){
    if (start==false){
        RedBall=true;
        BallPosition=1;
        pixels.setPixelColor(BallPosition, pixels.Color(255,255,255));
        pixels.show();
    }
    if (start==true){
        BlueBall=true;
        BallPosition=30;
        pixels.setPixelColor(BallPosition, pixels.Color(255,255,255));
        pixels.show();
    }

}

void loop(){
    gameplay();
}