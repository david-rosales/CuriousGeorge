#include <Servo.h>

Servo left_grab;
Servo right_grab;
Servo pick_up;
String command;
int left_pin = 2;
int right_pin = 6;
int lift_pin = 3;
int pos_l_grab = 87;
int pos_l_ungrab = 135;
int pos_r_grab = 93;
int pos_r_ungrab = 45;
int pos_lift = 135;
int pos_unlift = 40;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left_grab.attach(left_pin);
  right_grab.attach(right_pin);
  pick_up.attach(lift_pin);
  left_grab.write(pos_l_ungrab);
  right_grab.write(pos_r_ungrab);
  pick_up.write(pos_unlift);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()> 0) {
    command = Serial.readString();
    Serial.println(command);
    if (command == "grab") {
      grab();
      //need a delay here to give it time to act? not really sure if the code proceeds immediately 
      //after it gives the servo command or if it waits til the servos get to their commanded pose
      Serial.println("grabbed");
      //should this be Serial.println()? not sure if the newline character would mess it up or if it's
      //necessary to keep it from reading longer and longer strings
      //probably going to switch to numbers anyway so whatever
    }
    else if (command == "ungrab") {
      ungrab();
      Serial.println("ungrabbed");
    }
    else if (command == "lift") {
      lift();
      Serial.println("lifted");
    }
    else if (command == "unlift") {
      unlift();
      Serial.println("unlifted");
    }
    delay(10);
  }
}

void grab() {
  int pos_l = pos_l_ungrab;
  int pos_r = pos_r_ungrab;
  for (pos_l = pos_l_ungrab; pos_l >= pos_l_grab; pos_l-=1) {
      pos_r +=1;  
      left_grab.write(pos_l);
      right_grab.write(pos_r);
      delay(50);
    }
  }

void ungrab() {
  int pos_l = pos_l_grab;
  int pos_r = pos_r_grab;
  for (pos_l = pos_l_grab; pos_l <= pos_l_grab; pos_l+=1) {
    pos_r-=1;
    left_grab.write(pos_l);
    right_grab.write(pos_r);
    delay(50);
  }
  
}

void lift() {
  int pos = pos_unlift;
  for (pos = pos_unlift; pos <= pos_lift; pos +=1) {
    pick_up.write(pos);
    delay(50);  
  }
}

void unlift() {
  int pos = pos_lift;
  for (pos = pos_lift; pos >= pos_unlift; pos-=1) {
    pick_up.write(pos);
    delay(50);
  }
}
