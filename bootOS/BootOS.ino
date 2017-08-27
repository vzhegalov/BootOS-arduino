String message;
int bootline;
int bootcomplete;
int wasd;
int command;

void setup() {
  Start:
  pinMode(12,INPUT_PULLUP);
  Serial.begin(9600);
  boot(0);
}
int boot(bool def){
  if(bootcomplete==0);
  Serial.println("KERNEL_SETUP:");
  delay(100);
  Serial.println("CORE:ONLINE");
  delay(1000);
  Serial.println("PORTS:NOMINAL");
  Serial.println("NETWORK_STATUS:");
  if(def==0){
    Serial.println("OFFLINE.BOOT CANNELED");
    bootline=22111;
    bootcomplete=1;
  }
  if(def==1){
    Serial.println("ONLINE");
    delay(100);
    Serial.println("MONITOR:NOMINAL AND WORKING");
    Serial.println("OS INIT().BOOT COMPLETE");
    bootline=22222;
    bootcomplete=1;
  }
}
  
void loop() {
  // put your main code here, to run repeatedly:
 while (Serial.available()) {  
    char incomingChar = Serial.read();
    if (incomingChar >= '0' && incomingChar <= '9') {
      if(incomingChar=='2'){
          Serial.print("BOOTLINE:");
          Serial.print(bootline);
      }
      if(incomingChar=='1'){
        Serial.print("COMMANDS:");
        Serial.println("1-HELP");
        Serial.println("2-BOOTLINE-FOR VIEWING LAST BOOT STATUS");}
      Serial.println("PRESS ENTER TO CLEAR COMMAND PROMPT");
    }
}
bool buttonIsUp = digitalRead(12);
 if (buttonIsUp==0) {
    delay(10);
    // ...и считываем сигнал снова
    buttonIsUp = digitalRead(12);
    if (buttonIsUp==0) { 
     Serial.println("REBOOT");
     Serial.println("Network safety STATUS:ON");
     Serial.println("CLEAR OUTPUT");
     delay(2000);
     boot(1);
     delay(2000);
    }
  }
}
