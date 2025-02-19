#include <SoftwareSerial.h>
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
SoftwareSerial bt(RX_PIN, TX_PIN);

void setup() {
  // configuração dos pinos do bluetooth
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);

  // inicialização da comunicação serial
  Serial.begin(9600);
  bt.begin(9600);
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