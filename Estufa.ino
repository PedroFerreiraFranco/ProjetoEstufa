int umidade;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 7, 6, 5, 4);
#define LED 8

void setup()
{
  pinMode(LED,OUTPUT);
 Serial.begin(9600);
 lcd.begin(16, 2);
}
void loop()
{
 umidade = analogRead(A0);
 int Porcento = map(umidade, 1023, 0, 0, 100);

  lcd.clear();
 Serial.print(Porcento);
 Serial.println("%");
 if(Porcento <=30)
 {
 Serial.println("Irrigando: ");
 lcd.print("Irrigando: ");
 lcd.print(Porcento);// Imprime um texto
 lcd.print("%"); // Imprime um texto
 digitalWrite(LED, HIGH);
  }
 
 else
 {
  lcd.print("Umidade: ");
  lcd.print(Porcento);
  lcd.print("%"); // Imprime um texto
 digitalWrite(LED, LOW);
 }
 
 delay(1000);
}