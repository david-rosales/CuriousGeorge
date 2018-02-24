#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;// a maximum of eight servo objects can be created
Servo myservo3;
int pos = 0;
//int pos1 = 0;    // variable to store the servo position
//int pos2 = 0;
//int pos3 = 0;
void setup() {
 myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
 myservo2.attach(9);
 myservo3.attach(11);
 Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  while (Serial.available() == 0)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  int val = Serial.read() - '@';
  Serial.println(val);
 for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
 {                                  // in steps of 1 degree
    myservo2.write(pos);              
    delay(1);
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
    
    myservo3.write(pos);              
    delay(1);
 }
 for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
 {
    myservo2.write(pos); 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    
    myservo3.write(pos); 
    delay(1);                       // waits 15ms for the servo to reach the position
 }
//myservo1.write(pos);
//pos = pos+1;
//delay(20);
}
