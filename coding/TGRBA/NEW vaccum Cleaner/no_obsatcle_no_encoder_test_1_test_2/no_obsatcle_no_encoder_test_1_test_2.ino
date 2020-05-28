int trigPin1 =7,echoPin1 =8,trigPin2 =5,echoPin2 =13,trigPin3 =3, echoPin3 =4;
int in1 = 10, in2 = 9,in4 = 11, in3= 6;
float distance , duration,distance1, distance2,distance3;
int wall_distance = 20;
int speeds = 40;
int time_to_turn = 310 , time_to_stop = 5000 , time_in_y_axis = 1000 , average;

void setup() {
  pinMode(trigPin1, OUTPUT);pinMode(echoPin1, INPUT);pinMode(trigPin2, OUTPUT);pinMode(echoPin2, INPUT);pinMode(trigPin3, OUTPUT);pinMode(echoPin3, INPUT);
  pinMode(in1, OUTPUT);pinMode(in2, OUTPUT);pinMode(in3, OUTPUT);pinMode(in4, OUTPUT);
  Serial.begin(9600); 
  delay(10000);
}


void loop() {
//  distance1=ultra_sonic(trigPin1, echoPin1);distance3=ultra_sonic(trigPin2, echoPin2);distance2=ultra_sonic(trigPin3, echoPin3);
move_forward();

turn_left(); move_forward_2(); turn_left(); move_forward();

turn_right(); move_forward_2(); turn_right();
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
  while(1){
  Serial.println(distance1);
distance1=ultra_sonic(trigPin1, echoPin1);
if(distance1 <= wall_distance && distance>0){
  move_stop(); 
  average = 0;
  for(int i = 0 ; i<10 ; i++){
  distance1 = ultra_sonic(trigPin1, echoPin1);
  average = average + distance1 ;
  delay(50);// 500 for debuing
  }
  average = average/10 ;
      Serial.println("average = ");
    Serial.println(average);
  if(average < wall_distance ){ 
  break;
    }
    //delay(5000); for debujing only
}
}
  }
void turn_right(){ 
digitalWrite(in1,LOW);
analogWrite(in4,60);
analogWrite(in2,60);
digitalWrite(in3,LOW);
  delay(time_to_turn);
   move_stop(); 
  }
void turn_left(){
analogWrite(in1,60);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
analogWrite(in3,60);
  delay(time_to_turn);
   move_stop();
  }
void move_stop(){
  analogWrite(in1,LOW);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
 delay(time_to_stop);
  }
void move_forward_2(){
      
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_in_y_axis);
   move_stop(); 
  }
