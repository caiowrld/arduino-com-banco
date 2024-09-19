float valorSensor = 0;
const int ledBrancoPin = 4;     // Pino do LED Branco
const int ledVerdePin = 8;      // Pino do LED Verde
const int ledVermelhoPin = 10;   // Pino do LED Vermelho
const int buzzerPin = 5;        // Pino do Buzzer
const int ldr = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(ledBrancoPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    char led = Serial.read();
    if (led == 'B') {
      digitalWrite(ledBrancoPin, HIGH);
      digitalWrite(ledVerdePin, LOW);
      digitalWrite(ledVermelhoPin, LOW);
      digitalWrite(buzzerPin, LOW); 
    }
    else if (led == 'V') {
      digitalWrite(ledBrancoPin, LOW);
      digitalWrite(ledVerdePin, HIGH);
      digitalWrite(ledVermelhoPin, LOW);
      digitalWrite(buzzerPin, LOW); 
    } else if (led == 'R') {
      digitalWrite(ledBrancoPin, LOW);
      digitalWrite(ledVerdePin, LOW);
      digitalWrite(ledVermelhoPin, HIGH);
      digitalWrite(buzzerPin, HIGH); 
      }
  valorSensor = analogRead(ldr);
  Serial.println(valorSensor);
  delay(2000);
  }
}