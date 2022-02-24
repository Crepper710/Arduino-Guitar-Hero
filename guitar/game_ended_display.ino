extern long getScore();
extern bool functionButtonPressed();
extern bool joyStickDown();
extern bool joyStickUp();
extern bool joyStickLeft();
extern bool joyStickRight();

String taunts_lines[6] = {"broken buttons?", "That is a start", "Nice", "still plenty to go", "Press those buttons better!", "press: ↑↑↓↓←→←→ B A START" };
int taunts_score[7] = {0, 0, 69, 69, 100, 200, 300};
int pageDisplayed = 0;

bool prevState = false;

void initEndScreen() {
  noTone(13);
  waitForNoInput();
  prevState = false;
  lcd.clear();

  lcd.print("score: ");
  lcd.print(getScore());

  waitForInput();
  waitForNoInput();
  
  lcd.clear();
  for (int i = 0; i < sizeof(taunts_lines); i++){
    if(taunts_score[i]<= getScore() >= taunts_score[i + 1]){
      lcd.print(taunts_lines[i]);
    }
  }

  waitForInput();
  waitForNoInput();
  //lcd.print("YAY! you got a ");
  //lcd.setCursor(0, 1);
  //lcd.print("score of: ");
  //lcd.print(getScore());
}

void waitForInput() {
  while(!joyStickUp() && !joyStickDown() && !joyStickLeft() && !joyStickRight() && !functionButtonPressed()){}
}

void waitForNoInput() {
  while(joyStickUp() && joyStickDown() && joyStickLeft() && joyStickRight() && functionButtonPressed()){}
}

void loopEndScreen() {

}

bool gameEndedClosed() {
  return false;
}
