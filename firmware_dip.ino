#include <BluetoothSerial.h>
#include "Car/Car.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define RX_PIN 2
#define TX_PIN 3

// instância do carro
Car car(IN1, IN2, IN3, IN4);

// instância do bluetooth
BluetoothSerial bt;

void setup() {
  // inicialização da comunicação serial
  Serial.begin(115200);
  bt.begin("ESP32dip");
}

void loop() {
  // leitura do bluetooth
  if (bt.available() > 0) {
    char c = bt.read();
    Serial.println(c);

    switch(c) {
      case 'F':
        car.Forward();
        break;
      case 'B':
        car.Backward();
        break;
      case 'L':
        car.Left();
        break;
      case 'R':
        car.Right();
        break;
      case 'S':
        car.Stop();
        break;
    }
  }
}