#include <Arduino.h>

#define LedMerah D7
#define LedHijau D6
#define LedBiru D5
#define triggerPin D2
#define echoPin D1

int nilaiSensor;
byte temperature = 0;
byte humidity = 0;
int led = 13;

void Jarak() {
  long duration, jarak;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = duration * 0.034 / 2;

  Serial.print("Keadaan Sekarang: Jarak ");
  Serial.print(jarak);
  Serial.println(" cm");
  delay(1500);

  //KONDISI 1 : JARAK 1 CM
  if (jarak == 1) {
    digitalWrite(LedBiru, HIGH);
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedHijau, LOW);
    Serial.println("LED Biru nyala");
  }
  //KONDISI 2 : JARAK 2 CM
  if (jarak == 2) {
    digitalWrite(LedHijau, HIGH);
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedBiru, LOW);
    Serial.println("LED Hijau nyala");
  }
  //KONDISI 3 : JARAK 3 CM
  if (jarak == 3) {
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedHijau, LOW);
    digitalWrite(LedBiru, LOW);
    Serial.println("LED Merah nyala");
  }
  //KONDISI 4 : JARAK > 3 CM
  if (jarak > 3) {
    digitalWrite(LedMerah, HIGH);
    delay(400);
    digitalWrite(LedMerah, LOW);
    delay(100);
    digitalWrite(LedHijau, HIGH);
    delay(400);
    digitalWrite(LedHijau, LOW);
    delay(100);
    digitalWrite(LedBiru, HIGH);
    delay(400);
    digitalWrite(LedBiru, LOW);
    delay(100);
    Serial.println("LED Nyala Semua");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  delay(3000);
}

void loop() {
  Jarak();
  delay(3000);
}
