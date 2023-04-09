#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7 // SD3 pin signal sensor DHT

byte temperature = 0;
byte humidity = 0;

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

  Serial.print("Sample OK: ");
  Serial.print((int)temperature);

  Serial.print(" °C, ");
  Serial.print((int)humidity);
  Serial.println(" H");

  delay(1500);

  // Reamur
  // Reamur = Celcius * 0.8
  float converted_r = 0.00;
  converted_r = temperature * 0.8;
  Serial.print("Reamur = ");
  Serial.print(converted_r);
  Serial.println(" °R ");

  // Kelvin
  // Kelvin = Celcius + 273.15
  float converted_k = 0.00;
  converted_k = temperature + 273.15;
  Serial.print("Kelvin = ");
  Serial.print(converted_k);
  Serial.println(" °K ");
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  delay(1000);
}

void loop()
{
  KelembabanSuhu();
}
