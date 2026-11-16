#include <Servo.h>
Servo servo;

int IR = 8;
int LED = 2;

void setup() {
  servo.attach(9);
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int sensorStatus = digitalRead(IR);
  if (sensorStatus == 0) {
    digitalWrite(LED, HIGH);
    servo.write(0);
    delay(350);
    servo.write(90);
    delay(350);
  } else {
    digitalWrite(LED, LOW);
  }
}
