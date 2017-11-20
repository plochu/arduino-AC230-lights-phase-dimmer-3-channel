/*
 * parametry zmierzone emiprycznie
 *  użyteczny zakres opóźnienia po detekcji zera:
 *    pełne światło = 0us
 *    minimalne = 7168us
 */

const int Poziomy = 32; // ilosc poziomow jasnosci swiecenia

int Krok = 0;

volatile int i;

volatile int FireLamp1 = 0; // zmienna przechowujaca poziom swiecenia lampy 1
volatile int FireLamp2 = 0; // zmienna przechowujaca poziom swiecenia lampy 2
volatile int FireLamp3 = 0; // zmienna przechowujaca poziom swiecenia lampy 3

const int Lamp1 = 3;  // pin sterujacy obwodu lampy 1
const int Lamp2 = 4;  // pin sterujacy obwodu lampy 2
const int Lamp3 = 5;  // pin sterujacy obwodu lampy 3


// funkcja wywolywana przez przerwanie w przypadku detekcji zera
void Zero() {

}

// ustawienia poczatkowe programu
void setup() {
  // blokada przerwan
  cli(); // blokada przerwan

  // konfiguracja pinow sterowania lampami
  pinMode(Lamp1, OUTPUT);
  digitalWrite(Lamp1, LOW);
  pinMode(Lamp2, OUTPUT);
  digitalWrite(Lamp2, LOW);
  pinMode(Lamp3, OUTPUT);
  digitalWrite(Lamp3, LOW);
  
  // ustalanie wielkosci kroku
  Krok = 7168 / Poziomy;
  
  // konfiguracja pinu i przypisanie przerwania z detektora przejscia przez zero  
  pinMode(2, INPUT);
  attachInterrupt(0, Zero, FALLING);
  
  // odblokowane przerwan
  sei();
}

// petla glowna programu
void loop() {

}
