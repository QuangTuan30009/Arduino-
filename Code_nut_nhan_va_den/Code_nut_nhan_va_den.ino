  int led1 = 13; // Chân 13 điều khiển đèn 1 //
  int led2 = 12; // chân 12 điều khiển đèn 2//
  int led3 = 11; // chán 11 điều khiển đèn 3//
  int button1 = 2 // chân D2 điều khiển nút nhấn 1//
  int button2 = 4 // chân D4 điều khiển nút nhấn 2//
  int buttonState1 = 0; //trạng thái nút nhấn 1//
  int lastButtonState1 = LOW; // trạng thái trước đó của nút nhấn 1 // 
  unsigned long lastDebounceTime = 0; // trạng thái trước đó//

void setup() {
  // thiết lập các chân digital là OUTPUT//
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  // thiết lập nút nhấn là INPUT//
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
 
}

void loop() {
   int  = digitalRead(button1);
    // Nút  được nhấn//
    if(buttonState1 = HIGH) { // nếu là lần nhấn thứ nhất//
      if (led1State == LOW) {
        // bật đèn 1 //
        led1State = HIGH;
        digitalWrite(led1,HIGH);
      } //nếu là lần nhấn thứ 2//
       else {
        led1State = LOW;
        digitalWrite(led1,LOW);
      }
    }
  int reading1 = digitalRead(butto1); // đọc trạng thái nút nhấn 1 //
  // kiểm tra xem nút nhấn có thay đổi trạng thái ko//
  if (reading1 != lastButtonSteate) {
    lastDenounceTime = millis(); 
  }
  // kiểm tra xem có giữ nút trong 1 giây không //
  if ((millis() - lastDebuonceTime) > 1000) {
    if (reading1 == HIGH) {
      // nếu đã giữ 1s, thì thực hiện bật tắt led //
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
    }
    // reset thời gian trước đó //
    lastDebounceTime = millis();
  }
  // lưu trạng thái nút nhấn 1 //
  lastButtonState1 = reading1;
  // kiểm tra nút nhấn 2//
  int buttonState2 = digitalRead(button2);
  // nếu nút 2 được nhấn//
  if(led2State == LOW) {
    // bật đèn 2//
    led2State = HIGH;
    digitalWrite(led2,HIGH);
  }
  // đọc trạng thái cả 2 nút nhấn//
  int buttonState1And2 = digitalRead(button1) && digitalRead(button2); 
  // nếu cả 2 nút được nhấn //
  if (buttonState1And2 == HIGH) {
    // nháy cả 3 đèn 5 lần //
    for (int i = 0; i < 5; i++) {
      digitalWrite(led1,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(led1,HIGH);
      delay(1000);
      digitalWrite(led1,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led1,LOW);
      delay(1000);

    }
    // chờ 1 giây trước khi lặp lại 
    delay(1000);
  }
}
