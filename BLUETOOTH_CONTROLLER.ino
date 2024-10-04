#include <M5StickCPlus2.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("M5Stick", "M5Stack", 100); // Name, Manufacturer, Battery Level

void setup() {
  // Initialize M5StickC Plus2
  M5.begin();
  
  // Initialize BLE Keyboard
  bleKeyboard.begin();
}

void loop() {
  // Update M5StickC Plus2 button states
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(70, 20);
  M5.Lcd.print("BLE");
  M5.Lcd.setCursor(20, 50);
  M5.Lcd.print("Controller");
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(40, 75);
  M5.Lcd.print("By m5dev1000");
  M5.update();
  
  // Check if BLE is connected
  if (bleKeyboard.isConnected()) {
    // Check if the A button was pressed
    if (M5.BtnA.wasPressed()) {
      // Send play/pause media key
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      
      // Optional: Add a delay to avoid multiple triggers from one press
      delay(200);
    }
        if (M5.BtnB.wasPressed()) {
      // Send the next track media key
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      
      // Optional: Add a delay to avoid multiple triggers from one press
      delay(200);
    }
        if (M5.BtnPWR.wasPressed()) {
      // Send the previous track media key
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      
      // Optional: Add a delay to avoid multiple triggers from one press
      delay(200);
    }
  }
}
