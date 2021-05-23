//------------------------------------------------------------------------------------------------------------------------------------------
// LUCAS AUGUSTO FERNANDES DE LIRA - 31955541
// PAOLLA CAIRO CAMILLO - 31906427
// OBJETOS INTELIGENTES CONECTADOS
// PROJETO FINAL
// C++ code
// TESTANDO 
//------------------------------------------------------------------------------------------------------------------------------------------

#include <Servo.h>

//DEFINIR OS OBJETOS QUE VAMOS MANIPULAR
int LDR = 0;
int GIRO = 0;
int i = 0;
int j = 0;

Servo servo_8;


void setup()
{
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  servo_8.attach(8, 500, 2500);
  //MONITOR SERIAL PARA VISUALIZAR AS MENSAGENS 
  Serial.begin(9600);
}

void loop()
{
  //PARA REALIZAR A LEITURA DA PORTA ANALOGIA
  LDR = analogRead(A0);
  digitalWrite(12, LOW);
  //LOOP PARA QUANDO A INTENSIDADE DA LUZ FOR BAIXA
  if (LDR > 50) {
    //MANTER O LED APAGADO
    digitalWrite(13, LOW);
    for (GIRO = 0; GIRO <= 0; GIRO += 1) {
      // GIRAR A PA DO SERVO PARA POSICAO INICIAL
      servo_8.write(GIRO);
      //IMPRIMIR NO MONITOR SERIAL A SITUACAO DO MOTORISTA
      Serial.print("PODE DAR RE - ");
    }
  }
  // LOOP PARA QUANDO A INTENSIDADE DA LUZ FOR ALTA
  if (LDR < 50) {
    //MANTER O LED ACESO
    digitalWrite(12, HIGH);
    for (GIRO = 90; GIRO <= 90; GIRO += 1) {
      //GIRAR A PA DO SERVO PARA POSICAO FINAL
      servo_8.write(GIRO);
      //IMPRIMIR MONITOR SERIAL A SITUACAO DO MOTORISTA
      Serial.print("PARAR DE DAR RE - ");
    }
  }
  Serial.println(LDR);
  delay(10); // Delay a little bit to improve simulation performance
}
