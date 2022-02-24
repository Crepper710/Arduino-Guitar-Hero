extern long getScore();
extern bool functionButtonPressed();
extern bool functionButtonPressed();
extern bool lane2ButtonPressed();
extern bool lane1ButtonPressed();

String taunts_lines[] = {"broken buttons?", "That is a start", "Nice", "still plenty to go", "Press those buttons better!", "press: ↑↑↓↓←→←→ B A START" };
int taunts_score[] = {0, 69, 69, 100, 200, 300};
int pageDisplayed = 0;

bool prevState = false;

void initEndScreen() {
  noTone(13);
  prevState = false;
  lcd.clear();
  while(true){
    lcd.print("score: ");
    lcd.print(getScore());
    while(lane1ButtonPressed() == LOW && lane2ButtonPressed() == LOW && functionButtonPressed() == LOW){}
    lcd.clear();
    for (int i = 0; i < sizeof(taunts_lines); i++){
      if(taunts_score[i]<= getScore() >= taunts_score[i++]){
      lcd.print(taunts_lines[i]);
      }
    }
  }
  //lcd.print("YAY! you got a ");
  //lcd.setCursor(0, 1);
  //lcd.print("score of: ");
  //lcd.print(getScore());
}

void loopEndScreen() {

}

bool gameEndedClosed() {
  return false;
}
