#include "notes.h"

/* 
  Notes from:

  Tetris theme - (Korobeiniki) 
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/

int sound_cycle_count = -1;
int display_cycle_count = -1;
#define inital_sound_start_delay 25
int sound_start_delay = inital_sound_start_delay;
int wholeNote = (60000 * 4) / 144;

int notes[][3] = {
  {NOTE_E5, 4, 3},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_C5,8, 3},
  {NOTE_B4,8, 0},
  {NOTE_A4, 4, 0},
  {NOTE_A4,8, 0},
  {NOTE_C5,8, 3},
  {NOTE_E5,4, 0},
  {NOTE_D5,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_B4, -4, 3},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_E5,4, 0},
  {NOTE_C5, 4, 0},
  {NOTE_A4,4, 0},
  {NOTE_A4,8, 0},
  {NOTE_A4,4, 3},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5, -4, 0},
  {NOTE_F5,8, 0},
  {NOTE_A5,4, 0},
  {NOTE_G5,8, 0},
  {NOTE_F5,8, 0},
  {NOTE_E5, -4, 0},
  {NOTE_C5,8, 0},
  {NOTE_E5,4, 0},
  {NOTE_D5,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_B4, 4, 0},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_E5,4, 0},
  {NOTE_C5, 4, 0},
  {NOTE_A4,4, 0},
  {NOTE_A4,4, 0},
  {REST, 4, 0},
  {NOTE_E5, 4, 0},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_C5,8, 0},
  {NOTE_B4,8, 0},
  {NOTE_A4, 4, 0},
  {NOTE_A4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_E5,4, 0},
  {NOTE_D5,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_B4, -4, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_E5,4, 0},
  {NOTE_C5, 4, 0},
  {NOTE_A4,4, 0},
  {NOTE_A4,8, 0},
  {NOTE_A4,4, 0},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5, -4, 0},
  {NOTE_F5,8, 0},
  {NOTE_A5,4, 0},
  {NOTE_G5,8, 0},
  {NOTE_F5,8, 0},
  {NOTE_E5, -4, 0},
  {NOTE_C5,8, 0},
  {NOTE_E5,4, 0},
  {NOTE_D5,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_B4, 4, 0},
  {NOTE_B4,8, 0},
  {NOTE_C5,8, 0},
  {NOTE_D5,4, 0},
  {NOTE_E5,4, 0},
  {NOTE_C5, 4, 0},
  {NOTE_A4,4, 0},
  {NOTE_A4,4, 0},
  {REST, 4, 0},
  {NOTE_E5,2, 0},
  {NOTE_C5,2, 0},
  {NOTE_D5,2, 0},
  {NOTE_B4,2, 0},
  {NOTE_C5,2, 0},
  {NOTE_A4,2, 0},
  {NOTE_GS4,2, 0},
  {NOTE_B4,4, 0},
  {REST,8, 0},
  {NOTE_E5,2, 0},
  {NOTE_C5,2, 0},
  {NOTE_D5,2, 0},
  {NOTE_B4,2, 0},
  {NOTE_C5,4, 0},
  {NOTE_E5,4, 0},
  {NOTE_A5,2, 0},
  {NOTE_GS5,2, 0},
};

long startTime = 0;

void initSound() {
  sound_cycle_count = -1;
  display_cycle_count = -1;
  sound_start_delay = inital_sound_start_delay;
  startTime = millis();
}

void targetTick() {
  display_cycle_count++;
  display_cycle_count = display_cycle_count % 162;
}

bool displayTargetOnLane1() {
  return notes[display_cycle_count][2] % 2 == 1;
}

bool displayTargetOnLane2() {
  return notes[display_cycle_count][2] >> 1 == 1;
}

void soundTick() {
  if (sound_start_delay > 0) {
    sound_start_delay--;
    return;
  }
  sound_cycle_count++;
  sound_cycle_count = sound_cycle_count % 162;
  noTone(13);
  if(notes[sound_cycle_count][0] != NULL){
      tone(13, notes[sound_cycle_count][0]);
  }
}

int getCurrentSoundDelay() {
  if (sound_start_delay > 0) {
    return wholeNote / 16;
  }
  int delay = notes[sound_cycle_count][1];
  if (delay > 0) {
    delay = wholeNote/delay;
  } else {
    delay = wholeNote/abs(delay);
    delay *= 1.5;
  }
  return delay;
}

int getCurrentTargetDelay() {
  int delay = notes[display_cycle_count][1];
  if (delay > 0) {
    delay = wholeNote/delay;
  } else {
    delay = wholeNote/abs(delay);
    delay *= 1.5;
  }
  return delay;
}
