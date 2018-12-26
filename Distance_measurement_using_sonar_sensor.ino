const int trigPin=9;
const int echoPin=10;
void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

float duration = pulseIn(echoPin, HIGH);
float distance= duration*0.034/2;
Serial.println(distance);
delay(10000);
}
