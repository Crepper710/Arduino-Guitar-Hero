bool buttonPressed(int id) {
  if (HIGH == digitalRead(id)) {
    Serial.println("button");
    return true;
  }
  return false;
}

bool lane1ButtonPressed() {
  return buttonPressed(10);
}

bool lane2ButtonPressed() {
  return buttonPressed(9);
}

bool functionButtonPressed() {
  return buttonPressed(10);
}
