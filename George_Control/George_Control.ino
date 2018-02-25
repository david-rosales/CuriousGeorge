#include <Servo.h>

Servo left_grab;
Servo right_grab;
Servo pick_up;
String command;
int left_pin = 2;
int right_pin = 6;
int lift_pin = 3;
int motorL_f = 9;
int motorL_r = 10;
int motorR_f = 5;
int motorR_r = 4;
int pos_l_grab = 90;
int pos_l_ungrab = 135;
int pos_r_grab = 90;
int pos_r_ungrab = 45;
int pos_lift = 135;
int pos_unlift = 45;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left_grab.attach(left_pin);
  right_grab.attach(right_pin);
  pick_up.attach(lift_pin);
  pinMode(motorL_f, OUTPUT);
  pinMode(motorL_r, OUTPUT);
  pinMode(motorR_f, OUTPUT);
  pinMode(motorR_r, OUTPUT);
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
      //Serial.print();
    }
    else if (command == "reverse") {
      reverse();
      //Serial.print();
    }
    else if (command == "right") {
      right();
      //Serial.print();
    }
    else if (command == "left") {
      left();
      //Serial.print();
    }
    else if (command == "stop") {
      stop();
    }
    delay(10); //is this necessary?
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

void stop() {
	analogWrite(motorL_f, 0);
	analogWrite(motorL_r, 0); 
	analogWrite(motorR_f, 0); 
	analogWrite(motorR_r, 0); 
}

void forward() {
  stop();
  analogWrite(motorL_f, 100);
  analogWrite(motorR_f, 100);
  //either need a way of doing feedback on this while it's moving forward/turning, or need to just make it move in little spurts
  //also with the way this is currently written, the car won't ever stop 
}

void reverse() {
  stop();
  analogWrite(motorL_r, 100);
  analogWrite(motorR_r, 100);
}

void right() {
  stop();
  analogWrite(motorL_f, 100);
  analogWrite(motorR_r, 100);
}

void left() {
  stop(); 
  analogWrite(motorL_r, 100);
  analogWrite(motorR_f, 100);
}
