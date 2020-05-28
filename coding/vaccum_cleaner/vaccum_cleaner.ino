/*
firstly the vaccum cleaner go to any coner it detect ,it programed so that it must find corner which make the right sensor (sensor 2) have distance > wall_distance
secondly the vaccum cleaner will move forward if it detect distance < wall_distance it will turn_left and move forward for 1 second then turn left again and move forward
thirdly  the vaccum cleaner will move forward if it detect distance < wall_distance it will turn_right and move forward for 1 second then turn right again then move forward and the cycle repeat it self
fourthly the vaccum cleaner will detect any door and save this place in 2D array (x_axis,y_axis)
fifthly when the vaccum cleaner finish the room it compare which is the nearest place to it and go to this place
sixthly it go to this place as it move with the wall untill it find the place
seventhly  it detect +ve , -ve x axis and +ve , -ve y axis 
*/
int x_y_1[50][2],x_y_2[50][2],x_y_3[50][2],x_y_4[50][2];
int x_axis = 0 ,y_axis = 0; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,wall_distance = 25,duration,distance;
int begins = -1; //deh le x1,x2,y1,y2 
int ends ; /* deh le x3,x4,y3,y4 */
int trigPin1 =7,echoPin1 =8,trigPin2 =5,echoPin2 =13,trigPin3 =3, echoPin3 =4;
int in1 = 10, in2 = 9,in4 = 11, in3= 6;
int speeds = 40
;
int time_to_turn = 470 , time_to_stop = 500 , time_in_y_axis = 1000 , average = 0, average3 ,average2;
int count=0;
int encoder_x_axis,angle_x_left=0,angle_x_right=0,sum_x_angle=0;
int encoder_y_axis,angle_y_left=0,angle_y_right=0,sum_y_angle=0;
int save_x_axis , save_y_axis ;
int new_places[10][10];
int where_new_place[10];
int place_number = 0 ;
boolean postion_x  = HIGH;
boolean postion_y  = HIGH;
boolean  postion_x_or_postion_y = HIGH;
boolean left_or_right = false;
boolean first_case = false, second_case = false , third_case = false ,  first_loop = true;
int check_distance = 5;
int counters = 0;
//volatile int x_axis = 0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
attachInterrupt(0,plane,RISING);
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
 delay(5000);
   //=-09+ go_to_corner();
}

void loop() {
move_forward();
if(first_loop == false){
check();
}
turn_left(); 
move_forward_2(); 
turn_left(); left_or_right = true;
move_forward(); 
check();
turn_right();
move_forward_2(); 
turn_right();
move_stop();
left_or_right = false;
first_loop = false;
//delay(1000000000);


//turn_left(); move_forward_2(); turn_left(); move_forward();

//turn_right(); move_forward_2(); turn_right();

}

void plane(){
  if(postion_x_or_postion_y){
   if( postion_x ){
                x_axis++;
  delayMicroseconds(2000);
                }
              else{
                   x_axis--;
  delayMicroseconds(2000);
               
                }
  }
  else{
              if( postion_y ){
                     y_axis++;
                     delayMicroseconds(2000);
                }
              else{
                    y_axis--;
                    delayMicroseconds(2000);
                } 
  }
  }
