char serialData;

//int bt = 22;
int val;
int L = 13;
int led = 7;

void setup(){
  // put your setup code here, to run once:
  //pinMode(bt, INPUT);
  pinMode(L, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    serialData = Serial.read();
    Serial.print(serialData);

    if(serialData == '1'){
      digitalWrite(L,HIGH);
      digitalWrite(led, HIGH);
    }
    else if (serialData == '0'){
      digitalWrite(L,LOW);
      digitalWrite(led, LOW);
    }
  }
}
