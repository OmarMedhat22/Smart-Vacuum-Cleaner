void setup() {
  // put your setup code here, to run once:
}

void loop() {
  corner = 1 ;
    make_right_orention(); //e3dl nfsk

}


void  make_right_orention(){

  // 7alf_shmal();
   while(1){
   move_forward();
   if(distance1<corner){
    half_shmal(); //90 degree
    break;
    }
   }
      distance2 = sonarsensor();
      oriention = distance2;
   while(1){
      move_forward();
      delay(500);
      distance2 = sonarsensor();
      if(distance1>corner){
      if(distance2<oriention){
          turn_left(,); //turn_left bzwya m7soba
        }
      else if(distance2>oriention){
          turn_right(,); //turn_right bzwya m7soba
        }
      else if(distance2==oriention){
        break;
        }
        oriention = distance2;
      }
      else if(distance1<corner){
        turn_random(); 
        break;
        }
   }
  }

void  move_forward(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
  }
