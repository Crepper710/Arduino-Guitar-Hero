String menuItem_display[] = {"[play]","[level]","[difficulty]"};
int menuItem_display_center[] = {5, 5 , 2};
int menuItem = 0;
int menuItem_scroll_speed = 50;
int menuItem_count = 2;
bool gameStatus = false;
bool firstStart = true;
int cursor_delay = 300;

extern void setup_level();
extern bool functionButtonPressed();
extern bool joyStickLeft();
extern bool joyStickRight();
extern bool joyStickUp();
extern bool joyStickDown();

void initMenu() { //setup function
  if (firstStart == true){
    lcd.clear();
    lcd.print("Guitar Dude");
    lcd.setCursor(0,1);
    lcd.print("press START");
    Serial.println("1");
    while(!functionButtonPressed()){}
  }
    delay(1000);
    Serial.println("2");
    firstStart = false;
    lcd.clear();
    lcd.print("use START to select");
    lcd.clear();
    lcd.setCursor(8,0); //center first row
    lcd.write(7);
    lcd.setCursor(0,1); //center second row
    lcd.print(menuItem_display[0]);
  
}

void loopMenu() { // loopFunction
  
  if(joyStickDown()){
    menuItem--;
    
    if(menuItem < 0){
      menuItem = menuItem_count;
    }
    //for(int i=0; i < menuItem_scroll_left[menuItem]; i++){
      //lcd.scrollDisplayLeft();
      //delay(menuItem_scroll_speed);
    //}
    lcd.clear();
    lcd.setCursor(8,0); //center first row
  lcd.write(7);
  lcd.setCursor(menuItem_display_center[menuItem], 1);
  lcd.print(menuItem_display[menuItem]);
  Serial.println(menuItem);
  delay(cursor_delay);
  }

  if(joyStickUp()){
    
    Serial.println("b");
    menuItem++;
    Serial.println(menuItem);
    
    if(menuItem > menuItem_count){
      menuItem = 0;}
      lcd.clear();
      lcd.setCursor(8,0); //center first row
  lcd.write(7);
  lcd.setCursor(menuItem_display_center[menuItem], 1);
  lcd.print(menuItem_display[menuItem]);
  Serial.println(menuItem);
  delay(cursor_delay);
  }

  if(functionButtonPressed()){
    switch(menuItem){
      case 0:
        gameStatus = true;
        break;

      case 1:
        setup_level();
        delay(cursor_delay);
        break;
      case 2:
        delay(0);
        break;
    }
  }
  
  
}

bool startGame() {
  return gameStatus;
}
