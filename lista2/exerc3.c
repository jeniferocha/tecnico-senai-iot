
/*03) Utilize um acelerômetro para identificar as velocidades de deslocamento nos
eixos x, y e z.*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(9600);

  while (!mpu.begin()) {
    Serial.println("MPU6050 não conectado!");
    delay(1000);
  }
  Serial.println("MPU6050 pronto!");
}

sensors_event_t event;

void loop() {
  mpu.getAccelerometerSensor()->getEvent(&event);

  Serial.print("[");
  Serial.print(millis());
  Serial.print("] X: ");
  Serial.print(event.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(event.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(event.acceleration.z);
  Serial.println(" m/s^2");
  delay(500);
}