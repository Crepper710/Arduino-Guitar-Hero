buttonStart = digitalRead(8);
buttonLeft = digitalRead(9);
buttonRight = digitalRead(10);

int menuItem = 0
int menuItem_scroll_left[] = {5, 5, 5, 5};
int menuItem_scroll_right[] = {7, 5, 5, 5};
int menuItem_scroll_speed = 50;;
int menuItem_count = 4

byte arrow_down[8] = {
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100,
};
lcd.createChar(8, arrow_down);

void initMenu() { //setup function
  lcd.clear();
  lcd.autoscroll();
  lcd.print("Guitar Dude");
  lcd.setCursor(0,1);
  lcd.print("press START")
  while(buttonStart == LOW){}
  lcd.clear();
  lcd.print("use START to select");
  lcd.setCursor(8,1); //center first row
  lcd.write(8);
  lcd.setCursor(0,1); //center second row
}

void loopMenu() { // loopFunction
  lcd.print("[play]    [level selection]    [difficulty]    [creddits]    ") //4 items
  if(buttonLeft == HIGH){
    menuItem--;
    
    if(menuItem < 0){
      menuItem = menuItem_count;
      for(j=0; j < menuItem_scroll_left[menuItem]; j++){
        lcd.scrollDisplayLeft();
        delay(menuItem_scroll_speed);
    }
  }

  if(buttonRight == HIGH){
    menuItem++;
    
    if(menuItem > menuItem_count){
      menuItem = 0;
      for(j=0; j < menuItem_scroll_right[menuItem]; j++){
        lcd.scrollDisplayRight();
        delay(menuItem_scroll_speed);
      }
    }
  }
}

bool startGame() {
  return false;
}
