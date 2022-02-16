buttonStart = digitalRead(PIN);
buttonLeft = digitalRead(PIN);
buttonRight = digitalRead(PIN);

int menuItem = 0
int menuItem_scroll_left[] = {};
int menuItem_scroll_right[] = {7, };

void initMenu() { //setup function
  lcd.clear();
  lcd.autoscroll();
  lcd.print("Guitar Dude");
  lcd.setCursor(0,1);
  lcd.print("press START")
  while(buttonStart == LOW){}
  lcd.clear();
  lcd.print("use START to select")
  lcd.setCursor(0,1); //center first item!
}

void loopMenu() { // loopFunction
  lcd.print("[play]    [level selection]    [difficulty]    [creddits]    ") //4 items
  if(buttonLeft == HIGH){
    menuItem--;
    
    if(menuItem < 0){
      menuItem = 4;
      lcd.scrollDisplayLeft(menuItem_scroll_left[menuItem]);
    }
  }

  if(buttonRight == HIGH){
    menuItem++;
    
    if(menuItem > 4){
      menuItem = 0;
      lcd.scrollDisplayRight(menuItem_scroll_right[menuItem]);
    }
  }
}

bool startGame() {
  return false;
}
