extern long getScore();
extern bool functionButtonPressed();
extern bool joyStickDown();
extern bool joyStickUp();
extern bool joyStickLeft();
extern bool joyStickRight();

bool prevState = false;

void showEndScreen() {
  noTone(13);
  waitForNoInput();
  prevState = false;
  lcd.clear();

  lcd.print("score: ");
  lcd.print(getScore());

  waitForInput();
  waitForNoInput();
}

void waitForInput() {
  while(!joyStickUp() && !joyStickDown() && !joyStickLeft() && !joyStickRight() && !functionButtonPressed()){}
}

void waitForNoInput() {
  while(joyStickUp() || joyStickDown() || joyStickLeft() || joyStickRight() || functionButtonPressed()){}
}
