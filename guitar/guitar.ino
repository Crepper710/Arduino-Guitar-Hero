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
}

void loop() {
  loop_game();
}

int lastRenderTick = 0;
#define renderTickDelta 30

byte states_lane1[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte states_lane2[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop_game() {
  if (HIGH == digitalRead(10)) {
    states_lane1[0] = 1;
  }
  if (HIGH == digitalRead(9)) {
    states_lane2[0] = 1;
  }
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
    
  lcd.setCursor(14, 0);
  lcd.write(255);
  lcd.setCursor(14, 1);
  lcd.write(255);
  for (int i = 0; i < 10; i++) {
    
  lcd.setCursor(14, 0);
  lcd.write(" ");
  lcd.setCursor(14, 1);
  lcd.write(" ");
  }
  if (lastRenderTick + renderTickDelta <= millis()) {
    lastRenderTick = millis();
    render_and_update_display();
  }
}

void init_display() {
  for (int i = 0; i < 16; i++) {
    states_lane1[i] = 0;
    states_lane2[i] = 0;
  }
}

void render_and_update_display() {
  int i = 0;
  for (i = 0; i < 16; i++) {
    lcd.setCursor(i,0);
    if (states_lane1[i] != 0) {
      lcd.write(states_lane1[i] - 1);
      states_lane1[i]++;
    } else {
      lcd.write(" ");
    }
    lcd.setCursor(i,1);
    if (states_lane2[i] != 0) {
      lcd.write(states_lane2[i] - 1);
      states_lane2[i]++;
    } else {
      lcd.write(" ");
    }
  }
  for (i = 0; i < 16; i++) {
    if (states_lane1[i] >= 7) {
      if (i < 15) {
        states_lane1[i + 1] = states_lane1[i] - 6;
      }
    }
    if (states_lane1[i] >= 8) {
      states_lane1[i] = 0;
    }
    if (states_lane2[i] >= 7) {
      if (i < 15) {
        states_lane2[i + 1] = states_lane2[i] - 6;
      }
    }
    if (states_lane2[i] >= 8) {
      states_lane2[i] = 0;
    }
  }
}
