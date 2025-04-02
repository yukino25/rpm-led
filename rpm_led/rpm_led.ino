
int green_led1 = 9;
int green_led2 = 8;
int green_led3 = 7;
int yellow_led1 = 6;
int yellow_led2 = 5;
int yellow_led3 = 4;
int red_led1 = 3;
int red_led2 = 2;
const int button = 13;
int button_state = 0;
int rpm = 900;
#include "U8glib.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);


void setup() {
  // put your setup code here, to run once:
pinMode(green_led1,OUTPUT);
pinMode(green_led2,OUTPUT);
pinMode(green_led3,OUTPUT);
pinMode(yellow_led1,OUTPUT);
pinMode(yellow_led2,OUTPUT);
pinMode(yellow_led3,OUTPUT);
pinMode(red_led1,OUTPUT);
pinMode(red_led2,OUTPUT);
pinMode(button, INPUT);
  u8g.setFont(u8g_font_tpssb);
  u8g.setColorIndex(1);
Serial.begin(9600);
}

void loop() {
  u8g.firstPage(); 
 do {
u8g.setFont(u8g_font_gdr25r);

char buf[1];
sprintf (buf, "%d", rpm);
u8g.drawStr(18, 32, buf);

  } while( u8g.nextPage() );


  button_state = digitalRead(button);
  if (button_state == HIGH){
    if(rpm < 7300){
      rpm += 50;
      delay(15);
    }
    else if( rpm > 7300){
      rpm - (rpm - 7300);
    }
  }
  else if (button_state == LOW){
    if (rpm > 900){
      rpm -= 50;
      delay(15);
    }
    else if (rpm < 900) {
      rpm + (900 - rpm);
    }
  }
  Serial.print(rpm);
  if(rpm > 7000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, HIGH);
    digitalWrite(red_led1, HIGH);
    digitalWrite(red_led2, HIGH);
    delay(100);
    digitalWrite(green_led1, LOW);
    digitalWrite(green_led2, LOW);
    digitalWrite(green_led3, LOW);
    digitalWrite(yellow_led1, LOW);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
    delay(100);
  }
  else if(rpm > 6500){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, HIGH);
    digitalWrite(red_led1, HIGH);
    digitalWrite(red_led2, HIGH);   
  }
  else if(rpm > 6000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, HIGH);
    digitalWrite(red_led1, HIGH);
    digitalWrite(red_led2, LOW);
  }
  else if(rpm > 5500){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, HIGH);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }
    else if(rpm > 5000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
    
  }
    else if(rpm > 4000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }
    else if(rpm > 3000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, LOW);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }
    else if(rpm > 2000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, LOW);
    digitalWrite(yellow_led1, LOW);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }
  else if(rpm > 0){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, LOW);
    digitalWrite(green_led3, LOW);
    digitalWrite(yellow_led1, LOW);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }
  else{
    digitalWrite(green_led1, LOW);
    digitalWrite(green_led2, LOW);
    digitalWrite(green_led3, LOW);
    digitalWrite(yellow_led1, LOW);
    digitalWrite(yellow_led2, LOW);
    digitalWrite(yellow_led3, LOW);
    digitalWrite(red_led1, LOW);
    digitalWrite(red_led2, LOW);
  }

}