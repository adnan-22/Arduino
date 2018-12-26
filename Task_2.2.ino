float roomTemp;
void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);//INTERNAK 1.1v for the Vref of ADC
}

void loop() {
  roomTemp=(float)100*(1.1/1024)*analogRead(A0);//casting float
  Serial.println(roomTemp,4);
  delay(2000);
}
