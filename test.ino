char serialData;

int bt = 22;
int x;
char val;
int L = 13;
int led = 7;

void setup(){
  // put your setup code here, to run once:
  pinMode(bt, INPUT);
  pinMode(L, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(bt);
  val = char(x);
  
  if(val == HIGH){
    serialData = '1';
    digitalWrite(L,HIGH);
    Serial.print(serialData);
  }
  else if (val == LOW){
    serialData = '0';
    digitalWrite(L,LOW);
    //Serial.print(serialData);
  }
}
