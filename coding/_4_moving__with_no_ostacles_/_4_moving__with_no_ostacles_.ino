int x_y_1[100][2],x_y_2[100][2],x_y_3[100][2],x_y_4[100][2];
int x_axis,y_axis; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,time_in_y_axis,wall_distance = 25;
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
begin_moving();
}
void loop() {
check();
turn_left();
move_forward_2(); // deh function lel turn_left wel turn_right
turn_left();
stop_moving();
x_y_4[begins][0] = x_axis;
x_y_4[begins][1] = y_axis;
move_forward();
check();
ends=begins+1;
x_y_3[ends][0] = x_axis;
x_y_3[ends][1] = y_axis;
turn_right();
move_forward_2(); // deh function lel turn_left wel turn_right
turn_right();
stop_moving();
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
  analogWrite(in1,LOW);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn);
  }
void turn_right(){
  analogWrite(in1,speeds);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn);
  }
void stop_moving(){
  analogWrite(in1,LOW);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_turn); 
  }
void  move_forward(){
while(1){
  
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
distance1 = ultra_sonic();
if(distance1 <= wall_distance){
  stop_moving();
  break;
  }
}
         //postion();
         //direction_axis();
  }
void move_forward_2(){
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(time_in_y_axis);
  }
void check(){
  distance2 = ultra_sonic();
  distance3 = ultra_sonic();
  if(distance1 < wall_distance &&( distance2 < wall_distance || distance2 < wall_distance)){
    while(1){
      stop_moving();
      }
    }
  }
