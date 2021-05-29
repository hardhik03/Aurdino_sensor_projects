#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();
  
  char a[12] = "Hello Hardhik";
  int i=0;
  for(i<0;i<12;i++)
  {
    lcd.setCursor(i,0);
    lcd.print(a[i]);
  }
}
void loop()
{
  
}
