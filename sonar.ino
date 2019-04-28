#define echoPin 5 //echopin
#define trigPin 4 //trigger Pin
#define LEDPin 13 //alert light

#define L1 6 
#define L2 7
#define L3 8
#define L4 9

int maxRange = 60;
int minRange = 0;
int base = 10;
long duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
 }

/* FUNCTIONS */
int based(int distance){                 
    int x;                                
    x = distance / base;                  
    return x;                             
 }                                       

void uno(void){                           
   digitalWrite(L1,HIGH);                
   digitalWrite(L2,LOW);                  
   digitalWrite(L3,LOW);                  
   digitalWrite(L4,LOW);                                                   
}                                         
void dos(void){                          
  digitalWrite(L1,HIGH);                  
  digitalWrite(L2,HIGH);                  
  digitalWrite(L3,LOW);                   
  digitalWrite(L4, LOW);                  
}                                         
void tres(void){                          
  digitalWrite(L1,HIGH);                  
  digitalWrite(L2,HIGH);                  
  digitalWrite(L3,HIGH);                  
  digitalWrite(L4, LOW);                  
  }                                       
void quat(void){                          
  digitalWrite(L1,HIGH);                  
  digitalWrite(L2,HIGH);                  
  digitalWrite(L3,HIGH);                  
  digitalWrite(L4,HIGH);                  
}                                       

/* END FUNCTIONS */ 

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //starts timing when LOW to HIGH -- then times until push LOW

  //distance in cm based on the speed of sound
  distance = duration/58.2;
  
  
  int nDist = based(distance);
  
  if (distance >= maxRange || distance <= minRange){
    Serial.print("-1");
    digitalWrite(LEDPin, HIGH);
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW);
    digitalWrite(L4,LOW);
  }
  else {
    Serial.println(distance);
    digitalWrite(LEDPin,LOW);
    if(nDist <= 2){
      uno();
    }
    if(nDist >2 && nDist<=3){
      dos();
    }
    if(nDist >3 && nDist<=4){
      tres();
    }
    if(nDist >4 && nDist<=5){
      quat();
    }
  }
  delay(50);
}
