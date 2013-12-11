#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// state defines one of the LED pattermn based on input condition
int state = -1;
 
uint32_t hot = strip.Color(255,0,0);
uint32_t normal = strip.Color(80,0,80);
uint32_t cold = strip.Color(0,0,255);
uint32_t zero = strip.Color(0,0,0);
 
  
void HotMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, hot);
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(10); 
    }
}

void HotLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, hot);
        strip.show();
        delay(300); 
    }
    
   for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(300); 
    }
}

void HotNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, hot);
  }  
  strip.show(); 
}

void NormalMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, normal);
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(10); 
    }
}

void NormalLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, normal);
        strip.show();
        delay(300); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(300); 
    }
}

void NormalNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, normal);
  } 
  strip.show();  
}

void ColdMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, cold);
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(10); 
    }
}

void ColdLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, cold);
        strip.show();
        delay(300); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, zero);
        strip.show();
        delay(300); 
    }  
}

void ColdNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, cold);
      strip.show(); 
  } 
}

void blank()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, zero);
      strip.show(); 
  } 
}

void setup() {
  // this function
  Serial.begin(9600); 
  strip.begin();
}  

    
void loop() {
  
  while (Serial.available() > 0) 
  {
    state = Serial.parseInt();
  }
  
  switch (state) 
  {
      case 8:
        HotMoreWindy();
        break;
      case 7:
      	HotLessWindy(); 
	break;
      case 6:
      	HotNoWindy();  
	break;
      case 5:
      	NormalMoreWindy();   
	break;
      case 4:
      	NormalLessWindy();  
	break;
      case 3:
      	NormalNoWindy();   
	break;
      case 2:
      	ColdMoreWindy(); 
	break;
      case 1:
      	ColdLessWindy();
	break;
      case 0:
      	ColdNoWindy();
	break;
      case -1:
        blank();
        break;
   }
 }
 

