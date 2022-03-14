#include "notes.h"

/* 
  Notes from:
  https://github.com/robsoncouto/arduino-songs
*/

int sound_cycle_count = -1;
int display_cycle_count = -1;
#define inital_sound_start_delay 25
int sound_start_delay = inital_sound_start_delay;
int wholeNote[2] = {(60000 * 4) / 144, (60000 * 2) / 140};
int currentIndex = 0;

int length[2] = {99, 64};

String names[2] = {"[Tetris]", "[Cantina]"};

int notes[][99][3] = {{ //[][][1] = ↑  ;[][][2] = ↓  ;[][][3] = ↑ + ↓
  //Tetris
{NOTE_E5, 4, 0}, //D5,1;C5,2;B4,3,;A4,0;
  {NOTE_B4, 8, 0},
  {NOTE_C5, 8, 0},
  {NOTE_D5, 4, 1},
  {NOTE_C5, 8, 0},
  {NOTE_B4, 8, 2},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 8, 0},
  {NOTE_C5, 8, 3},
  {NOTE_E5, 4, 0},
  {NOTE_D5, 8, 0},
  {NOTE_C5, 8, 2},
  {NOTE_B4,-4, 3},
  {NOTE_C5, 8, 0},
  {NOTE_D5, 4, 1},
  {NOTE_E5, 4, 0},
  {NOTE_C5, 4, 2},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 8, 0},
  {NOTE_A4, 4, 0},
  {NOTE_B4, 8, 3},
  {NOTE_C5, 8, 0},
  {NOTE_D5,-4, 1},
  {NOTE_F5, 8, 0},
  {NOTE_A5, 4, 0},
  {NOTE_G5, 8, 0},
  {NOTE_F5, 8, 0},
  {NOTE_E5,-4, 0},
  {NOTE_C5, 8, 2},
  {NOTE_E5, 4, 0},
  {NOTE_D5, 8, 1},
  {NOTE_C5, 8, 2},
  {NOTE_B4, 4, 3},
  {NOTE_B4, 8, 0},
  {NOTE_C5, 8, 0},
  {NOTE_D5, 4, 1},
  {NOTE_E5, 4, 1},
  {NOTE_C5, 4, 2},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 4, 0},
  {REST,    4, 0},
  {NOTE_E5, 4, 0},
  {NOTE_B4, 8, 1},
  {NOTE_C5, 8, 3},
  {NOTE_D5, 4, 1},
  {NOTE_C5, 8, 1},
  {NOTE_B4, 8, 0},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 8, 3},
  {NOTE_C5, 8, 0},
  {NOTE_E5, 4, 0},
  {NOTE_D5, 8, 1},
  {NOTE_C5, 8, 1},
  {NOTE_B4,-4, 3},
  {NOTE_C5, 8, 3},
  {NOTE_D5, 4, 0},
  {NOTE_E5, 4, 0},
  {NOTE_C5, 4, 2},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 8, 0},
  {NOTE_A4, 4, 0},
  {NOTE_B4, 8, 3},
  {NOTE_C5, 8, 3},
  {NOTE_D5,-4, 1},
  {NOTE_F5, 8, 0},
  {NOTE_A5, 4, 0},
  {NOTE_G5, 8, 0},
  {NOTE_F5, 8, 0},
  {NOTE_E5,-4, 2},
  {NOTE_C5, 8, 2},
  {NOTE_E5, 4, 0},
  {NOTE_D5, 8, 1},
  {NOTE_C5, 8, 0},
  {NOTE_B4, 4, 3},
  {NOTE_B4, 8, 3},
  {NOTE_C5, 8, 0},
  {NOTE_D5, 4, 1},
  {NOTE_E5, 4, 0},
  {NOTE_C5, 4, 2},
  {NOTE_A4, 4, 0},
  {NOTE_A4, 4, 0},
  {REST,    4, 0},
  {NOTE_E5, 2, 0},
  {NOTE_C5, 2, 1},
  {NOTE_D5, 2, 0},
  {NOTE_B4, 2, 3},
  {NOTE_C5, 2, 2},
  {NOTE_A4, 2, 0},
  {NOTE_GS4,2, 0},
  {NOTE_B4, 4, 3},
  {REST,    8, 0},
  {NOTE_E5, 2, 0},
  {NOTE_C5, 2, 2},
  {NOTE_D5, 2, 0},
  {NOTE_B4, 2, 3},
  {NOTE_C5, 4, 2},
  {NOTE_E5, 4, 0},
  {NOTE_A5, 2, 0},
  {NOTE_GS5,2, 0},
} ,{
    {NOTE_B4,-4, 1}, //B4,1;E5,2
  {NOTE_E5,-4, 0},
  {NOTE_B4,-4, 1},
  {NOTE_E5,-4, 0},
  {NOTE_B4, 8, 1},
  {NOTE_E5,-4, 0},
  {NOTE_B4, 8, 1},
  {REST,    8, 0},
  {NOTE_AS4,8, 0},
  {NOTE_B4, 8, 0},
  {NOTE_B4, 8, 0},
  {NOTE_AS4,8, 0},
  {NOTE_B4, 8, 1},
  {NOTE_A4, 8, 0},
  {REST,    8, 0},
  {NOTE_GS4,8, 0},
  {NOTE_A4, 8, 0},
  {NOTE_G4, 8, 0},
  {NOTE_G4, 4, 0},
  {NOTE_E4,-2, 0},
  {NOTE_B4,-4, 2},
  {NOTE_E5,-4, 0},
  {NOTE_B4,-4, 2},
  {NOTE_E5,-4, 0},
  {NOTE_B4, 8, 2},
  {NOTE_E5,-4, 0},
  {NOTE_B4, 8, 2},
  {REST,    8, 0},
  {NOTE_AS4,8, 0},
  {NOTE_B4, 8, 0},
  {NOTE_A4,-4, 0},
  {NOTE_A4,-4, 0},
  {NOTE_GS4,8, 0},
  {NOTE_A4,-4, 0},
  {NOTE_D5, 8, 0},
  {NOTE_C5,-4, 0},
  {NOTE_B4,-4, 0},
  {NOTE_A4,-4, 0},
  {NOTE_B4,-4, 1},
  {NOTE_E5,-4, 2},
  {NOTE_B4,-4, 1},
  {NOTE_E5,-4, 2},
  {NOTE_B4, 8, 1},
  {NOTE_E5,-4, 2},
  {NOTE_B4, 8, 1},
  {REST,    8, 0},
  {NOTE_AS4,8, 0},
  {NOTE_B4, 8, 0},
  {NOTE_D5, 4, 0},
  {NOTE_D5,-4, 0},
  {NOTE_B4, 8, 0},
  {NOTE_A4,-4, 0},
  {NOTE_G4,-4, 0},
  {NOTE_E4,-2, 0},
  {NOTE_E4, 2, 0},
  {NOTE_G4, 2, 0},
  {NOTE_B4, 2, 1},
  {NOTE_D5, 2, 0},
  {NOTE_F5,-4, 0},
  {NOTE_E5,-4, 2},
  {NOTE_AS4,8, 0},
  {NOTE_AS4,8, 0},
  {NOTE_B4, 4, 0},
  {NOTE_G4, 4, 0}
}};

