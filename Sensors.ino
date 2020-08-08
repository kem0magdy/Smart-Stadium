#include <Servo.h>
#define servo_water_level 13
Servo servo_water_L;

void setup() {
  // put your setup code here, to run once:
servo_water_L.attach(servo_water_level);

servo_water_L.write(0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    servo_water_L.write(90);
delay(2000);
    servo_water_L.write(0);
delay(2000);



}
