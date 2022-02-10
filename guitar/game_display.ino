int lastRenderTick = 0;
#define renderTickDelta 50
int lastSoundTick = 0;
#define soundTickDelta 500

byte states_lane1[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte states_lane2[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

extern bool should_display_on_lane1();

extern bool should_display_on_lane2();

extern void sound_tick();

void loop_game() {
  int curr_millis = millis();
  if (HIGH == digitalRead(10)) {
    states_lane1[0] = 1;
  }
  if (HIGH == digitalRead(9)) {
    states_lane2[0] = 1;
  }
  if (lastSoundTick + soundTickDelta <= curr_millis) {
    Serial.print("m\n");
    Serial.print(lastSoundTick);
    Serial.print("\n");
    Serial.print(curr_millis);
    Serial.print("\n");
    lastSoundTick = lastSoundTick + soundTickDelta;
    sound_tick();
    if (should_display_on_lane1()) {
      states_lane1[0] = 1;
    }
    if (should_display_on_lane2()) {
      states_lane2[0] = 1;
    }
  }
  if (lastRenderTick + renderTickDelta <= curr_millis) {
    lastRenderTick = lastRenderTick + renderTickDelta;
    render_and_update_display();
  }
}

void init_display() {
  for (int i = 0; i < 11; i++) {
    states_lane1[i] = 0;
    states_lane2[i] = 0;
  }
}

void render_and_update_display() {
  int i = 0;
  for (i = 0; i < 11; i++) {
    lcd.setCursor(i + 5, 0);
    if (states_lane1[i] != 0) {
      lcd.write(states_lane1[i] - 1);
      states_lane1[i]++;
    } else {
      lcd.write(" ");
    }
    lcd.setCursor(i + 5, 1);
    if (states_lane2[i] != 0) {
      lcd.write(states_lane2[i] - 1);
      states_lane2[i]++;
    } else {
      lcd.write(" ");
    }
  }
  for (i = 0; i < 11; i++) {
    if (states_lane1[i] >= 7) {
      if (i < 10) {
        states_lane1[i + 1] = states_lane1[i] - 6;
      }
    }
    if (states_lane1[i] >= 8) {
      states_lane1[i] = 0;
    }
    if (states_lane2[i] >= 7) {
      if (i < 10) {
        states_lane2[i + 1] = states_lane2[i] - 6;
      }
    }
    if (states_lane2[i] >= 8) {
      states_lane2[i] = 0;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Score");
  lcd.setCursor(0, 1);
  lcd.print(millis() % 100000);
}
