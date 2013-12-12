#include <Adafruit_NeoPixel.h>
#include <OneWire.h>

// For LED strip
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

// Fpr temperature sensor
OneWire  ds(3); 

void setup() {
  // this function
  Serial.begin(9600); 
  strip.begin();
}  
  
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

 

    
void ledPattern()
{
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

void sensor(void) {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    return;
  }
  
 // Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return;
  }
  Serial.println();
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      //Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      //Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
      //Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
     // Serial.println("Device is not a DS18x20 family device.");
      return;
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;
  //Serial.print("Temperature = ");
  Serial.print(celsius);
  //Serial.print(" C ");
}

void loop() {
  sensor();
  ledPattern();
}
 

