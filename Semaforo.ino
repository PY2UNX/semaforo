/*
 Project: Semaforo v0.1 - 17/06/2017
 Author: Renato Tambellini - renato@tambellini.eti.br
 Hardware: Arduino Uno + 6 leds + 2 resistors
 
 Pins Used:
 02 PWM - Rua #1 - Verde
 03 PWM - Rua #1 - Amarelo
 04 PWM - Rua #1 - Vermelho
 05 PWM - Rua #2 - Verde
 06 PWM - Rua #2 - Amarelo
 07 PWM - Rua #2 - Vermelho
 
 Tabela de mudancas de estado:
 
 Estagio R#1Vd R#1Am R#1Vm R#2Vd R#2Am R#2Vm
 stage#1  *1*    0    *0*   0     *0*   *1*
 stage#2  *0*   *1*    0    0      0     1
 stage#3   0    *0*   *1*  *1*     0    *0*
 stage#4   0     0     1   *0*    *1*    0
 
*/

void setup() {

  // Define modo dos pinos
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 

  // Garante que pinos estejam em nivel baixo
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  
  // Amarelo piscante por 5 segundos
  for (int a = 0; a < 10; ++a)
    tilt();

}

void loop() {

  for (int stage = 1; stage < 5; ++stage) {
  
    switch (stage) {
      
      case 1: // Rua #1 Verde, Rua #2 Vermelho
        digitalWrite(4, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(6000); // 6 segundos
        break;
        
      case 2: // Rua #1 Amarelo
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(2000); // 2 segundos
        break;
        
      case 3: // Rua #1 Vermelho, Rua #2 Verde
       digitalWrite(3, LOW);
       digitalWrite(4, HIGH);
       digitalWrite(7, LOW);
       digitalWrite(5, HIGH);
       delay(6000); // 6 segundos
       break;

      case 4: // Rua #2 Amarelo
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(2000); // 2 segundos
        break;
        
    }
  
  }
  
}

void tilt() {

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  delay(500);
  
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  delay(500);
    
}
