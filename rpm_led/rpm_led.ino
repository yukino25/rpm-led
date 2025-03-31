int green_led1 = 9;
int green_led2 = 8;
int green_led3 = 7;
int yellow_led1 = 6;
int yellow_led2 = 5;
int yellow_led3 = 4;
int red_led1 = 3;
int red_led2 = 2;




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
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int rpm = atoi(recievedstring);
  int rpm = 0;
  Serial.print(rpm);
  if(Serial.available() > 0){
    String receivedstring = "";
    while(Serial.available() > 0){
      receivedstring += char(Serial.read());
    }
  }
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
  }
  else if(rpm > 5500){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
    digitalWrite(yellow_led3, HIGH);
  }
    else if(rpm > 5000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
    digitalWrite(yellow_led2, HIGH);
  }
    else if(rpm > 4000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
    digitalWrite(yellow_led1, HIGH);
  }
    else if(rpm > 3000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(green_led3, HIGH);
  }
    else if(rpm > 2000){
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
  }
  else if(rpm > 0){
    digitalWrite(green_led1, HIGH);
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