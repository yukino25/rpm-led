#include <Adafruit_NeoPixel.h>
int NUMPIXELS = 8;
int LEDPIN = 12;

#include <AltSoftSerial.h>
#include <ELMduino.h>


AltSoftSerial BTSerial(8, 9); // RX, TX
#define ELM_PORT BTSerial


ELM327 myELM327;


uint32_t rpm = 0;
#include "U8glib.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);
U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

void rpm1(void){

	if (myELM327.nb_rx_state == ELM_SUCCESS){
		draw1();
	}
	else{
		draw2();
	}
}

void draw1(void){
	  float tempRPM = myELM327.rpm();
			rpm = (uint32_t)tempRPM;
			u8g.setFont(u8g_font_gdr25r);
			char buf[1];
			sprintf (buf, "%d", rpm);
			u8g.drawStr(18, 32, buf);
			Serial.println(rpm);
}
void draw2(void){
		u8g.setFont(u8g_font_gdr25r);
		char buf[1];
		u8g.drawStr(18, 32, "error");
}


void setup() {
	pinMode(3,OUTPUT);
	pinMode(10, OUTPUT);
	pixels.begin(); // This initializes the NeoPixel library.
  
  
    pixels.setPixelColor(0, pixels.Color(255,0,255));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(1, pixels.Color(255,0,255)); 
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(2, pixels.Color(255,0,255));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(3, pixels.Color(255,0,255)); 
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(4, pixels.Color(255,0,255));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(5, pixels.Color(255,0,255)); 
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(6, pixels.Color(255,0,255));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(7, pixels.Color(255,0,255));
  	pixels.show();
    delay(200);
    pixels.setPixelColor(7, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(5, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(3, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(2, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(1, pixels.Color(0,0,0));
  	pixels.show();
    delay(50);
  	pixels.setPixelColor(0, pixels.Color(0,0,0));
  	pixels.show();
  u8g.setFont(u8g_font_tpssb);
  u8g.setColorIndex(1);
  Serial.begin(38400);
  ELM_PORT.begin(38400);
	BTSerial.begin(38400);
  Serial.println("Attempting to connect to ELM327...");
			
}


void loop() {
	if (BTSerial.available())

Serial.write(BTSerial.read());

if (Serial.available())

BTSerial.write(Serial.read());

	if(ELM_PORT.available()){
		BTSerial.write(ELM_PORT.read());
	}
	u8g.firstPage();
	do{
		rpm1();
	}while(u8g.nextPage());
	
  if(rpm > 7000){
    pixels.setPixelColor(0, pixels.Color(255,0,0));
  	pixels.setPixelColor(1, pixels.Color(255,0,0)); 
  	pixels.setPixelColor(2, pixels.Color(255,0,0));
  	pixels.setPixelColor(3, pixels.Color(255,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(255,0,0));
  	pixels.setPixelColor(5, pixels.Color(255,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(255,0,0));
  	pixels.setPixelColor(7, pixels.Color(255,0,0));
    pixels.show();
    delay(100);
    pixels.setPixelColor(0, pixels.Color(0,0,0));
  	pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,0,0));
  	pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));
	pixels.show();
    delay(100);
  }
  else if(rpm > 6500){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
  	pixels.setPixelColor(5, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(6, pixels.Color(255,0,0));
  	pixels.setPixelColor(7, pixels.Color(255,0,0));   
	pixels.show();
  }
  else if(rpm > 6000){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
  	pixels.setPixelColor(5, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(6, pixels.Color(255,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0)); 
    pixels.show();
  }
  else if(rpm > 5500){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
  	pixels.setPixelColor(5, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0)); 
	pixels.show();
  }
    else if(rpm > 5000){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(4, pixels.Color(255,255,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0)); 
	pixels.show();
  }
    else if(rpm > 4000){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(255,255,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));  
	pixels.show();
  }
    else if(rpm > 3000){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,255,0));
  	pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));  
	pixels.show();
  }
    else if(rpm > 2000){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,255,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,0,0));
  	pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));
	pixels.show();
  }
  else if(rpm > 0){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
  	pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,0,0));
  	pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));
	pixels.show();
  }
  else if(rpm = 0){
  	pixels.setPixelColor(0, pixels.Color(0,0,0));
  	pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(2, pixels.Color(0,0,0));
  	pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(4, pixels.Color(0,0,0));
  	pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  	pixels.setPixelColor(6, pixels.Color(0,0,0));
  	pixels.setPixelColor(7, pixels.Color(0,0,0));
  	pixels.show();
  }
}
