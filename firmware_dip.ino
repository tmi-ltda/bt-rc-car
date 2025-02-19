#include <SoftwareSerial.h>

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define RX_PIN 2
#define TX_PIN 3

int velocidade = 255;

// instância do bluetooth
SoftwareSerial bt(RX_PIN, TX_PIN);

void setup() {
  // configuração dos pinos do bluetooth
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);

  // configuração dos pinos da ponte h
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

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
        frente();
        break;
      case 'B':
        tras();
        break;
      case 'L':
        esquerda();
        break;
      case 'R':
        direita();
        break;
      case 'S':
        parar();
        break;
    }
  }
}

// controle dos motores
void frente() {
  analogWrite(IN1, velocidade);
  digitalWrite(IN2, LOW);
  analogWrite(IN3, velocidade);
  digitalWrite(IN4, LOW);
}

void tras() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, velocidade);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, velocidade);
}

void esquerda() {
  analogWrite(IN1, velocidade);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, velocidade);
}

void direita() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, velocidade);
  analogWrite(IN3, velocidade);
  digitalWrite(IN4, LOW);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
