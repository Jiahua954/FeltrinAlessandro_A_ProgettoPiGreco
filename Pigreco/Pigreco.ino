#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int tempo;
int posPiGreco;
int posBomba;
int posVita;
int record;
int vita;
int punteggioAttuale;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  tempo = 5000;

}

void loop() {
  // put your main code here, to run repeatedly:

}

void bottone (int pulsante)
{
  bool finito = false;
  while(!finito)
  {
    if(digitalRead(pulsante) == HIGH)
    {
      finito=true;
    }
  }
}

void ControlloRisultato ()
{
  int tempoInizio = millis();
  int tempoSecondario;
  bool finito=false;
  while(!finito)
  {
    if(posVita!= -1 && digitalRead(posVita) == HIGH)
    {
      vita++;
      finito = true;
    }
    else if(posBomba != -1 && digitalRead(posBomba) == HIGH)
    {
      vita--;
      finito = true;
    }
    else if(posPiGreco!=-1 && digitalRead(posPiGreco) == HIGH) 
    {
      punteggioAttuale++;
      finito = true;
    }
    tempoSecondario = millis();
    if(tempoSecondario-tempoInizio>tempo)
    {
      finito = true;
    }

    if(tempo>2000)
    {
      tempo = tempo - 200;
    }
  }
}

void Gioco(int numeroVite)
{
  vita = numeroVite;
  bool finito = false;
  int valoreCasuale;
  while(!finito)
  {
    valoreCasuale = random(1,11);
    if(valoreCasuale>=1 && valoreCasuale <=6)
    {
      posPiGreco = random(2,7);
      lcd.setCursor((posPiGreco-1)*3,2);
    }
    else if(valoreCasuale>=7 &&  valoreCasuale <=9)
    {
      posBomba = random(2,7);
    }
    else
    {
      posVita = random(2,7);
    }
    ControlloRisultato();
    if(punteggioAttuale > record)
    {
      record = punteggioAttuale;
    }
    if(vita==0)
    {
      finito= true;
    }
  }
}
