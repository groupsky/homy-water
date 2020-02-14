int a1, a2, a3;
float v1, v2, v3;
float p1, p2, p3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  a1 = analogRead(A0);
  delay(10);
  a2 = analogRead(A1);
  delay(10);
  a3 = analogRead(A2);

  v1 = a1*5.0/1023.0;
  v2 = a2*5.0/1023.0;
  v3 = a3*5.0/1023.0;

  p1 = (v1-0.47)*12/(4.5-0.5);
  p2 = (v2-0.47)*12/(4.5-0.5);
  p3 = (v3-0.47)*12/(4.5-0.5);
  
  Serial.print(" 0: A=");
  Serial.print(a1);
  Serial.print(" V=");
  Serial.print(v1);
  Serial.print(" P=");
  Serial.print(p1);

  Serial.print(" 1: A=");
  Serial.print(a2);
  Serial.print(" V=");
  Serial.print(v2);
  Serial.print(" P=");
  Serial.print(p2);

  Serial.print(" 2: A=");
  Serial.print(a3);
  Serial.print(" V=");
  Serial.print(v3);
  Serial.print(" P=");
  Serial.print(p3);

  Serial.println();
  
  delay(100);
}
