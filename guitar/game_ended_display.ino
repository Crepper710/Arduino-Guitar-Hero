extern long getScore();
extern bool functionButtonPressed();

void initEndScreen() {
  noTone(13);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YAY! you got a ");
  lcd.setCursor(0, 1);
  lcd.print("score of: ");
  lcd.print(getScore());
}

void loopEndScreen() {

}

bool prevState = false;

bool gameEndedClosed() {
  bool state = functionButtonPressed();
  if (prevState && !state) {
    return true;
  }
  prevState = state;
  return false;
}