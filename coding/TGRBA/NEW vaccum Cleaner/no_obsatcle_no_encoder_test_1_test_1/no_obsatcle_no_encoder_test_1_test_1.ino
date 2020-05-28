int x_y_1[100][2],x_y_2[100][2],x_y_3[100][2],x_y_4[100][2];
int x_axis,y_axis; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,time_in_y_axis,wall_distance = 25,duration,distance,average;
int begins = -1; //deh le x1,x2,y1,y2 
int ends ; /* deh le x3,x4,y3,y4 */
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
int speeds = 40;
int time_to_turn = 500;

void setup() {
  // put your setup code here, to run once:
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

}

void loop() {
move_forward();
}

void  move_forward(){
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
while(1){
  
  Serial.println(distance1);
if(distance1 <= wall_distance && distance>0){
  average = 0;
  for(int i = 0 ; i<10 ; i++){
  distance1=ultra_sonic(trigPin1, echoPin1);
  average = average + distance1 ;
  }
  average = average/10 ;
  if(average < wall_distance ){ 
  break;
    }
}
         //postion();
         //direction_axis();
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
void stop_moving(){
  analogWrite(in1,LOW);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn); 
  }
