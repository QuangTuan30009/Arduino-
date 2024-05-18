#include <Servo.h> //khai báo thư viện Servo 
Servo myservo; //khai báo myservo để khiển servo 
int servo = 6; //khai báo servo với chân 6 



const int trig = 8; //khai báo trig là chân 8
const int echo = 7;// khai báo echo là chân 7
unsigned long thoigian; // biến thời gian là kiểu số nguyên 
int khoangcach; // khai báo khoảng cách 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //mở cổng serial ở 9600
  pinMode(trig, OUTPUT); //chân trig xuất tín hiệu 
  pinMode(echo, INPUT); //chân echo nhận tín hiệu 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, 0);  //tắt chân trig về LOW
  delayMicroseconds(2); // delay 2 micro giây để đảm bảo chan trig về 0 
  digitalWrite(trig, 1); //đưa chân trig lên HIGH 
  delayMicroseconds(10); // bật xung có độ rộng 10 microseconf 
  digitalWrite(trig, 0); // tắt chân trig 

  thoigian = pulseIn(echo, HIGH); // hàm pluseIn là để đo khoảng thời gian của chân echo từ HIGH cho đến LOW và được lưu vào biến thoigian 
  //pluseIn có thể đo tùy trạng thái từ HIGH về LOW hoặc từ LOW len HIGH, trong trường hợp trên là từ HIGH về LOW
  // sau đó tính khoảng cách đến vật thể (cm)
  // tốc độ âm thanh trong không khí là 340m/s đổi ra là 29,412 microseconds/cm 
  khoangcach = int(thoigian / 2 / 24,412 );
 
  
  if (khoangcach <= 15) // nếu khoảng cách tới vật nhỏ hơn 20cm 
  { Serial.print("có vật");
  myservo.write(180); //servo quay 180 độ 
  } else
  { Serial.print("không có vật");
  myservo.write(0); //servo quay 0 độ 
  }
   //in lên serial 
  Serial.print("khoảng cách: ");
  Serial.print(khoangcach);
  Serial.println("cm");
  delay(500);

}
