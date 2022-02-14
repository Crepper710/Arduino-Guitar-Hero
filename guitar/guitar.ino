#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte note1[8] = {
  B00000,
  B00000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
  B00000,
};

byte note2[8] = {
  B00000,
  B00000,
  B11000,
  B11000,
  B11000,
  B00000,
  B00000,
  B00000,
};

byte note3[8] = {
  B00000,
  B00000,
  B11100,
  B11100,
  B11100,
  B00000,
  B00000,
  B00000,
};

byte note4[8] = {
  B00000,
  B00000,
  B01110,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000,
};

byte note5[8] = {
  B00000,
  B00000,
  B00111,
  B00111,
  B00111,
  B00000,
  B00000,
  B00000,
};

byte note6[8] = {
  B00000,
  B00000,
  B00011,
  B00011,
  B00011,
  B00000,
  B00000,
  B00000,
};

byte note7[8] = {
  B00000,
  B00000,
  B00001,
  B00001,
  B00001,
  B00000,
  B00000,
  B00000,
};

void setup() {
  lcd.createChar(0, note1);
  lcd.createChar(1, note2);
  lcd.createChar(2, note3);
  lcd.createChar(3, note4);
  lcd.createChar(4, note5);
  lcd.createChar(5, note6);
  lcd.createChar(6, note7);
  lcd.begin(16, 2);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  //init_display();
  Serial.begin(9600);
}

extern void initGame();

extern void loopGame();

extern bool gameEnded();

void loop() {
  initGame();
  while (!gameEnded()) {
    loopGame();
  }
}
