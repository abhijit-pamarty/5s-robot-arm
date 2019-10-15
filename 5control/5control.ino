#include<Servo.h>

Servo ser_1, ser_2, ser_3, ser_4, ser_5;

#define ser_pin_1 3
#define ser_pin_2 4
#define ser_pin_3 5
#define ser_pin_4 6
#define ser_pin_5 7


#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A4
#define pot5 A5


void setup() {
  ser_1.attach(ser_pin_1);
  ser_2.attach(ser_pin_2);
  ser_3.attach(ser_pin_3);
  ser_4.attach(ser_pin_4);
  ser_5.attach(ser_pin_5);


  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);
  pinMode(pot5, INPUT);

  Serial.begin(9600);

}

int control_servo(Servo servo,int pot_pin) //function to control a servo
{
  float value = analogRead(pot_pin);
  value =(value/1023)*180;
  value = int(value);
  servo.write(value);
  Serial.println(value);
}



void loop() {
  control_servo(ser_1, pot1);
  control_servo(ser_2, pot2);
  control_servo(ser_3, pot3);
  control_servo(ser_4, pot4);
  control_servo(ser_5, pot5);
  delay(10);

}
