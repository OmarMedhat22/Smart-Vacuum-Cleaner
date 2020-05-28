int trigPin1 =7; 
int echoPin1 =6;
int trigPin2 =5;
int echoPin2 =4;
int trigPin3 =3;
int echoPin3 =2;
//#define enA 10//RIGHT MOTOR 
int in1 =8;
int in2 =9;
//#define enB 11 //LEFT MOTOR 
int in3 =10;
int in4 =11;
float distance ;
float duration ;
int wall_distance = 15;


float  distance1, distance2,distance3;


void setup() {
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
  Serial.begin(9600);
  
}




void loop() {
 analogWrite(in2,255);
  analogWrite(in4,255);
  
  distance1=ultra_sonic(trigPin1, echoPin1);
  distance3=ultra_sonic(trigPin2, echoPin2);
  distance2=ultra_sonic(trigPin3, echoPin3);

//Serial.println(distance2);
//delay(1000);

    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);

     // delay(1000);      
    
                             if (distance1 < wall_distance)  {
   

    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
  
   if (distance2 < wall_distance)  {
                              
   if  (distance3 < wall_distance) { 
                                digitalWrite(in1, HIGH);
                                digitalWrite(in3, HIGH);
                                                            }
                              else {
                                     digitalWrite(in1, HIGH);
                                     digitalWrite(in3, LOW);
                                    delay(1000);
    
                                }

                                                               }

                               
                           else{
    digitalWrite(in1, LOW);
    digitalWrite(in3, HIGH);
     delay(1000);

  } 
 // else{}
 

                            }
                            
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


