#include "notes.h"

#define tickDelta 2500

int notes[][2]{
    {8,dS4}, {8,gS4}, {8,dS4}, {8,gS4},
    {8,d4}, {8,gS4}, {8,d4}, {8,gS4},
    {8,cS4}, {8,gS4}, {8,cS4}, {8,gS4},
    {8,c4}, {8,g4}, {8,c4}, {16,c4}, {32,c4}, {32,d4},
    
    {8,dS4}, {8,gS4}, {8,gS4}, {8,gS4},
    {8,d4}, {8,gS4}, {8,d4}, {8,gS4},
    {8,cS4}, {8,gS4}, {8,cS4}, {8,gS4},
    {8,b4}, {8,a4}, {8,gS4}, {8,NULL},
    {8,dS4}, {16,gS4}, {32,NULL}, {32,gS4}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4},{32,fS4}, {32,fS4},
    {8,dS4}, {8,NULL}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4}, {32,fS4}, {32,fS4},
    {8,dS4}, {8,b4}, {16,fS4}, {32,fS4}, {32,fS4}, {16,fS4}, {32,fS4}, {32,dS4},
    {8,fS4}, {8,cS4}, {16,gS4}, {32,gS4}, {32,gS4}, {8,e4},

    {8,dS4}, {16,fS4}, {32,NULL}, {32,fS4}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4}, {32,fS4}, {32,fS4},
    {8,dS4}, {8,NULL}, {16,fS4}, {32,fS4}, {32,g4}, {16,fS4}, {32,fS4}, {32,e4},
    {8,dS4}, {8,b4}, {16,fS4}, {32,fS4}, {32,fS4}, {16,fS4}, {32,fS4}, {32,d4},
    {8,fS4}, {8,cS4}, {16,gS4}, {32,gS4}, {32,cS4}, {8,d4},
    {8,dS4}, {16,gS4}, {32,NULL}, {32,gS4}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4}, {32,fS4}, {32,fS4},
    {8,dS4}, {8,NULL}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4}, {32,fS4}, {32,fS4},
    {8,dS4}, {8,b4}, {16,fS4}, {32,fS4}, {32,fS4}, {16,fS4}, {32,fS4}, {32,dS4},
    {8,fS4}, {8,cS4}, {16,gS4}, {32,gS4}, {32,gS4}, {8,e4},

    {8,dS4}, {16,fS4}, {32,NULL}, {32,fS4}, {16,fS4}, {32,fS4}, {32,gS4}, {16,fS4}, {32,fS4}, {32,fS4},
    {8,dS4}, {8,NULL}, {16,fS4}, {32,fS4}, {32,g4}, {16,fS4}, {32,fS4}, {32,e4},
    {8,dS4}, {8,b4}, {16,fS4}, {32,fS4}, {32,fS4}, {16,fS4}, {32,fS4}, {32,d4},
    {8,fS4}, {8,cS4}, {16,gS4}, {32,gS4}, {32,cS4}, {8,d4}

};

void setup() {
  // put your setup code here, to run once:
  for(int current_note = 0; current_note <= sizeof (notes) / sizeof (notes [0]); current_note++ ){

    noTone(13);
    if(notes[current_note][1] != NULL){
      tone(13, notes[current_note][1]);
    }
    
    delay(tickDelta/notes[current_note][0]);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
