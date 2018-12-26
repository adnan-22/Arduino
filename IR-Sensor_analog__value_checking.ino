# define L1 A0
# define L2 A1
# define ML A2
# define MR A3
# define R2 A4
# define R1 A5


void setup() 
{
  Serial.begin(9600);

  pinMode (L1, INPUT);
  pinMode (L2, INPUT);
  pinMode (ML, INPUT);
  pinMode (MR, INPUT);
  pinMode (R2, INPUT);
  pinMode (R1, INPUT);
}

void loop() 
{
  int l1 = analogRead(L1);
  int l2 = analogRead(L2);
  int ml = analogRead(ML);
  int mr = analogRead(MR);
  int r2 = analogRead(R2);
  int r1 = analogRead(R1);

  Serial.print(" L-1 = " );  Serial.print(l1);
  Serial.print(" L-2 = " );  Serial.print(l2);
  Serial.print(" M-L = " );  Serial.print(ml);
  Serial.print(" M-R = " );  Serial.print(mr);
  Serial.print(" R-2 = " );  Serial.print(r2);
  Serial.print(" R-1 = " );  Serial.print(r1);

  delay(2000);
}
