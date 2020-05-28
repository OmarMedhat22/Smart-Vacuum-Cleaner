/* fkrt el new place btt2sm l 3 hagat
1- awl haga ene a3rf el mkan  el gdeed w a3mlo save 
2- tany haga ene aroo7 el mkan el gdeed dh b3d lma a5las el mkan ele na feh
3- talt haga ene a3rf amshe fel mkan el gdeed btre2a mo3yana
4- lazm a3ml check na ele mkan dh ro7to abl keda wla l2 
5- lam a5las mkan aroo7 lmakn tany bs a5tar ele mkan ele yb2a orayb mne 
*/
int x_y_1[100][2],x_y_2[100][2],x_y_3[100][2],x_y_4[100][2];
int x_axis,y_axis; //na m3rfhom abl keda fel orention
int distance1,distance2,distance3,time_in_y_axis,wall_distance;
int begins = -1; //deh le x1,x2,y1,y2 
int ends ; /* deh le x3,x4,y3,y4 */
int in1,in2,in3,in4;
void setup() {
  // put your setup code here, to run once:

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
begin_function:
begins++;
x_y_1[begins][0] = x_axis;
x_y_1[begins][1] = y_axis;
move_forward_begin();
  x_y_2[begins][0] = x_axis;
  x_y_2[begins][1] = y_axis;
  }
int ultra_sonic(){}
void turn_left(){}
void turn_right(){}
void stop_moving(){}
void move_forward_begin(){
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
  new_place(true);.
  new_place(false);.
}
  
  }
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
  new_place(left_or_right);.

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
  int place;
  distance2 = ultra_sonic();
  distance3 = ultra_sonic();
  if(distance1 < wall_distance &&( distance2 < wall_distance || distance2 < wall_distance)){
    while(1){
      stop_moving();
     place = which_place_to_go();
     if( (new_places[place][1] > y_axis - 20) && (new_places[place][1] <= y_axis + 20) ){
      while(1){
      move_backward();
      if(left_or_right){distance2 = ultra_sonic(); if(distance2>wall_distance){break;}}
      else{distance3 = ultra_sonic(); if(distance3>wall_distance){break;}}
      }
      }
      else{ go_to_place(place); }
      }
    }
  }
void new_place(){
  if(left_or_right){

    save_new_place(trig_pin_2 , echo_pin_2 , 0); // ana hna sh8al fe distance 2 3shan na mash fel -ve x axis
    if(x_axis < x_y_3[ends][0]){ save_new_place(trig_pin_3 , echo_pin_3 , 1);} // ana hna sh8al fe distance 3 3shan na mash fel -ve x axis bs 3det msafa mo3yana 
    
  }
  else{
    save_new_place(trig_pin_3 , echo_pin_3 , 1);
    if(x_axis > x_y_4[ends][0]){ save_new_place(trig_pin_2 , echo_pin_2 , 0);} // ana hna sh8al fe distance 2 3shan na mash fel -ve x axis bs 3det msafa mo3yana
    }
  }
void save_new_place(int trig_pin , int echo_pin , int where){
    int distances = ultra_sonic();
  if(distances > wall_distance){
  save_x_axis = x_axis;  //bsave el mkan l7d lma ala2e ostacle fa a3mlo save fel variable new_places
  save_y_axis = y_axis; //bsave el mkan l7d lma ala2e ostacle fa a3mlo save fel variable new_places
  }
  else if(distances < wall_distance){
    new_places[place_number][0] = save_x_axis;
    new_places[place_number][1] = save_y_axis;
    where_new_place[place_number] = where; // if where_new_place = 1 so i found place by distance 2 when ia move in +ve x axis or by distance 3 when i move in -ve x axis
    place_number++;
    }
  }
int  which_place_to_go(){
  int no_of_places,x,y,straight_line,minumum=322427667;
  while(no_of_places<place_number){
     x = x_axis - new_places[no_of_places][0];
     y = y_axis - new_places[no_of_places][0];
     straight_line = x*x + y*y;
     if( (straight_line < minumum) && ( straight_line !=0) ){
      minumum = no_of_places;
      }
      no_of_places++;
    }
   return minumum;
  }
void go_to_place(int place ){
  static boolean R_L = left_or_right;
  while(1){
  if(R_L){
     stop_moving();
     turn_left();
    R_L =  move_forward_with_wall(R_L);
    }
   else{
     stop_moving();
     turn_right();
    R_L =  move_forward_with_wall(R_L,place);
    }
  }
  
  }
boolean move_forward_with_wall(boolean pos , int place){
  while(1){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      if(pos){
      distance1 = ultra_sonic();
      distance2 = ultra_sonic();
      if(distance1 < wall_distance){return true}
      else if(distance2 > wall_distance){return false }
      else if( ((new_places[place][1] > y_axis - 20) && (new_places[place][1] <= y_axis + 20)) && ((new_places[place][0] > x_axis - 20) && (new_places[place][0] <= x_axis + 20)) ) { enter_the_new_place(); }
      }
      else{
      distance1 = ultra_sonic();
      distance3 = ultra_sonic();
      if(distance1 < wall_distance){return false}
      else if(distance3 > wall_distance){return true }
        }
    
    }
  
  }
void enter_the_new_place(){
     // el mkan fel ymeen bel nsba l distance 2
  if(where_new_place[place_number] == 1 ){
    old_y_axis = y_axis;
    old_x_axis = x_axis;
    move_forward_2(); // hmshee forward haga bseta awe
    new_y_axis = y_axis;
    new_x_axis = x_axis
    if( old_y_axis == new_y_axis ) {
       if( old_x_axis < new_x_axis ){move_forward_2(); turn_right(); move_forward_2(); turn_right();} // awl w tany move forward na bmshe l7 lma ml2eesh ostacle 3shan alf
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
