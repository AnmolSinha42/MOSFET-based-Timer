#include <LiquidCrystal_I2C.h>
#include <Wire.h>

float measured = 0;
float source = 5.47;
float x = 0;
float time = 0;
int button = 0;
9
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //pinMode(A0,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);         // Move cursor to character 0 on line 0
  lcd.print("Time:");  
}
void loop() {
  measured = (analogRead(A0)/1023.0)*25;
  x = measured;
  if (x<3){
    //time = 6.47646*x*x*x*x-42.30994*x*x*x+86.50814*x*x-49.85866*x+15.56221;
    time = 1.75941*x*x+1.8666*x+12.72101;
    
  }
  else if(x<3.35) {
    time = 10.63347*x*x*x-47.68965*x*x+57.16941*x+5.02118;
  }
  else{
    time = 5.9211*x*x*x*x-38.65994*x*x*x+80.12311*x*x-46.99575*x+15.56473;
  }
  
  button = digitalRead(8);
  if (button == 1){
    lcd.setCursor(0, 1);         // Move cursor to character 0 on line 0
    lcd.print(time);  //0 to 3.45V
    lcd.print(" s     ");
  }
  delay(50);
}

