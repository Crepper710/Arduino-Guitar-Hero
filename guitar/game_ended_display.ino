extern long getScore();
extern bool functionButtonPressed();

bool prevState = false;

void initEndScreen() {
  noTone(13);
  prevState = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YAY! you got a ");
  lcd.setCursor(0, 1);
  lcd.print("score of: ");
  lcd.print(getScore());
}

void loopEndScreen() {

}

bool gameEndedClosed() {
  return false;
}
