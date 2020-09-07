// Distancia definida
const int distancia_captar = 15;

// Portas do sensor
const int TRIG = 3;
const int ECHO = 2;

// Portas dos leds
const int ledGreen = 7;
const int ledRed = 8;

// Iniciar o arduino, definir portas que sao de saida e portas que sao de entrada
void setup() {
 
  // Configurações do Sensor
  pinMode(TRIG,OUTPUT); // pino que envia o sinal
  pinMode(ECHO,INPUT); // pino que recebe o sinal
 
  // Configurações do LED
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

// Funcao para apagar e ligar os leds, baseados na distancia de um objeto
void loop() {
  int distancia = calcula_distancia(TRIG,ECHO); // chamamos a funcao que calcula a distancia, passando os pinos TRIG e ECHO ja definidos

    if(distancia <= distancia_captar){ // se a distancia do objeto for menor ou igual do que a definida, entra aqui
      digitalWrite(ledGreen, LOW); // desliga o led verde
      digitalWrite(ledRed, HIGH); // liga o led vermelho
    }
    else{ // caso a distancia seja maior do que a definida
      digitalWrite(ledGreen, HIGH); // liga o led verde
      digitalWrite(ledRed, LOW); // desliga o led vermelho
    }
  delay(100); // delay para repetir a verificacao
}

// Funcao utilizada para calcular a distancia
int calcula_distancia(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW); // seta o pino TRIG como LOW
  delayMicroseconds(2); // espera 2 microssegundos
  digitalWrite(pinotrig,HIGH); // seta o pino TRIG como HIGH
  delayMicroseconds(10); // espera 10 microssegundos
  digitalWrite(pinotrig,LOW); // seta o pino TRIG como LOW novamente

  return pulseIn(pinoecho,HIGH)/58; // retorna a distancia que o objeto esta em cm
}
