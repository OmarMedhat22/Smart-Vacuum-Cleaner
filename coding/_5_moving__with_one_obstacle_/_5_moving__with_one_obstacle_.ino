int x_y_1[100][2],x_y_2[100][2],x_y_3[100][2],x_y_4[100][2];
int x_axis,y_axis; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,time_in_y_axis,wall_distance;
int begins = -1; //deh le x1,x2,y1,y2 
int ends ; /* deh le x3,x4,y3,y4 */
int ostacle_x; //dh vaiable be save el makan ele abl ele ostacle;
int ostacle_y; //dh vaiable be save el makan ele abl ele ostacle;
int in1,in2,in3,in4;
boolean finding_ostacle = true,left_or_right;
int time_to_end_obstacle;
void setup() {
  // put your setup code here, to run once:

}
void loop() {
check();
turn_left();
move_forward_2(time_in_y_axis); // deh function lel turn_left wel turn_right
turn_left();
stop_moving();
x_y_4[begins][0] = x_axis;
x_y_4[begins][1] = y_axis;
move_forward(true);
check();
ends=begins+1;
x_y_3[ends][0] = x_axis;
x_y_3[ends][1] = y_axis;
turn_right();
move_forward_2(time_in_y_axis); // deh function lel turn_left wel turn_right
turn_right();
stop_moving();
x_y_4[begins][0] = x_axis;
x_y_4[begins][1] = y_axis;
move_forward(false);
x_y_3[ends][0] = x_axis;
x_y_3[ends][1] = y_axis;
}
void begin_moving(){
begins++;
x_y_1[begins][0] = x_axis;
x_y_1[begins][1] = y_axis;
move_forward(false);
  x_y_2[begins][0] = x_axis;
  x_y_2[begins][1] = y_axis;
  }
int ultra_sonic(){}
void turn_left(){}
void turn_right(){}
void stop_moving(){}
void  move_forward(boolean left_or_right){
while(1){
  
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
distance1 = ultra_sonic();
if(distance1 <= wall_distance){
  stop_moving();
  break;
  }
  obstacle(left_or_right);
}
         //postion();
         //direction_axis();
  }
void move_forward_2(int time_y){
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(time_y);
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
void obstacle(boolean left_or_right){
  if(finding_ostacle){
  if(left_or_right){
  distance2 = ultra_sonic();
  if(distance2 <= wall_distance){
     ostacle_x = x_axis;
     ostacle_y = y_axis;
     finding_ostacle = false;
    }
  }
 else{ 
     distance3 = ultra_sonic(); 
     ostacle_x = x_axis;
     ostacle_y = y_axis;
     finding_ostacle = false;
  }
  }
else{
  if(x_axis > ostacle_x ){
    if(left_or_right == false){
      turn_right();
      move_forward_2(time_to_end_obstacle);
      turn_left();
      move_forward(false); // na tla3 l2odam +ve x axis
    }
     else{
       turn_left();
       move_forward_2(time_to_end_obstacle);
       turn_right();
       move_forward(true); // na rag3 lwara -ve x axis
     }
      
   finding_ostacle = true;
    }
  }
  }
