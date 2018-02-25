#include <Servo.h>

bool reading = false;
char inData[10]; // Allocate some space for the string, maximum 10
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character

void setup() {
 Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  while(Serial.available() > 0) // Don't read unless
 {
   reading = true;
   if(index < 10) // One less than the size of the array
   {
     inChar = Serial.read(); // Read a character
     inData[index] = inChar; // Store it
     index++; // Increment where to write next
     inData[index] = '\0'; // Null terminate the string
   }
 }
   if(Serial.available() == 0 && reading)
   {
    Serial.print(inData);
    for(int i =0;i<10;i++)
    {inData[i] = "";}
    reading = false;
    index = 0;
   }
}
