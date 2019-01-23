// Lyskryds med lyd sketch
// Arduino reference : https://www.arduino.cc/reference/en/

const int greenPin = 13; // Grøn port
const int yellowPin = 12; // Gul port
const int redPin = 8; // Rød port
const int buzzerPin = 9; // Buzzer port

int waitRed=10; // Rød ventetid
int waitGreen=5; // Grøn ventetid

// FUNKTIONER
// tone : Funktion der laver lyd med vores buzzer (Kig i reference)
void soundFast(int delay, int interval){
    // Hurtig skiftene lyd
    // param delay : Ventetid i millisekunder
    // param invterval : iteration interval

    int iterations = delay / interval; // Regn iterationer ud
    for (int i = 0; i <= iterations; i++){ // Loop det
        int waitTime = (int) interval/2; // Divider ventetid med 2 (Kast til Integer)
        tone(buzzerPin, 1000, waitTime); // Lav lyd med buzzer
        delay(waitTime);
    }
}

void soundSlow(int delay, int interval){
    // langsom skiftene lyd
    // param delay : Ventetid i millisekunder
    // param invterval : iteration interval

    int iterations = delay / interval; // Regn iterationer ud
    for (int i = 0; i <= iterations; i++){
        int waitTime = (int) interval/2; // Divider ventetid med 2
        tone(buzzerPin, 1000, waitTime); // Lav lyd med buzzer
        delay(waitTime);
    }
}


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

// FUNKTIONER
// digitalWrite HIGH : Send strøm igennem
// digitalWrite LOW : Stop strøm
// delay X : Vent X millisekunder

void loop() {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);

    soundSlow(1000*waitRed, 100); // Kør lyd i waitRed*1000 millisekunder med interval 100millisekunder

    digitalWrite(yellowPin, HIGH);

    delay(2000);

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);

    soundFast(1000*waitGreen);

    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);

    delay(2000);
}
