#include <Wire.h>  // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>  // Biblioteca para o LCD I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do LCD, 16 colunas, 2 linhas
const int sensorPin = A0;  // Pino do sensor de umidade
const int ledPin = 13;  // Pino do LED vermelho
const int relayPin = 4; // Pino do relé para controlar o motor

// Definir os limites mínimo e máximo de leitura do sensor
const int umidadeSoloMin = 0;  // Leitura mínima do sensor
const int umidadeSoloMax = 1023;  // Leitura máxima do sensor

// Definir os limites mínimo e máximo de umidade do solo em porcentagem
const int umidadePorcentagemMin = 0;  // Umidade do solo mínima em porcentagem
const int umidadePorcentagemMax = 100;  // Umidade do solo máxima em porcentagem

void setup() {
  lcd.init();  // Inicializa o LCD
  lcd.backlight();  // Liga a luz de fundo do LCD
  pinMode(sensorPin, INPUT);  // Define o pino do sensor de umidade como entrada
  pinMode(ledPin, OUTPUT);  // Define o pino do LED como saída
  pinMode(relayPin, OUTPUT); // Define o pino do relé como saída
}

void loop() {
  // Leitura da umidade do solo
  int umidadeSolo = analogRead(sensorPin);

  // Mapear a leitura do sensor para a faixa de 0 a 100%
  int umidadePorcentagem = map(umidadeSolo, umidadeSoloMin, umidadeSoloMax, umidadePorcentagemMax, umidadePorcentagemMin); // Invertido os valores min e max

  // Exibe a umidade do solo em porcentagem no LCD
  lcd.setCursor(0, 0);
  lcd.print("Umidade do Solo:");
  lcd.setCursor(0, 1);
  lcd.print(umidadePorcentagem);
  lcd.print("%");

  // Verifica se a umidade do solo está abaixo de um determinado valor
  if (umidadePorcentagem < 50) {  // Invertido o operador de comparação
    digitalWrite(ledPin, HIGH);  // Liga o LED vermelho
    digitalWrite(relayPin, HIGH); // Liga o relé (aciona o motor)
  } else {
    digitalWrite(ledPin, LOW);  // Desliga o LED vermelho
    digitalWrite(relayPin, LOW); // Desliga o relé (desliga o motor)
  }
  
  delay(1000);  // Aguarda 1 segundo antes da próxima leitura
}
