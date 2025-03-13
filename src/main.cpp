#include "Arduino.h"
#include "BluetoothSerial.h"
#include "Car.h"

#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26

// instância do carro
Car car(IN1, IN2, IN3, IN4, 0, 1, 2, 3);

// instância do bluetooth
BluetoothSerial bt;

void setup() {
  // inicialização da comunicação serial
  Serial.begin(115200);
  bt.begin("ESP32dip");
}

void loop() {
  // leitura do bluetoothr

  if (bt.available() > 0) {
    char c = bt.read();
    Serial.println(c);

    switch(c) {
      case 'F':
        car.forward();
        break;
      case 'B':
        car.backward();
        break;
      case 'L':
        car.left();
        break;
      case 'R':
        car.right();
        break;
      case 'E':
        car.forwardLeft();
        break;
      case 'Q':
        car.forwardRight();
        break;
      case 'S':
        car.stop();
        break;
    }
  }
}