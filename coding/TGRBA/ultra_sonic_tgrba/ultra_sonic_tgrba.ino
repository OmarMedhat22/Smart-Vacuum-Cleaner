int trigPin1 =7; 
int echoPin1 =6;
float distance ;
float duration ;


float  distance1, distance2,distance3;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  distance1 = ultra_sonic(trigPin1, echoPin1);
  Serial.println(distance1);
  delay(1000);
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
