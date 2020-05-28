int in1,in2,in3,in4;
int x_axis;
int y_axis,count=0;
int encoder_x_axis,angle_x_left=0,angle_x_right=0,sum_x_angle=0;
int encoder_y_axis,angle_y_left=0,angle_y_right=0,sum_y_angle=0;
const int encoderIn1 = 8;
const int encoderIn2 = 8;
boolean postion_x  = HIGH;
boolean postion_y  = HIGH;
boolean  postion_x_or_postion_y = HIGH;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(encoderIn1, INPUT); 
pinMode(encoderIn2, INPUT);
Serial.println(".................................................");
  delay(50);
}
 
void loop() {
   move_forward();
   turn_left();
   move_forward();
   turn_left();
   move_forward();
     turn_left();
   move_forward();
     turn_right();
   move_forward();
       turn_right();
   move_forward();
       turn_right();
   move_forward();
      turn_left();
   move_forward();
       turn_right();
      move_forward();
    turn_right();
      move_forward();
      turn_left();
   move_forward();
      turn_right();
      move_forward();
   turn_right();
      move_forward();
        turn_left();
   move_forward();

           turn_left();
   move_forward();
           turn_left();
   move_forward();

  delay(5000000000000000000000);

}
void direction_axis(){
  if(postion_x_or_postion_y){
   if( postion_x ){
              Serial.println("postive x-axis");
                }
              else{
                 Serial.println("negative x-axis");
               
                }
  }
  else{
              if( postion_y ){
                   Serial.println("postive y-axis");
                }
              else{
                   Serial.println("negative y-axis");
                } 
  }
}

void postion(){
  encoder_x_axis=digitalRead(encoderIn1);
  encoder_y_axis=digitalRead(encoderIn2);
 if (encoder_x_axis == HIGH) { 
              if( postion_x ){
                  x_axis++;
                }
              else if(postion_x){
                   x_axis--;
               
                }
         }
   if (encoder_y_axis == HIGH) { 
              if( postion_y){
                  y_axis++;
                }
              else if(postion_y){
                   y_axis--;
               
                }
         }
  
  }
void  move_forward(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
         postion();
         direction_axis();
  }
  void  move_backward(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
  }
    void  turn_right(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      angle_x_right= angle_x_right + -90;
      sum_x_angle = angle_x_right + angle_x_left;
      if(sum_x_angle == 0){
        angle_x_right = 0;
        angle_x_left = 0;
        }
        else if(angle_x_right == -180){
          postion_y = !postion_y;
          angle_x_right = 0;
          }
      angle_y_right=angle_y_right-90;
      sum_y_angle=angle_y_right+angle_y_left;
      if(sum_y_angle == 0){
        angle_y_right=0;
        angle_y_left=0;
        }
    else  if(angle_y_right == -180){
          postion_x=!postion_x;
          angle_y_right=0;
          }
         postion_x_or_postion_y=!postion_x_or_postion_y;
         postion();
  }
     void  turn_left(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
  if(count>0){
      angle_x_left= angle_x_left + 90;
      sum_x_angle = angle_x_right + angle_x_left;
      if(sum_x_angle == 0){
        angle_x_right = 0;
        angle_x_left = 0;
        }
        else if(angle_x_left == 180){
          postion_y = !postion_y;
          angle_x_left=0;
          }
  }
  
      angle_y_left=angle_y_left+90;
      sum_y_angle=angle_y_right+angle_y_left;
        if(sum_y_angle == 0){
        angle_y_right=0;
        angle_y_left=0;
        }
     else if(angle_y_left == 180){
          postion_x=!postion_x;
          angle_y_left=0;
          }
     postion_x_or_postion_y=!postion_x_or_postion_y;
          count++;
          postion();
  }
