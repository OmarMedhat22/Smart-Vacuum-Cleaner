 int trigPin1 =7; 
int echoPin1 =8;
int trigPin2 =5;
int echoPin2 =6;
int trigPin3 =3;
int echoPin3 =4;
int in1 = 10;
int in2 = 12;
int in4 = 11;
int in3= 13;
float distance ;
float duration ;
int wall_distance = 20;
int speeds = 40;
int time_to_turn = 500;

float  distance1, distance2,distance3;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
//  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 // pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  
}




void loop() {
  distance1=ultra_sonic(trigPin1, echoPin1);
  distance3=ultra_sonic(trigPin2, echoPin2);
  distance2=ultra_sonic(trigPin3, echoPin3);
  Serial.println(distance1);

move_forward();

if (distance1 < wall_distance)  {
   
 move_stop();
 
   if (distance2 < wall_distance)  {
                              
    if  (distance3 < wall_distance) { 
 move_stop();
    }                                           
    else { turn_left(); }
                                          }                               
else{
turn_right();

  } 
                 }
                            
 }
 float ultra_sonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
   return distance = duration * 0.034 / 2 ;
}
void move_forward(){
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  }
void turn_right(){
    analogWrite(in1,speeds);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn);
  }
void turn_left(){
  analogWrite(in1,LOW);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn);
  }
void move_stop(){
  analogWrite(in1,LOW);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn);  
  }

