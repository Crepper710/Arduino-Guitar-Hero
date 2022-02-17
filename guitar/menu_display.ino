int menuItem = 0;
int menuItem_scroll_left[] = {5, 5, 5, 5};
int menuItem_scroll_right[] = {7, 5, 5, 5};
int menuItem_scroll_speed = 50;
int menuItem_count = 4;


extern bool functionButtonPressed();
extern bool lane2ButtonPressed();
extern bool lane1ButtonPressed();

void initMenu() { //setup function
  lcd.clear();
  lcd.autoscroll();
  lcd.print("Guitar Dude");
  lcd.setCursor(0,1);
  lcd.print("press START");
  while(functionButtonPressed() == LOW){}
  lcd.clear();
  lcd.print("use START to select");
  lcd.setCursor(8,1); //center first row
  lcd.write(8);
  lcd.setCursor(0,1); //center second row
}

void loopMenu() { // loopFunction
  lcd.print("[play]    [level selection]    [difficulty]    [creddits]    "); //4 items
  if(lane2ButtonPressed() == HIGH){
    menuItem--;
    
    if(menuItem < 0){
      menuItem = menuItem_count;
      for(int i=0; i < menuItem_scroll_left[menuItem]; i++){
        lcd.scrollDisplayLeft();
        delay(menuItem_scroll_speed);
    }
  }

  if(lane1ButtonPressed() == HIGH){
    menuItem++;
    
    if(menuItem > menuItem_count){
      menuItem = 0;
      for(int j=0; j < menuItem_scroll_right[menuItem]; j++){
        lcd.scrollDisplayRight();
        delay(menuItem_scroll_speed);
      }
    }
  }
}

bool startGame() {
  return true;
}
