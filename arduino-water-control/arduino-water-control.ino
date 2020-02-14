/**
 * Libraries:
 * 
 * - https://github.com/rlogiacco/CircularBuffer
 */

// the highest raw reading at atmospheric pressure
#define ZERO_VALUE 101
// the sensor max value in bars = 0.1MPa
#define MAX_PRESSURE 12.0
// the highest raw value that is supposed to be read
#define MAX_VALUE (1024.*4.5)
//
#define INPUT_PIN A1
//
#define CONTROL_PIN A0

short raw;
short minV = 1023;
short maxV = 0;
unsigned long rawSum = 0;
byte rawCount = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(INPUT_PIN);
  rawSum += raw;
  rawSum += 1023 - analogRead(CONTROL_PIN);
  rawCount++;
  if (minV > raw) minV = raw;
  if (maxV < raw) maxV = raw;
  if (rawCount == 250) {
    process(float(rawSum)/float(rawCount));
    rawCount=0;
    rawSum=0;
  }
}

void process(float raw) {
  float pressure = (raw - ZERO_VALUE)*MAX_PRESSURE/(MAX_VALUE-ZERO_VALUE);
  if (pressure < 0) pressure = 0;

  Serial.print(pressure);
  Serial.print(" bar (");
  Serial.print(minV);
  Serial.print("/");
  Serial.print(maxV);
  Serial.print(")");
  Serial.println("");
}
