
void setup() {
  // put your setup code here, to run once:
}

void loop() {
 go_to_corner();
}
void  turn_right(){}
void  turn_left(){}
void  move_forward(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
  }
void go_to_corner(){
  while(1){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      if(distance1 <= corner){
        if(distance3 <=corner ){
          turn_right(); // 90 degree
          break;
          }
         else if( distance2 <= corner ){
          turn_left(); // 90 degree
          break;
          }
        else{
              turn_right(); /* aw */ turn_left();
          }
        }

    }

  }
