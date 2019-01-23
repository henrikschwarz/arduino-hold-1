// Lyskryds sketch
// Arduino reference : https://www.arduino.cc/reference/en/

int greenPin = 13; // Grøn port
int yellowPin = 12; // Gul port
int redPin = 8; // Rød port

int waitRed=10; // Rød ventetid
int waitGreen=5; // Grøn ventetid

void setup() {
    // Sæt porte som ouput
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(redPin, OUTPUT);

    // Initialiser; Tænd alle LEDer
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, HIGH);

    delay(500);

    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
}

// digitalWrite HIGH = Send strøm igennem
// digitalWrite LOW = Stop strøm
// delay X = Vent X millisekunder

void loop() {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);

    delay(1000*waitRed);

    digitalWrite(yellowPin, HIGH);

    delay(2000);

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);

    delay(1000*waitGreen);

    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);

    delay(2000);
}
