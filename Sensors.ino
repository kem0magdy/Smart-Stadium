#include <Servo.h>
//Waterpump
const int IN1=10;
const int IN2=11;
const int ENA=5;
//FAN
const int IN3=8;
const int IN4=7;
const int ENB=6;
#define Smoke A0
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
#define FLAME A3
// servo motor of water level 
#define servo_water_level 13
Servo servo_water_L;

void setup() {
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(FLAME,INPUT);
pinMode(Smoke,INPUT);
servo_water_L.attach(servo_water_level);

servo_water_L.write(0);
  Serial.begin(9600);

}

void loop() {
int ReadSmoke=analogRead(Smoke);
if(ReadSmoke >=450)
{
  Serial.println("Smoke detected ! Take Action");
  Serial.println(analogRead(Smoke));
  analogWrite(ENB,255);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(3000);

}
else {
  Serial.println("NO Smoke Detecetd");
 analogWrite(ENB,0);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}
delay(200);

  int sensorReading = analogRead(A3);
if(sensorReading >=62 )
{
  Serial.println("Flame detected ! Take Action");
  Serial.println(analogRead(A3));
  analogWrite(ENA,255);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
delay(1000);

}
else {
  Serial.println("NO Flame Detecetd");
 analogWrite(ENA,0);
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
}
delay(200);


int water_L = analogRead(A2);

  if (water_L > 500) {
    Serial.println("Very heavy Rain");
    servo_water_L.write(90);
  }
  else if ((water_L > 300) && (water_L <= 500))
  {
    Serial.println("AVERAGE Rain");
    servo_water_L.write(0);
}
  Serial.println( "   Smoke    " );
 Serial.println( analogRead(Smoke));
 delay(200);
 
  Serial.println( "   Water Level    " );
  Serial.println(analogRead(A2));
   delay(200);
 Serial.println("FLAME");
 Serial.println(analogRead(A3));
  delay(200);


}
