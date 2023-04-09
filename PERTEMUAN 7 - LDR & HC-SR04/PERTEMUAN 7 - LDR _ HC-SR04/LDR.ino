#define sensorLDR A0
int nilaiSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Contoh Penggunaan Sensor LDR");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilaiSensor = analogRead(sensorLDR);
  Serial.print("Nilai Sensor : ");
  Serial.println(nilaiSensor);
  delay(1000);
}
