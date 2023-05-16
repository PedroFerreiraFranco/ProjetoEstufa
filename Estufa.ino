#include <dht11.h>
#define DHT11PIN 10

dht11 DHT11;

int umidade;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 7, 6, 5, 4);
int porta_rele = 11;

#define LED 8

void setup()
{
  pinMode(LED,OUTPUT);
 Serial.begin(9600);
 lcd.begin(16, 2);
 pinMode(porta_rele, OUTPUT);
}
/*--------------------------------------------------*/
void mostrarDHT11(){ 
    int chk = DHT11.read(DHT11PIN);
    
   lcd.print("Umidade Ar(%):");
   lcd.print((float)DHT11.humidity, 2);
   
   lcd.setCursor(2, 1);
   lcd.print("Temp Ar (C):");
   lcd.print((float)DHT11.temperature, 2);
}
/*--------------------------------------------------*/
void mostrarIrrigando(int Porcento){
  lcd.print("Irrigando: ");
  lcd.print(Porcento);// Imprime um texto
  lcd.print("%"); // Imprime um texto
  digitalWrite(LED, HIGH);
  digitalWrite(porta_rele, HIGH);
}
/*--------------------------------------------------*/
void mostrarUmidade(int Porcento){
  lcd.print("Umidade Solo:");
  lcd.print(Porcento);
  lcd.print("%"); // Imprime um texto
  digitalWrite(LED, LOW);
  digitalWrite(porta_rele, LOW);
}
/*--------------------------------------------------*/
void loop(){
 umidade = analogRead(A0);
 int Porcento = map(umidade, 1023, 0, 0, 100);
 lcd.clear();
 mostrarDHT11();
 delay(5000);
 lcd.clear();
 if(Porcento <=40){
  mostrarIrrigando(Porcento);
  }else{
  mostrarUmidade(Porcento);
 }

 delay(5000);
 
 
}
