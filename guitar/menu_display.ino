extern int getTrackCount();
extern void setCurrentTrack(int index);
extern String getTrackName(int index);
extern bool functionButtonPressed();
extern bool joyStickLeft();
extern bool joyStickRight();
extern bool joyStickUp();
extern bool joyStickDown();

//settings for main menu
String menuItem_display[] = {"[play]","[level]"};
int menuItem_display_center[] = {5, 5}; //needed spaces for displaying in center
int menuItem = 0; //selected item
int menuItem_count = 1; //amount of items

//settings for level selection
//items are fetched from sound.ino
int levelItem_display_center[] = {5, 5};
int levelItem = 0;
int levelItem_count = getTrackCount();

bool gameStatus;
bool firstStart = true;
int cursor_delay = 300;
int menuSection = 0; //0=menu; 1=level;


void initMenu() { //setup function
  gameStatus = false;
  if (firstStart == true){ //initial starting screen is only shown on boot
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Music Man 2");
    lcd.setCursor(2,1);
    lcd.print("press START");
    while(!functionButtonPressed()){}
  }
    delay(1000);
    firstStart = false;
    lcd.clear();
    lcd.setCursor(8,0); //center first row
    lcd.write(7);
}

void loopMenu() { // loopFunction
  switch(menuSection){ //includes main menus & level selection
    case 0: //menu
      lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);
      lcd.print(menuItem_display[menuItem]);
    
      if(joyStickDown()){
        menuItem--;
        
        if(menuItem < 0){
          menuItem = menuItem_count;
        }
      lcd.clear();
      lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);  //ajusts cursor to center
      lcd.print(menuItem_display[menuItem]);  //writes current menu item
      delay(cursor_delay);
      }
    
      if(joyStickUp()){
        menuItem++;
        
        if(menuItem > menuItem_count){
          menuItem = 0;}
          lcd.clear();
          lcd.setCursor(8,0); //center first row
      lcd.write(7);
      lcd.setCursor(menuItem_display_center[menuItem], 1);  //ajusts cursor to center
      lcd.print(menuItem_display[menuItem]);  //writes current menu item
      delay(cursor_delay);
      }

    //navigates to selected menu/function
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
        lcd.print(getTrackName(levelItem - 1)); //fetches the level name from sound.ino
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
        lcd.print(getTrackName(levelItem - 1)); //fetches the level name from sound.ino
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
      }
      else {
        lcd.setCursor(0, 1);
        lcd.print(getTrackName(levelItem - 1)); //fetches the level name from sound.ino
      }
      delay(cursor_delay);
      }

    //navigates to selected menu/function
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

bool startGame() { //starts game if true
  return gameStatus;
}
