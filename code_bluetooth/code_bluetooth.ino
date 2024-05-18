#include <Servo.h>          // Thư viện điều khiển Servo
#include <SoftwareSerial.h> // Thư viện tạo chân serial 

SoftwareSerial Bl_car(A2, A3); //Tạo chân serial riêng
Servo myservo;


#define in1 9 //L298n Motor Driver pins.
#define in2 10
#define in3 11
#define in4 12

#define LED 13

#define pwm_1 5  // Speed motor
#define pwm_2 6

int command;
int Speed = 250;

char servo_compare = 'B';
char servo_compare_s = 'A';
void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT); //Set the LED pin.

  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);

  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  Bl_car.begin(9600);
  myservo.attach(3);
  myservo.write(180);
  delay(2000);
  myservo.write(80);

  analogWrite(pwm_1, Speed);
  analogWrite(pwm_2, Speed);
}

void loop() {
  //  forward();
  //  delay(10000);

  if (Bl_car.available() > 0) {
    command = Bl_car.read();
    Serial.println(command);
    Stop();

    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 105;
        break;
      case '2':
        Speed = 110;
        break;
      case '3':
        Speed = 130;
        break;
      case '4':
        Speed = 150;
        break;
      case '5':
        Speed = 170;
        break;
      case '6':
        Speed = 190;
        break;
      case '7':
        Speed = 210;
        break;
      case '8':
        Speed = 220;
        break;
      case '9':
        Speed = 230;
        break;
      case 'q':
        Speed = 255;
        break;
      case 'X':
        servocar(180);
        break;
      case 'x':
        servocar(80);
        break;
    }
    analogWrite(pwm_1, Speed);
    analogWrite(pwm_2, Speed);
  }
 
}

void servocar(int uni) {
  myservo.write(uni);
  if (uni == 80) {
    servo_compare_s = 'A';
    if (servo_compare != servo_compare_s) {
      myservo.write(uni);
      servo_compare_s = 'B';
    }
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}

void back() {
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in4, HIGH);
  digitalWrite(in1, HIGH);
}

void right() {
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
}
void forwardleft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW);
}
void forwardright() {
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
}
void backright() {
  digitalWrite(in2, HIGH);
  digitalWrite(in4, LOW);
}
void backleft() {
  digitalWrite(in2, LOW);
  digitalWrite(in4, HIGH);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

