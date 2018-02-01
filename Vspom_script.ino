

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void whatnumber() {
  if (Serial.available()>0) {
    bool data = 0;
    char wn1 = Serial.read();
    String message;
    if (wn1 != '\n'){
      message += wn1;
      data = 1;
    }
    if (data == 1){
   Serial.print("FUCK YOU DUNY THE CODE IS:");
   Serial.print(message);
   data=0;}
   
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  whatnumber();
}
