bool buttonPressed(int id) {
  if (HIGH == digitalRead(id)) {
    return true;
  }
  return false;
}

bool joyStickDown() {
  return analogRead(A0) <= 100;
}

bool joyStickUp() {
  return analogRead(A0) >= 923;
}

bool joyStickLeft() {
  return analogRead(A1) <= 100;
}

bool joyStickRight() {
  return analogRead(A1) >= 923; 
}

bool functionButtonPressed() {
  return !buttonPressed(6);
}
