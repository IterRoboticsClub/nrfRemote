
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() 
{
      Serial.begin(9600);
      radio.begin();
      radio.openWritingPipe(address);
      radio.setPALevel(RF24_PA_MIN);
      radio.stopListening();
      pinMode(A0,INPUT);
      pinMode(A1,INPUT);
      pinMode(A2,INPUT);
      pinMode(A3,INPUT);
      pinMode(5,INPUT);
      pinMode(2,INPUT);
      pinMode(3,INPUT);
      pinMode(4,INPUT);

      //for lcd

       lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print(" TEAM IRC ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WIRELESS REMOTE ");
    
      
}
void loop() 
{
      char text[8];
     
     if(digitalRead(A0)==HIGH)
     {
      text[0] = 'H';
    //  radio.write(&text, sizeof(text));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 0 ");
     }
      else if(digitalRead(A0)==LOW)
      {
        text[0] = 'L';
        
      }
    
     if(digitalRead(A1)==HIGH)
     {
        text[1] = 'H';
    //  radio.write(&text, sizeof(text1));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 1 ");
     }
      else if(digitalRead(A1)==LOW)
      {
        text[1] = 'L';
        
      }
     
     
      
      if(digitalRead(A2)==HIGH)
     {
       text[2] = 'H';
     // radio.write(&text2, sizeof(text2));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 2 ");
     }

       else if(digitalRead(A2)==LOW)
      {
        text[2] = 'L';
        
      }
      
      
      if(digitalRead(A3)==HIGH)
     {
       text[3] = 'H';
      //radio.write(&text3, sizeof(text3));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 3 ");
     }

      else if(digitalRead(A3)==LOW)
      {
        text[3] = 'L';
        
      }
      
      
      
      if(digitalRead(2)==HIGH)
     {
       text[4] = 'H';
      //radio.write(&text4, sizeof(text4));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 4 ");
     }
      else if(digitalRead(2)==LOW)
      {
        text[4] = 'L';
        
      }

     if(digitalRead(3)==HIGH)
     {
      text[5] = 'H';
      //radio.write(&text5, sizeof(text5));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 5 ");
     }

   else if(digitalRead(3)==LOW)
      {
        text[5] = 'L';
        
      }
    
     
     if(digitalRead(4)==HIGH)
     {
           text[6] = 'H';
     // radio.write(&text6, sizeof(text6));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 6 ");
     }
      else if(digitalRead(4)==LOW)
      {
        text[6] = 'L';
        
      }
     
     if(digitalRead(5)==HIGH)
     {
           text[7] = 'H';
     // radio.write(&text7, sizeof(text7));
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Button 7 ");
     }
      else if(digitalRead(5)==LOW)
      {
        text[7] = 'L';
        
      }
      Serial.println(text);
     radio.write(&text,sizeof(text));      
}
