long lastRenderTick = 0;
#define renderTickDelta 50
long lastSoundTick = 0;
#define soundTickDelta getCurrentSoundDelay()
long lastTargetTick = 0;
#define targetTickDelta getCurrentTargetDelay()
long score = 0;
int lives = 0;
bool prevCheckLane1 = false;
bool prevCheckLane2 = false;

byte statesLane1[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte statesLane2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//from sound.ino
extern bool displayTargetOnLane1();
extern bool displayTargetOnLane2();
extern void soundTick();
extern void targetTick();
extern void initSound();
extern int getCurrentSoundDelay();
extern int getCurrentTargetDelay();

//from buttons.ino
extern bool joyStickDown();
extern bool joyStickUp();
extern bool joyStickLeft();
extern bool joyStickRight();

void loopGame() {
  long currMillis = millis();
  if (lastSoundTick + soundTickDelta <= currMillis) {
    lastSoundTick = lastSoundTick + soundTickDelta;
    soundTick();
  }
  if (lastTargetTick + targetTickDelta <= currMillis) {
    lastTargetTick = lastTargetTick + targetTickDelta;
    targetTick();
    if (displayTargetOnLane1()) {
      statesLane1[0] = 1;
    }
    if (displayTargetOnLane2()) {
      statesLane2[0] = 1;
    }
  }
  if (lastRenderTick + renderTickDelta <= currMillis) {
    lastRenderTick = lastRenderTick + renderTickDelta;
    renderAndUpdateDisplay();
  }
  processButtons();
}

void initGame() {
  lastRenderTick = millis();
  lastSoundTick = millis();
  lastTargetTick = millis();
  score = 0;
  lives = 5;
  Serial.println(lives);
  prevCheckLane1 = false;
  prevCheckLane2 = false;
  for (int i = 0; i < 11; i++) {
    statesLane1[i] = 0;
    statesLane2[i] = 0;
  }
  lcd.clear();
  initSound();
  Serial.println(lives);
}

void processButtons() {
  bool checkLane1 = false;
  bool checkLane2 = false;
  if (joyStickUp()) {
    checkLane1 = true;
  }
  if (joyStickDown()) {
    checkLane2 = true;
  }
  if (joyStickLeft() || joyStickRight()) {
    checkLane1 = true;
    checkLane2 = true;
  }
  if (checkLane1 && !prevCheckLane1) {
    if (!checkAndClearLane1()) {
      lives = lives-1;
    }
  }
  prevCheckLane1 = checkLane1;
  if (checkLane2 && !prevCheckLane2) {
    if (!checkAndClearLane2()) {
      lives = lives-1;
    }
  }
  prevCheckLane2 = checkLane2;
}

bool checkAndClearLane1() {
  for (int i = 10; i > 7; i--) {
    if (statesLane1[i] != 0) {
      score = score + calcScoreToAdd(i, statesLane1[i]);
      statesLane1[i] = 0;
      if (statesLane1[i] == 1) {
        statesLane1[i - 1] = 0;
      }
      return true;
    }
  }
  return false;
}

bool checkAndClearLane2() {
  for (int i = 10; i > 7; i--) {
    if (statesLane2[i] != 0) {
      score = score + calcScoreToAdd(i, statesLane2[i]);
      statesLane2[i] = 0;
      if (statesLane2[i] == 1) {
        statesLane2[i - 1] = 0;
      }
      return true;
    }
  }
  return false;
}

int calcScoreToAdd(int index, int state) {
  return max(min(12 - abs(((index - 8) * 8 + state) - 12), 10), 0); //returns a scoreaddition between 0-10
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
  lcd.print(score % 100000);
  lcd.setCursor(0, 1);
  Serial.println(lives);
  for (i = 0; i < lives; i++) {
    lcd.setCursor(i, 1);
    lcd.write(7);
  }
}

bool gameEnded() {
  return lives <= 0;
}

long getScore() {
  return score;
}
