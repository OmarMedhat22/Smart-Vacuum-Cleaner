int x_axis;
int y_axis,count=0;
int detectState;
const int encoderIn = 8;
boolean p_x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(encoderIn, INPUT); //Set pin 8 as input

}
 

void loop() {
  // put your main code here, to run repeatedly:
x_axis = -3;
Serial.println(x_axis);
delay(500);
}
void postion(){
  detectState=digitalRead(encoderIn);
 if (detectState == HIGH) { 
         }
  
  }
void  move_forward(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      if(p_x==true){
        +ve;
        }

        
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
          p_x=!p_x;
          angle_y_right=0;
          }
      
      
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
          p_x=!p_x;
          angle_y_left=0;
          }

          count++;
  }
