#include <AltSoftSerial.h>


AltSoftSerial BTSerial(8, 9); // RX, TX

void setup() {

Serial.begin(38400);

pinMode(10,OUTPUT); digitalWrite(10,HIGH);

Serial.println("Enter AT commands:");

BTSerial.begin(38400);

}

void loop()

{

if (BTSerial.available())

Serial.write(BTSerial.read());

if (Serial.available())

BTSerial.write(Serial.read());

}