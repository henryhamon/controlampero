#include <ezButton.h>

ezButton btnA(13);
ezButton btnB(12);
ezButton btnC(14);
ezButton btnD(27);
ezButton btnE(26);
ezButton btnF(25);
ezButton btnG(33);
ezButton btnH(32);
ezButton btnDown(35);
ezButton btnUp(34);

void footSetup() {
  btnA.setDebounceTime(50);
  btnB.setDebounceTime(50);
  btnC.setDebounceTime(50);
  btnD.setDebounceTime(50);

  btnE.setDebounceTime(50);
  btnF.setDebounceTime(50);
  btnG.setDebounceTime(50);
  btnH.setDebounceTime(50);
  
  btnUp.setDebounceTime(50);
  btnDown.setDebounceTime(50);
}

void footEvent() {
  btnUp.loop();
  btnDown.loop();
  btnA.loop();
  btnB.loop();
  btnC.loop();
  btnD.loop();
  btnE.loop();
  btnF.loop();
  btnG.loop();
  btnH.loop();

  if (btnUp.isPressed()) {
    Serial.println("Up is pressed");
  }
  
  if (btnDown.isPressed()) {
    Serial.println("Down is pressed");
  }

  if (btnA.isPressed()) {
    Serial.println("A is pressed");
  }
  
  if (btnB.isPressed()) {
    Serial.println("B is pressed");
  }
  
  if (btnC.isPressed()) {
    Serial.println("C is pressed");
  }
  
  if (btnD.isPressed()) {
    Serial.println("D is pressed");
  }
  
  if (btnE.isPressed()) {
    Serial.println("E is pressed");
  }
  
  if (btnF.isPressed()) {
    Serial.println("F is pressed");
  }
  
  if (btnG.isPressed()) {
    Serial.println("G is pressed");
  }
  
  if (btnH.isPressed()) {
    Serial.println("H is pressed");
  }
}