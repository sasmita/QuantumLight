#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void HotMoreWindy()
{
  while (1)
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
}

void HotLessWindy()
{
  while (1)
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
}

void HotNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,0,0));
      strip.show(); 
  }  
}

void NormalMoreWindy()
{
   while (1)
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
}

void NormalLessWindy()
{
   while (1)
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
}

void NormalNoWindy()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,127,127));
      strip.show(); 
  }  
}

void ColdMoreWindy()
{
  while (1)
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
}

void ColdLessWindy()
{
  while (1)
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
  while (Serial.available() > 0) {
    int input = Serial.parseInt();
    if (input == 8)
     {
      HotMoreWindy();
     }
    else if(input == 7)
     {
      HotLessWindy(); 
     }
    else if(input == 6)
     {
      HotNoWindy();  
     }
      else if(input == 5)
     {
      NormalMoreWindy();   
     }
    else if(input == 4)
     {
      NormalLessWindy();  
     }
      else if(input == 3)
     {
      NormalNoWindy();   
     }
    else if(input == 2)
     {
      ColdMoreWindy();  
     }
      else if(input == 1)
     {
      ColdLessWindy();   
     }
     else
     { 
       ColdNoWindy();
     }
    }
  // Finally showing all the LEDsstrip.show(); // Initialize all pixels to 'off
 }


