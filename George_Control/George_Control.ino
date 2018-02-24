#include <Servo.h>

Servo left_grab;
Servo right_grab;
Servo pick_up;
//Motor left;
//Motor right;
String command;
int left_pin = 0;
int right_pin = 1;
int lift_pin = 2;
int pos_l_grab = 0;
int pos_l_ungrab = 0;
int pos_r_grab = 0;
int pos_r_ungrab = 0;
int pos_lift = 0;
int pos_unlift = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left_grab.attach(left_pin);
  right_grab.attach(right_pin);
  pick_up.attach(lift_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()> 0) {
    command = Serial.readString();
    if (command == "grab") {
      grab();
      //need a delay here to give it time to act? not really sure if the code proceeds immediately 
      //after it gives the servo command or if it waits til the servos get to their commanded pose
      Serial.print("grabbed");
      //should this be Serial.println()? not sure if the newline character would mess it up or if it's
      //necessary to keep it from reading longer and longer strings
      //probably going to switch to numbers anyway so whatever
    }
    else if (command == "ungrab") {
      ungrab();
      Serial.print("ungrabbed");
    }
    else if (command == "lift") {
      lift();
      Serial.print("lifted");
    }
    else if (command == "unlift") {
      unlift();
      Serial.print("unlifted");
    }
    else if (command == "forward") {
      forward();
      Serial.print();
    }
    else if (command == "right") {
      right();
      Serial.print();
    }
    else if (command == "left") {
      left();
      Serial.print();
    }
    delay(10) //is this necessary
  }
}

void grab() {
  left_grab.write(pos_l_grab);
  right_grab.write(pos_r_grab);
}

void ungrab() {
  left_grab.write(pos_l_ungrab);
  right_grab.write(pos_r_ungrab);
}

void lift() {
  pick_up.write(pos_lift);
}

void unlift() {
  pick_up.write(pos_unlift);
}

void forward() {
  
}

void right() {
  
}

void left() {
  
}
