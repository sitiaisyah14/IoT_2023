#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7 // SD3 pin signal sensor DHT
#define LedMerah D5
#define LedHijau D6
#define LedBiru D7

byte temperature = 0;
byte humidity = 0;
int led=13;

SimpleDHT11 dht11(D1); //instan sensor dht11

void KelembabanSuhu()
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
  Serial.print((int)humidity);
  Serial.println(" H");

  delay(1500);

  if ( temperature >= 32 && humidity >= 86) {
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, LOW);
    Serial.println("LED Merah nyala");
  }
  if ( temperature >= 29 && temperature < 32 && humidity >=82 && humidity < 86 ) {
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedBiru, HIGH);
    digitalWrite(LedHijau, LOW);
    Serial.println("LED Biru nyala");
  }
  if ( temperature < 29 && humidity < 82) {
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, HIGH);
    Serial.println("LED Hijau nyala");
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  pinMode(LedMerah,OUTPUT);
  pinMode(LedHijau,OUTPUT);
  pinMode(LedBiru,OUTPUT);
  delay(1000);
}

void loop()
{
  KelembabanSuhu();
}
