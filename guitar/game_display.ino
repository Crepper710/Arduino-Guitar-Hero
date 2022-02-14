long lastRenderTick = 0;
#define renderTickDelta 50
long lastSoundTick = 0;
#define soundTickDelta getCurrentDelay()
long score = 0;
int lives = 0;

byte statesLane1[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte statesLane2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

extern bool shouldDisplayOnLane1();

extern bool shouldDisplayOnLane2();

extern void soundTick();

extern int getCurrentDelay();

void loopGame() {
  long currMillis = millis();
  if (HIGH == digitalRead(10)) {
    statesLane1[0] = 1;
  }
  if (HIGH == digitalRead(9)) {
    statesLane2[0] = 1;
  }
  if (lastSoundTick + soundTickDelta <= currMillis) {
    lastSoundTick = lastSoundTick + soundTickDelta;
    soundTick();
    if (shouldDisplayOnLane1()) {
      statesLane1[0] = 1;
    }
    if (shouldDisplayOnLane2()) {
      statesLane2[0] = 1;
    }
  }
  if (lastRenderTick + renderTickDelta <= currMillis) {
    lastRenderTick = lastRenderTick + renderTickDelta;
    renderAndUpdateDisplay();
  }
}

void initGame() {
  lastRenderTick = millis();
  lastSoundTick = millis();
  score = 0;
  lives = 5;
  for (int i = 0; i < 11; i++) {
    statesLane1[i] = 0;
    statesLane2[i] = 0;
  }
}

void processButtons() {

}

void renderAndUpdateDisplay() {
  int i = 0;
  for (i = 0; i < 11; i++) {
    lcd.setCursor(i + 5, 0);
    if (statesLane1[i] != 0) {
      lcd.write(statesLane1[i] - 1);
      statesLane1[i]++;
    } else {
      lcd.write(" ");
    }
    lcd.setCursor(i + 5, 1);
    if (statesLane2[i] != 0) {
      lcd.write(statesLane2[i] - 1);
      statesLane2[i]++;
    } else {
      lcd.write(" ");
    }
  }
  for (i = 0; i < 11; i++) {
    if (statesLane1[i] >= 7) {
      if (i < 10) {
        statesLane1[i + 1] = statesLane1[i] - 6;
      }
    }
    if (statesLane1[i] >= 8) {
      statesLane1[i] = 0;
      if (i >= 10) {
        lives = lives - 1;
      }
    }
    if (statesLane2[i] >= 7) {
      if (i < 10) {
        statesLane2[i + 1] = statesLane2[i] - 6;
      }
    }
    if (statesLane2[i] >= 8) {
      statesLane2[i] = 0;
      if (i >= 10) {
        lives = lives - 1;
      }
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Score");
  lcd.setCursor(0, 1);
  lcd.print(lives % 100000);
}

bool gameEnded() {
  return lives <= 0;
}
