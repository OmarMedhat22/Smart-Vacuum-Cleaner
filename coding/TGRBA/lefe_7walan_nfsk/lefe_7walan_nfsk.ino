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
int in3 =10;
int in4 =11;
float distance ;
float duration ;
int wall_distance = 10;

void setup() {
  // put your setup code here, to run once:
   pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
   analogWrite(in2,150);
  analogWrite(in4,150);
  

}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
