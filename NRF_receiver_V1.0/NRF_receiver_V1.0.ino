

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define in1 2
#define in2 3
#define in3 4
#define in4 5

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop() 
{
  
  if (radio.available()) 
  {
    char text[8];
    radio.read(&text, sizeof(text));
    //Serial.println(text);

     if(text[0]=='H')
          digitalWrite(in1,LOW);
        else if(text[0]=='L')
              digitalWrite(in1,HIGH);
      if(text[1]=='H')
          digitalWrite(in2,LOW);
        else if(text[1]=='L')
              digitalWrite(in2,HIGH);
       if(text[2]=='H')
          digitalWrite(in3,LOW);
       else if(text[2]=='L')
             digitalWrite(in3,HIGH);
       if(text[3]=='H')
          digitalWrite(in4,LOW);
        else if(text[3]=='L')
              digitalWrite(in4,HIGH);
    
 }             
}
