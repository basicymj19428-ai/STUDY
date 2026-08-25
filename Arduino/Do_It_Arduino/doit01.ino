void setup()  //전원이 들어오면 가장 먼저 한번 실행
{
  pinMode(13, OUTPUT);  //13번 핀을 출력모드로 선언
}

void loop()  //마이크로초 주기로 반복 실행
{
  digitalWrite(13, HIGH);  //13번 핀에 HIGH 신호를 보냄
  delay(1000);  //1초 지연
  digitalWrite(13, LOW);  //13번 핀에 LOW 신호를 보냄
  delay(1000);  //1초 지연
}