#include <LiquidCrystal.h>//include lcd  library

//create object of type Liquid Crystal and name lcd
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  //initiate lcd and pass the columns,rows
  lcd.begin(16,2);
  lcd.setCursor(0,0);
 
  }
void loop() {
  //lcd.autoscroll();
  
  lcd.print("Hello, Dunia!");
  lcd.scrollDisplayLeft();
  delay(80);
  //lcd.clear();
  lcd.cursor();
  //delay(500);
  //lcd.noCursor();
  delay(500);
  }