void  move_forward(){
       //  postion();
        plane();
         while(1){
  
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  distance1=ultra_sonic(trigPin1, echoPin1);
        distance1 = abs(distance1);
  Serial.println(distance1);
if(distance1 <= wall_distance && distance1 > 0){
  move_stop();
  average = 0;
  for(int i = 0 ; i<10 ; i++){
  distance1=ultra_sonic(trigPin1, echoPin1);
          distance1 = abs(distance1);
  average = average + distance1 ;
   delay(5);
  }
  average = average/10 ;
  Serial.println("the average  = ");
  Serial.println(average);
  if(average < wall_distance  ){ 
  break;
    }
  }
    if(counters == 0){
      new_place(true);
      new_place(false);
      }
      else{    new_place(left_or_right); }
}
      counters++;

  }

    void  turn_right(){
            Serial.println("right");
      delay(1500);
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
//         postion();
 digitalWrite(in1,LOW);
analogWrite(in4,60);
analogWrite(in2,60);
digitalWrite(in3,LOW);
  delay(time_to_turn);
   move_stop(); 
  }
     void  turn_left(){
      Serial.println("left");
      delay(1500);
      analogWrite(in1,60);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
analogWrite(in3,60);
  delay(time_to_turn);
   move_stop();
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
         // postion();

  }
   
   void go_to_corner(){
    
  while(1){
     move_forward();

     for(int i=0; i<10; i++){
      distance2=ultra_sonic(trigPin2, echoPin2);\
      average2 = average2 + distance2 ;
      delay(50);
      }
      average2 = average2/10 ;
       for(int i=0; i<10; i++){
      distance3=ultra_sonic(trigPin3, echoPin3);
      average3 = average3 + distance3 ;
      delay(50);
      }        
             average3 = average3/10 ;
              

      if(distance1 <= wall_distance){
        move_stop();
        if(average3 <= wall_distance ){
          turn_right(); // 180 degree
          turn_right();
          move_stop(); 
          delay(60000);
          break;
          }
         else if( average2 <= wall_distance ){
          turn_left(); // 90 degree
          move_stop();
          delay(60000);
          break;
          }
        else{
               turn_left();
          }
        }

    }
  }
   void move_forward_2(){
      
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_in_y_axis);
   move_stop(); 
  }
  void move_stop(){
  analogWrite(in1,LOW);
  analogWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  delay(time_to_stop); 
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
  

void values_of_axis(){
Serial.println("the x_axis = ");
Serial.println(x_axis);
Serial.println("the y_axis = ");
Serial.println(y_axis);
delay(5000);
  }
void check(){
  int place,average_dis2 = 0,average_dis3 = 0;
     for(int i=0 ; i<10 ; i++){distance2=ultra_sonic(trigPin2, echoPin2); distance2 = abs(distance2); average_dis2 = average_dis2 + distance2; delay(5); }
      average_dis2  = average_dis2/10 ; 
                        for(int i=0 ; i<10 ; i++){distance3=ultra_sonic(trigPin3, echoPin3); distance3 = abs(distance3); average_dis3 = average_dis3 + distance3; delay(5); }
      average_dis3  = average_dis3/10 ;
      Serial.println("checking");
      delay(5000);
  if(( average_dis2 < check_distance || average_dis3 < check_distance)){
    while(1){
      Serial.println("checkingggggggggggggggggggggggggg");
      delay(5000);
     move_stop();
     place = which_place_to_go();
        go_to_place(place); 
      }
    }
  }
  void new_place(boolean left_or_right){
  if(left_or_right){
     save_new_place(trigPin2 , echoPin2 , 0); // ana hna sh8al fe distance 2 3shan na mash fel -ve x axis
    //if(x_axis < x_y_3[ends][0]){ save_new_place(trigPin3 , echoPin3 , 1);} // ana hna sh8al fe distance 3 3shan na mash fel -ve x axis bs 3det msafa mo3yana 
    
  }
  else{
    save_new_place(trigPin3 , echoPin3 , 1);
  //  if(x_axis > x_y_4[ends][0]){ save_new_place(trigPin2 , echoPin2 , 0);} // ana hna sh8al fe distance 2 3shan na mash fel -ve x axis bs 3det msafa mo3yana
    }
  }
  void save_new_place(int trig_pin , int echo_pin , int where){
    int distances , place_average = 0;
     distances = ultra_sonic(trig_pin,echo_pin);
             for(int i = 0 ; i<10 ; i++){
              distances = ultra_sonic(trig_pin,echo_pin);      distances = abs(distances);
              place_average = place_average + distances;
              }
              place_average = place_average/10 ; 
            Serial.print("the place average distance =");    Serial.println(place_average); 
            
               if(place_average < wall_distance){
                     first_case = true;
                     if(second_case == true){third_case = true;}
                                       }
    
   if( (place_average > wall_distance) && (first_case == true) ){
  save_x_axis = x_axis;  //bsave el mkan l7d lma ala2e ostacle fa a3mlo save fel variable new_places
  save_y_axis = y_axis; //bsave el mkan l7d lma ala2e ostacle fa a3mlo save fel variable new_places
  second_case = true; 
  }
  
    if((place_average < wall_distance) && (second_case == true) && (first_case == true) && (third_case == true)){
       new_places[place_number][0] = save_x_axis;
       new_places[place_number][1] = save_y_axis;
       where_new_place[place_number] = where;           // if where_new_place = 1 so i found place by distance 2 when ia move in +ve x axis or by distance 3 when i move in -ve x axis
       place_number++;
       move_stop();
      Serial.println("the place");
       delay(60000);
       first_case = false; second_case = false; third_case = false;
      }
 //   if(first_case)
  }
int  which_place_to_go(){
  int no_of_places=0,x,y,straight_line,minumum=322427667;
  while(no_of_places<place_number){
     x = x_axis - new_places[no_of_places][0];
     y = y_axis - new_places[no_of_places][1];
     straight_line = x*x + y*y;
     if( (straight_line < minumum) && ( straight_line !=0) ){
      minumum = no_of_places;
      }
      no_of_places++;
    }
   return minumum;
  }
void go_to_place(int place ){
  Serial.println("goto place");
  static boolean R_L = left_or_right;
  while(1){
  if(R_L){
     move_stop();
     turn_left();
    R_L =  move_forward_with_wall(R_L,place);
    }
   else{
     move_stop();
     turn_right();
    R_L =  move_forward_with_wall(R_L,place);
    }
  }
  
  }
boolean move_forward_with_wall(boolean pos , int place){
  int average_dis = 0 , average_dis2 = 0 , average_dis3 = 0;
  while(1){
    average_dis = 0 , average_dis2 = 0 , average_dis3 = 0;
  analogWrite(in1,speeds);
  analogWrite(in4,speeds);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
      if(pos){
        for(int i=0 ; i<10 ; i++){distance1 = ultra_sonic(trigPin1, echoPin1); distance1 = abs(distance1); average_dis = average_dis + distance1; delay(5); }
      average_dis  = average_dis/10 ; 
                   for(int i=0 ; i<10 ; i++){distance2=ultra_sonic(trigPin2, echoPin2); distance2 = abs(distance2); average_dis2 = average_dis2 + distance2; delay(5); }
      average_dis2  = average_dis2/10 ; 
      if(average_dis < wall_distance){return true;}
      else if(average_dis2 > wall_distance){return false; }
      else if( ((new_places[place][1] > y_axis - 20) && (new_places[place][1] <= y_axis + 20)) && ((new_places[place][0] > x_axis - 20) && (new_places[place][0] <= x_axis + 20)) ) {move_stop(); Serial.println("found new place"); delay(30000);/*enter_the_new_place(); */}
      }
      else{
              for(int i=0 ; i<10 ; i++){distance1 = ultra_sonic(trigPin1, echoPin1); distance1 = abs(distance1); average_dis = average_dis + distance1; delay(5); }
      average_dis  = average_dis/10 ; 
                      for(int i=0 ; i<10 ; i++){distance3=ultra_sonic(trigPin3, echoPin3); distance3 = abs(distance3); average_dis3 = average_dis3 + distance3; delay(5); }
      average_dis3  = average_dis3/10 ; 
      if(average_dis < wall_distance){return false;}
      else if(average_dis3 > wall_distance){return true; }
      else if( ((new_places[place][1] > y_axis - 20) && (new_places[place][1] <= y_axis + 20)) && ((new_places[place][0] > x_axis - 20) && (new_places[place][0] <= x_axis + 20)) ) {Serial.println("found new place"); move_stop(); delay(30000);/*enter_the_new_place(); */}

        }
    
    }
  
  }
/*+void enter_the_new_place(){
     // el mkan fel ymeen bel nsba l distance 2
  if(where_new_place[place_number] == 1 ){
    old_y_axis = y_axis;
    old_x_axis = x_axis;
    move_forward_2(); // hmshee forward haga bseta awe
    new_y_axis = y_axis;
    new_x_axis = x_axis
    if( old_y_axis == new_y_axis ) {
       if( old_x_axis < new_x_axis ){move_forward_2(); turn_right(); move_forward_2(); turn_right();} // awl w tany move forward na bmshe l7d  lma ml2eesh ostacle 3shan alf
       else{move_forward_2(); turn_left(); move_forward_2();  turn_right(); } // awl w tany move forward na bmshe l7 lma ml2eesh ostacle 3shan alf
      }
    else if( old_y_axis < new_y_axis ){ move_backward(); turn_left();} // lma hmshe backward na hmsh l7d lma ml2eesh ostacle y3ny lazm a5le el function keda
    else {turn_right();}
    }
    // el mkan fel shmal bel nsba l distance 3
    else if(where_new_place[place_number] == 0 ){
      old_y_axis = y_axis;
    old_x_axis = x_axis;
    move_forward_2(); // hmshee forward haga bseta awe
    new_y_axis = y_axis;
    new_x_axis = x_axis
    if( old_y_axis == new_y_axis ) {
       if( old_x_axis < new_x_axis ){move_forward_2(); turn_left() move_forward_2(); turn_right();} // awl w tany move forward na bmshe l7 lma ml2eesh ostacle 3shan alf
       else{move_forward_2();  turn_right(); move_forward_2();  turn_right(); } // awl w tany move forward na bmshe l7 lma ml2eesh ostacle 3shan alf
      }
    else if( old_y_axis > new_y_axis ){ move_backward(); turn_left();} // lma hmshe backward na hmsh l7d lma ml2eesh ostacle y3ny lazm a5le el function keda
    else {turn_right(); }
      }
   new_places[place_number][0] = 0;
   new_places[place_number][0] = 0;
  goto begin_function;
  }
  */
