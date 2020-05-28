int in1 = 10, in2 = 9,in4 = 11, in3= 6;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 //digitalWrite(in1,LOW);
//digitalWrite(in3,LOW);
analogWrite(in1,60);
analogWrite(in4,60);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
delay(10000);
move_stop();
//backward
digitalWrite(in1,LOW);
digitalWrite(in4,LOW);
analogWrite(in2,60);
analogWrite(in3,60);
delay(10000);
move_stop();
//turn left
analogWrite(in1,60);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
analogWrite(in3,60);
delay(10000);
move_stop();
//TURN RIGHT
digitalWrite(in1,LOW);
analogWrite(in4,60);
analogWrite(in2,60);
digitalWrite(in3,LOW);
delay(10000);
move_stop();
}
void move_stop(){
  digitalWrite(in1,LOW);
digitalWrite(in4,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
delay(5000);
  }
