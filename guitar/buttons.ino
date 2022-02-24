bool buttonPressed(int id) {
  if (HIGH == digitalRead(id)) {
    return true;
  }
  return false;
}

bool joyStickLeft() {
  return analogRead(A0) <= 100;
}

bool joyStickRight() {
  return analogRead(A0) >= 923;
}

bool joyStickUp() {
  return analogRead(A1) <= 100;
}

bool joyStickDown() {
  return analogRead(A1) >= 923; 
}

bool functionButtonPressed() {
  return !buttonPressed(6);
}
