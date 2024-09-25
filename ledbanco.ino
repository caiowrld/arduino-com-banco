float valorSensor = 0;
const int ledBrancoPin = 8;     // Pino do LED Branco
const int ledVerdePin = 9;      // Pino do LED Verde
const int ledVermelhoPin = 10;   // Pino do LED Vermelho
const int ldr = 7;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(ledBrancoPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledVermelhoPin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    char led = Serial.read();
    if (led == 'B') {
      digitalWrite(ledBrancoPin, HIGH);
      digitalWrite(ledVerdePin, LOW);
      digitalWrite(ledVermelhoPin, LOW);
    }
    else if (led == 'V') {
      digitalWrite(ledBrancoPin, LOW);
      digitalWrite(ledVerdePin, HIGH);
      digitalWrite(ledVermelhoPin, LOW);
    } else if (led == 'R') {
      digitalWrite(ledBrancoPin, LOW);
      digitalWrite(ledVerdePin, LOW);
      digitalWrite(ledVermelhoPin, HIGH);
      }
  valorSensor = analogRead(ldr);
  Serial.println(valorSensor);
  delay(2000);
}
}
