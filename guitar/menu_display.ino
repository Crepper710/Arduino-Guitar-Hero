extern int getTrackCount();
extern void setCurrentTrack(int index);
extern String getTrackName(int index);
extern bool functionButtonPressed();
extern bool joyStickLeft();
extern bool joyStickRight();
extern bool joyStickUp();
extern bool joyStickDown();

String menuItem_display[] = {"[play]","[level]"};
int menuItem_display_center[] = {5, 5};
int menuItem = 0;
int menuItem_scroll_speed = 50;
int menuItem_count = 1;

int levelItem_display_center[] = {5, 5};
int levelItem = 0;
int levelItem_count = getTrackCount();

bool gameStatus;
bool firstStart = true;
int cursor_delay = 300;
int menuSection = 0; //0=menu; 1=level;



void initMenu() { //setup function
  gameStatus = false;
  if (firstStart == true){
    lcd.clear();
    lcd.print("Guitar Dude");
    lcd.setCursor(0,5);
    lcd.print("press START");
    while(!functionButtonPressed()){}
  }
    delay(1000);
    firstStart = false;
    //lcd.clear();
    //lcd.print("use START to select");
    lcd.clear();
    lcd.setCursor(8,0); //center first row
    lcd.write(7);
    //lcd.setCursor(5,1); //center second row
    //lcd.print(menuItem_display[0]);
}

void loopMenu() { // loopFunction
  switch(menuSection){
    case 0: //menu
      lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);
      lcd.print(menuItem_display[menuItem]);
      //delay(cursor_delay);
    
      if(joyStickDown()){
        menuItem--;
        
        if(menuItem < 0){
          menuItem = menuItem_count;
        }
        lcd.clear();
        lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);
      lcd.print(menuItem_display[menuItem]);
      delay(cursor_delay);
      }
    
      if(joyStickUp()){
        menuItem++;
        
        if(menuItem > menuItem_count){
          menuItem = 0;}
          lcd.clear();
          lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);
      lcd.print(menuItem_display[menuItem]);
      delay(cursor_delay);
      }
    
      if(functionButtonPressed()){
        switch(menuItem){
          case 0: //play
            gameStatus = true;
            break;
    
          case 1: //level
            menuSection = 1;
            delay(cursor_delay);
            lcd.clear();
            break;
        }
      }
      break;



    case 1: //level selection
      lcd.setCursor(8,0); //center first row
      lcd.write(7);
      if(levelItem == 0){
        lcd.setCursor(4, 1);
        lcd.print("[return]");
      } else {
        lcd.setCursor(0, 1);
        lcd.print(getTrackName(levelItem - 1));
      }
      
      if(joyStickDown()){
        levelItem--;
        
        if(levelItem < 0){
          levelItem = levelItem_count;
        }
        lcd.clear();
        lcd.setCursor(8,0); //center first row
      lcd.write(7);
      if(levelItem == 0){
        lcd.setCursor(4, 1);
        lcd.print("[return]");
      } else {
        lcd.setCursor(0, 1);
        lcd.print(getTrackName(levelItem - 1));
      }
      delay(cursor_delay);
      }
    
      if(joyStickUp()){
        levelItem++;
        
        if(levelItem > levelItem_count){
          levelItem = 0;}
          lcd.clear();
          lcd.setCursor(8,0); //center first row
      lcd.write(7);
      if(levelItem == 0){
        lcd.setCursor(4, 1);
        lcd.print("[return]");
      } else {
        lcd.setCursor(0, 1);
        lcd.print(getTrackName(levelItem - 1));
      }
      //lcd.setCursor(levelItem_display_center[levelItem], 1);
      //lcd.print(levelItem_display[levelItem]);
      delay(cursor_delay);
      }
    
      if(functionButtonPressed()){ 
        if(levelItem != 0){
          setCurrentTrack(levelItem -1);
          menuSection = 0;
          lcd.clear();
        }
        menuSection = 0;
          lcd.clear();
        delay(cursor_delay);
      }
      break;
  }
  
  
}

bool startGame() {
  return gameStatus;
}
