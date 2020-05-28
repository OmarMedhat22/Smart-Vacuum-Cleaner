int x_y_1[50][2],x_y_2[50][2],x_y_3[50][2],x_y_4[50][2];
int x_axis,y_axis; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,wall_distance = 25,duration,distance;
int begins = -1; //deh le x1,x2,y1,y2 
int ends ; /* deh le x3,x4,y3,y4 */
int trigPin1 =7,echoPin1 =8,trigPin2 =5,echoPin2 =13,trigPin3 =3, echoPin3 =4;
int in1 = 10, in2 = 9,in4 = 11, in3= 6;
int speeds = 40;
int time_to_turn = 310 , time_to_stop = 5000 , time_in_y_axis = 1000 , average = 0;


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
   begin_moving();
}

void loop() {
//check();
turn_left();
move_forward_2(); // deh function lel turn_left wel turn_right
turn_left();
x_y_4[begins][0] = x_axis;
x_y_4[begins][1] = y_axis;
move_forward();
//check();
ends=begins+1;
x_y_3[ends][0] = x_axis;
x_y_3[ends][1] = y_axis;
turn_right();
move_forward_2(); // deh function lel turn_left wel turn_right
turn_right();
x_y_4[begins][0] = x_axis;
x_y_4[begins][1] = y_axis;
move_forward();
x_y_3[ends][0] = x_axis;
x_y_3[ends][1] = y_axis;
}
void begin_moving(){
begins++;
x_y_1[begins][0] = x_axis;
x_y_1[begins][1] = y_axis;
move_forward();
  x_y_2[begins][0] = x_axis;
  x_y_2[begins][1] = y_axis;
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
void turn_left(){
 
analogWrite(in1,60);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
analogWrite(in3,60);
  delay(time_to_turn);
   move_stop();
  }
void turn_right(){
digitalWrite(in1,LOW);
analogWrite(in4,60);
analogWrite(in2,60);
digitalWrite(in3,LOW);
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
void  move_forward(){
while(1){
  
  analogWrite(in1,speeds);
  analogWrite(in4,58);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  distance1=ultra_sonic(trigPin1, echoPin1);
  Serial.println(distance1);
if(distance1 <= wall_distance && distance1 > 0){
  move_stop();
  average = 0;
  for(int i = 0 ; i<10 ; i++){
  distance1=ultra_sonic(trigPin1, echoPin1);
  average = average + distance1 ;
   delay(50);
  }
  average = average/10 ;
  if(average < wall_distance ){ 
  break;
    }
  }
}
         //postion();
         //direction_axis();
  }
void move_forward_2(){
      
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
      delay(time_in_y_axis);
         move_stop(); 

  }
void check(){
  distance3=ultra_sonic(trigPin2, echoPin2);
  distance2=ultra_sonic(trigPin3, echoPin3);
  if(distance1 < wall_distance &&( (distance2 < wall_distance && distance2 >0 ) || (distance3 < wall_distance && distance3 >0 ) )){
    while(1){
      move_stop();
      }
    }
  }
