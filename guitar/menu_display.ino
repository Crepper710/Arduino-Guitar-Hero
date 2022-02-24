String menuItem_display[] = {"[play]","[level]","[difficulty]"};
int menuItem_display_center[] = {2, 2 , 5};
int menuItem = 0;
//int menuItem_scroll_left[] = {5, 5, 5, 5};
//int menuItem_scroll_right[] = {7, 5, 5, 5};
int menuItem_scroll_speed = 50;
int menuItem_count = 3;
bool gameStatus = false;
bool firstStart = true;


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
    lcd.write(8);
    lcd.setCursor(0,1); //center second row
    //lcd.print("[play]    [level selection]    [difficulty]    [creddits]    "); //4 items
    //lcd.print("|");
    lcd.print(menuItem_display[0]);
  
}

void loopMenu() { // loopFunction
  //Serial.println("3");
  
  if(joyStickDown()){
    menuItem--;
    Serial.println(menuItem);
    
    if(menuItem < 0){
      menuItem = menuItem_count;
    }
    //for(int i=0; i < menuItem_scroll_left[menuItem]; i++){
      //lcd.scrollDisplayLeft();
      //delay(menuItem_scroll_speed);
    //}
    lcd.clear();
  }

  if(joyStickUp()){
    
    Serial.println("b");
    menuItem++;
    Serial.println(menuItem);
    
    if(menuItem > menuItem_count){
      menuItem = 0;}
      //for(int j=0; j < menuItem_scroll_right[menuItem]; j++){
        //lcd.scrollDisplayRight();
        //delay(menuItem_scroll_speed);
        //}
        lcd.clear();
  }

  if(functionButtonPressed() == HIGH){
    gameStatus = true;
  }
  lcd.setCursor(menuItem_display_center[menuItem], 0);
  lcd.print(menuItem_display[menuItem]);
  Serial.println(menuItem);
  delay(1000);
}

bool startGame() {
  return gameStatus;
}
