#include <Servo.h>
Servo servo;
int trigger_pin = 1;
int echo_pin = 2;
int pos = 0; 
int time;
int distance; 
void setup() 
{
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        servo.attach(P2_1);
}
void loop() 
{
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance>=3 && distance <= 10) 
        {   
        rotate(180);
        }
  else {       
        rotate(180);       
       } 
}

void rotate(int angle)
{
  for(pos=0;pos<=angle;pos++)
  {
    servo.write(pos);
    delay(15);
  }
  delay(1000);
 
  for(pos=angle;pos>=0;pos--)
  {
    servo.write(pos);
    delay(15);
  }
  delay(1000);
}
