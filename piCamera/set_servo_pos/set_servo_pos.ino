
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  380 //Minimum pulse width, i.e. 0%
#define SERVOMAX  500 //Maximum pulse width, i.e. 1000%


void setup() {
  //Start serial connection
  Serial.begin(9600);
  //Open I2C connection to PWM Driver
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}


//Calculates pulse length from percentage input
int getPulseLen(int input){
 float scale = SERVOMAX-SERVOMIN;
 return ((float)input/100.0) * scale + SERVOMIN;
 
}

void loop() {
  
  if (Serial.available() > 0){
    while (Serial.available() > 0){
      digitalWrite(13,LOW);
      char a  = Serial.read();
      Serial.write(a);
      if (a == 'a'){
        digitalWrite(13,HIGH);       
       int top = Serial.read()-48; 
       int bottom = Serial.read()-48;
       Serial.print(getPulseLen(top*10+bottom));
       Serial.print("\n");
       pwm.setPWM(0, 0, getPulseLen(top*10+bottom));
      }
    }  
  }
  delay(100);
}
