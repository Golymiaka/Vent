#include <DHT11.h>

// Настройки пинов
#define DHTPIN 2
#define MOTOR_IN1 8
#define MOTOR_IN2 9

DHT11 dht11(DHTPIN);

const float tempHigh = 25.0;
const float tempLow = 23.0;

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  Serial.println("Programm launched.");
}

void loop() {

  // Получение текущей температуры
  float temperature = dht11.readTemperature();

  Serial.print("Current temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Логика моторчика
  if (temperature > tempHigh) {
    // Если температура выше верхнего порога, включаем моторчик
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    Serial.println("Motor ON.");
  } else if (temperature < tempLow) {
    // Если температура ниже нижнего порога, выключаем моторчик
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    Serial.println("Motor OFF.");
  }

  delay(2000);
}