long startTime = 0;

void initSound() {
  sound_cycle_count = -1;
  display_cycle_count = -1;
  sound_start_delay = inital_sound_start_delay;
  startTime = millis();
}

void targetTick() {
  display_cycle_count++;
  display_cycle_count = display_cycle_count % length[currentIndex];
}

bool displayTargetOnLane1() {
  return notes[currentIndex][display_cycle_count][2] % 2 == 1;
}

bool displayTargetOnLane2() {
  return notes[currentIndex][display_cycle_count][2] >> 1 == 1;
}

void soundTick() {
  if (sound_start_delay > 0) {
    sound_start_delay--;
    return;
  }
  sound_cycle_count++;
  sound_cycle_count = sound_cycle_count % length[currentIndex];
  noTone(13);
  if(notes[sound_cycle_count][0] != NULL){
      tone(13, notes[currentIndex][sound_cycle_count][0]);
  }
}

int getCurrentSoundDelay() {
  if (sound_start_delay > 0) {
    return 1666 / 16;
  }
  int delay = notes[currentIndex][sound_cycle_count][1];
  if (delay > 0) {
    delay = wholeNote[currentIndex]/delay;
  } else {
    delay = wholeNote[currentIndex]/abs(delay);
    delay *= 1.5;
  }
  return delay;
}

int getCurrentTargetDelay() {
  int delay = notes[currentIndex][display_cycle_count][1];
  if (delay > 0) {
    delay = wholeNote[currentIndex]/delay;
  } else {
    delay = wholeNote[currentIndex]/abs(delay);
    delay *= 1.5;
  }
  return delay;
}

//interface:

void setCurrentTrack(int index) {
  Serial.println(index);
  currentIndex = index;
}

int getCurrentTrack() {
  return currentIndex;
}

String getTrackName(int index) {
  return names[index];
}

int getTrackCount() {
  return 2;
}
