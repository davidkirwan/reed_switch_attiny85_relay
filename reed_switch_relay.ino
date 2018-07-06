/**
 * Reed Switch Activated Relay Control Circuit Sketch
 * 
 * Circuit: https://imgur.com/a/s5n3a
 * Github: https://github.com/davidkirwan/
 * Version: 0.1.0
 */

#define PIN_IN  3
#define PIN_OUT 0

void long_delay(int wait){
  int w = 0;
  while(w < wait){
    delay(1000); 
    w++;
  }
}

void activate() {
  //Serial.println("activate");
  digitalWrite(PIN_OUT, LOW);
  long_delay(60); // 1 min 
}

void setup(){
  //Serial.begin(9600);
  pinMode(PIN_IN, INPUT);
  pinMode(PIN_OUT, OUTPUT);
  digitalWrite(PIN_OUT, HIGH);  
  delay(5000);
}

void loop(){
  delay(250);
  int val = digitalRead(PIN_IN);
  //Serial.println(val);
  //Serial.println("first");
  if(val == 1){
    delay(250);
    val = digitalRead(PIN_IN);
    //Serial.println(val);
    //Serial.println("second");  
    if(val == 1){
      activate();
    }
  }
  else {
    digitalWrite(PIN_OUT, HIGH);
  }
}
