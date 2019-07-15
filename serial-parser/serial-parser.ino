#include "command_processor.h"

void checkSerial(void); 


char newMsg[1025];
static bool doneRecieving = false; 
static uint8_t led = 13; 

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  memset(newMsg, 0, 1025);
  pinMode(led, OUTPUT);
  Serial.println("Booting up...");
}

void loop() {
/*
bool done_once = false; 
char* hexana = "62616e616e610a"; 
char asciiana[10];

hex2ascii(hexana, asciiana, strlen(hexana), strlen(asciiana));

if (done_once == false)
{
  Serial.println("test");
  Serial.println(asciiana);
  done_once = true; 
}
*/

 checkSerial();
 if (doneRecieving)
  {
    processCommand(newMsg); 
    doneRecieving = false; 
  }

  if (newMsg[0] != '\0')
  {
    memset(newMsg, 0, 1025);
  }
  
}


void checkSerial()
{
 static uint16_t i = 0;
 static char tempChar = '\0';

  i = 0;
  while (Serial.available()) 
  {
    doneRecieving = true; 
    tempChar = Serial.read();
    if (tempChar != '\n')
    {
      newMsg[i] = tempChar;
      i++;
      if (i > 1025)
      {
        i = 0;
        break;
      } 
    }
    else
    {
      Serial.flush();
      i = 0;
      break;
      
    }
  }
  
}
