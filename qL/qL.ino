#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int state = 0;
  
void HotMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,0,0));
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(10); 
    }
}

void HotLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,0,0));
        strip.show();
        delay(300); 
    }
    
   for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(300); 
    }
}

void HotNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,0,0));
  }  
  strip.show(); 
}

void NormalMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,127,127));
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(10); 
    }
}

void NormalLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,127,127));
        strip.show();
        delay(300); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(300); 
    }
}

void NormalNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,127,127));
  } 
  strip.show();  
}

void ColdMoreWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,255,255));
        strip.show();
        delay(10); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(10); 
    }
}

void ColdLessWindy()
{
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(255,255,255));
        strip.show();
        delay(300); 
    }
    
    for(uint16_t i=0; i<strip.numPixels(); i++) 
    {
        strip.setPixelColor(i, strip.Color(0,0,0));
        strip.show();
        delay(300); 
    }  
}

void ColdNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,255,255));
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
   }
 }
 

