// Display simple eksempel sketch
// Arduino reference : https://www.arduino.cc/reference/en/
// LiquidCrystal reference : https://www.arduino.cc/en/Reference/LiquidCrystal

// Sæt porte op
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initialiser vores LCD display

// FUNKTIONER
// begin : Sæt vores LCD op
// print : Skriv tekst til LCD
void setup() {
    lcd.begin(16, 2);
    lcd.print("hello, world!"); // Print besked til lcd
}

// FUNKTIONER
// setCursor : Sæt linje man skriver på LCD (Der er to linjer)
// print : Skriv tekst til LCD
void loop() {
    lcd.setCursor(0, 1); // Sæt til linje to (Vi siger "1", men det er fordi der nul indekseres)
    lcd.print(millis() / 1000); // Skriv sekunder siden arduino controller er blevet genstartet
}
