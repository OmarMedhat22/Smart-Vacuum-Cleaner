volatile int x_axis = 0 ;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
attachInterrupt(0,plane,RISING);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(x_axis);
delay(1000);
}

int plane(){
  x_axis++;
  delayMicroseconds(2000);
  }
