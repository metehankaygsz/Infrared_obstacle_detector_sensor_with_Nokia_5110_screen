//Metehan Kaygisiz 5.7.2021 18:26
#include <SPI.h>
#include <Adafruit_GFX.h>        
#include <Adafruit_PCD8544.h>     
int sensorpin = 2;
int val ;
Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


//ok sign
const unsigned char ok [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0f, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x70, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3c, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


//cross sign
const unsigned char cross [] PROGMEM = {
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 
  0x38, 0x00, 0x06, 0x38, 0x00, 0x07, 0x70, 0x00, 0x07, 0x70, 0x00, 0x03, 0xe0, 0x00, 0x03, 0xe0, 
  0x00, 0x03, 0xe0, 0x00, 0x03, 0xc0, 0x00, 0x01, 0xc0, 0x00, 0x01, 0xc0, 0x00, 0x01, 0xe0, 0x00, 
  0x03, 0xf0, 0x00, 0x03, 0xf8, 0x00, 0x03, 0x7e, 0x00, 0x06, 0x3f, 0x00, 0x06, 0x0e, 0x00, 0x04, 
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup()   {
  pinMode (sensorpin, INPUT) ;
  Serial.begin(9600);
  display.begin(); 
  display.setContrast(50); //you can change contrast from here if you can't see the texts
  display.clearDisplay();   
}
void loop() {
  val = digitalRead (sensorpin) ;
  if (val == HIGH)
  {
    display.setCursor(0, 0);
    display.println("No");
    display.println("Objects");
    display.println("Detected");
    display.drawBitmap(0  , 14, ok, 50, 50, 1);
    display.setTextSize(1);
    display.display();
  }
  else
  {
    display.setCursor(0, 0);
    display.println("Objects");
    display.println("Detected");
    display.drawBitmap(0  , 18, cross, 20, 25, 1);
    display.setTextSize(1);
    display.display();
    delay(100);
    display.clearDisplay();  
  }
}
