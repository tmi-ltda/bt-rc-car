#include <Arduino.h>
#include <BluetoothSerial.h>
#include <Car.hpp>

#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26
#define COMMAND_SIZE 6
#define DIGITS 4

enum Commands {
  FORWARD = 'F',
  BACKWARD = 'B',
  LEFT = 'L',
  RIGHT = 'R',
  STOP = 'S',
  A_LEFT = 'X',
  A_RIGHT = 'Y',
};

char command[COMMAND_SIZE] = {};
char c = 'S';

bool repeat_x = true;
bool repeat_y = true;

uint64_t last_read = 0;

// instância e configuração do carro
car_config_t config = {
  .left_pin1 = IN1,
  .left_pin2 = IN2,
  .right_pin1 = IN3,
  .right_pin2 = IN4
};
Car car(config);

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
    bt.flush();
    size_t len = bt.readBytesUntil('\n', command, COMMAND_SIZE - 1);
    command[len] = '\0';

    if (len == 1 && isAlpha(command[0])) {
      c = command[0];

      if (c == A_LEFT) repeat_x = !repeat_x;
      if (c == A_RIGHT) repeat_y = !repeat_y;
      Serial.printf("Command: %c\n", c);
    } else if (len > 1 & isDigit(command[1])) {
      int number = min(100, atoi(command + 1));
      float power = number / 100.0f;
      Serial.printf("Max power = %d%%\n", number);

      car.setMaxPower(power);
    }
  }

  switch(c) {
      case FORWARD:
        car.forward();
        break;
      case BACKWARD:
        car.backward();
        break;
      case LEFT:
        car.differentialLeft();
        break;
      case RIGHT:
        car.differentialRight();
        break;
      case A_LEFT:
        if (!repeat_x) car.axialLeft();
        else c = STOP;
        break;
      case A_RIGHT:
        if (!repeat_y) car.axialRight();
        else c = STOP;
        break;
      case STOP:
        car.stop();
        break;
  }
}