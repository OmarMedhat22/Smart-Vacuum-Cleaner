int trigPin1 =7; 
int echoPin1 =6;
int trigPin2 =5;
int echoPin2 =4;
int trigPin3 =3;
int echoPin3 =2;
#define enA 10//RIGHT MOTOR 
int in1 =8;
int in2 =9;
#define enB 11 //LEFT MOTOR 
int in3 =12;
int in4 =13;
float distance ;
float duration ;
int wall_distance = 10;


float  distance1, distance2,distance3;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  
}




void loop() {
  analogWrite(enA,150);
  analogWrite(enB,150);
  
  distance1=ultra_sonic(trigPin1, echoPin1);

Serial.println(distance2);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
                             if (distance1 < wall_distance)  {
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    distance2=ultra_sonic(trigPin2, echoPin2);

   if (distance2 < wall_distance)  {
    
                   distance3=ultra_sonic(trigPin3, echoPin3); 
                               
   if  (distance3 < wall_distance) { 
                                digitalWrite(in1, LOW);
                                digitalWrite(in2, LOW);
                                digitalWrite(in3, LOW);
                                digitalWrite(in4, LOW);
                                                            }
                              else {
                                    digitalWrite(in1, LOW);
                                    digitalWrite(in2, LOW);
                                    digitalWrite(in3, LOW);
                                    digitalWrite(in4, LOW);
                                    delay(1000);
    
                                }

                                                               }

                               
                           else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
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


