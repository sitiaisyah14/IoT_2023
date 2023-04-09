#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7 // SD3 pin signal sensor DHT
#define LedMerah D6
#define LedHijau D1
#define LedBiru D2
#define sensorLDR A0

int nilaiSensor;
byte temperature = 0;
byte humidity = 0;
int led=13;

SimpleDHT11 dht11(D0); //instan sensor dht11

void CahayaSuhu()
{
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Pembacaan DHT11 gagal, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print("Keadaan Sekarang: ");
  Serial.print((int)temperature);
  Serial.print(" *C, ");

  Serial.print("Nilai Sensor : ");
  Serial.println(nilaiSensor);

  delay(1500);

  nilaiSensor = analogRead(sensorLDR);

  //KONDISI 1 : REDUP, DINGIN
  if ( temperature <= 27 && nilaiSensor >= 500) {
    digitalWrite(LedBiru, HIGH);
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedHijau, LOW);
    Serial.println("LED Biru nyala");
  }
  //KONDISI 2 : TERANG, PANAS
  if ( temperature > 27 && nilaiSensor < 500) {
    digitalWrite(LedHijau, LOW);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedMerah, HIGH);
    Serial.println("LED Merah nyala");
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  pinMode(LedMerah,OUTPUT);
  pinMode(LedHijau,OUTPUT);
  pinMode(LedBiru,OUTPUT);
  delay(3000);
}

void loop()
{
  CahayaSuhu();
  delay(1000);
}
