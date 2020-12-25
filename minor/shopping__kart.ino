/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buzzer=9;        //initialize the buzzer
char card[13];       //Mentioning the card Character value 
int i=0;             //when no product is available so it will intialize as zero
int total=0;         //when cart will be empty so the totall value will also zero 
int in1=0;           //intialize the RFID TAG value zero as start 
int in2=0;
int in3=0;
int in4=0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("ANSHUL    ");
  lcd.setCursor(0,1);
  lcd.print("WEL-COMES YOU");
  pinMode(9,OUTPUT);
  delay(2000);
  lcd.clear();
}

void loop() {
  if(Serial.available()>0)
  {
    delay(12);
    digitalWrite(buzzer,1);
    i=0;
    while(Serial.available()>0)
    {
      card[i]=Serial.read();
      i++;
      delay(1);
      
    }
    Serial.println(card);
    lcd.setCursor(0,0);
    digitalWrite(buzzer,0);
    
     
      if(strncmp(card,"5300B7EACDC3",11)==0)//86007305CD3D    86007598C3A8  860075987C17
      {
        Serial.print("match1");
        if(in1==0)
        {
          in1=1;
        
        lcd.print("Cinthole IN=99/-         ");
        total=total+99;
        
        }
           else
            {
              in1=0;
              lcd.print("Cinthole OUT=99/-       ");
            total=total-99;
            }
          
        }




if(strncmp(card,"86007305CD3D",11)==0)//86007305CD3D    86007598C3A8  860075987C17
      {
        Serial.print("match1");
        if(in2==0)
        {
          in2=2;
        
        lcd.print("Lux  IN= 15/-         ");
        total=total+15;
        
        }
           else
            {
              in2=0;
              lcd.print("Lux  OUT= 15/-          ");
            total=total-15;
            }
          
        }


        if(strncmp(card,"86007598C3A8",11)==0)//86007305CD3D    86007598C3A8  860075987C17
      {
        Serial.print("match1");
        if(in3==0)
        {
          in3=2;
        
        lcd.print("Senitizer IN=49/-         ");
        total=total+49;
        
        }
           else
            {
              in3=0;
              lcd.print("Senitizer OUT=49/-          ");
            total=total-49;
            }
          
        }


        if(strncmp(card,"860075987C17",11)==0)//86007305CD3D    86007598C3A8  860075987C17
      {
        Serial.print("match1");
        if(in4==0)
        {
          in4=2;
        
        lcd.print("Mask IN=50/-          ");
        total=total+50;
        
        }
           else
            {
              in4=0;
              lcd.print("Mask OUT=50/-              ");
            total=total-50;
            }
          
        }




while(Serial.available()>0)
{
  Serial.read();
}

delay(2000);
      
  }
  lcd.setCursor(0,1);
  lcd.print("Total=");
  lcd.print(total);
  lcd.print("/-  ");
}
