#include "command_processor.h"

void checkSerial1(void); 
void checkSerialUSB(void);

char newMsgUSB[1050];
char newMsg[1050];
char newMsgLP[1050];

static bool doneRecieving = false; 
static bool doneRecievingUSB = false; 
static uint8_t led = 13; 
    static uint16_t i = 0;
    static char tempCharLP = '\0';

    
void setup() 
{
  Serial.begin(9600);
  Serial1.begin(57600);
  memset(newMsg, 0, 1026);
  memset(newMsgUSB, 0, 1026);
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
    checkSerialUSB();
    if (true == doneRecievingUSB)
    {
        Serial.println(newMsgUSB);
        Serial1.println(newMsgUSB);
        doneRecievingUSB = false; 
        memset(newMsgUSB, 0, 1026);
    }

    checkSerial1();
    if (true == doneRecieving)
    {
        Serial.println(newMsg);
        processCommand(newMsg); 
        memset(newMsg, 0, 1026);
        doneRecieving = false; 
        i = 0; 
    }
}


void checkSerialUSB()
{
    static uint16_t i = 0;
    static char tempChar = '\0';

    i = 0;
    while (Serial.available()) 
    {
        doneRecievingUSB = true; 
        tempChar = Serial.read();
        if (tempChar != '\n')
        {
            newMsgUSB[i] = tempChar;
            i++;
            if (i > 1023)
            {
                newMsgUSB[i+1] = '\0';
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


void checkSerial1()
{
  
    while (Serial1.available()) 
    {
        
        tempCharLP = Serial1.read();
        if (tempCharLP != '\n')
        {
            newMsg[i++] = tempCharLP;            
            if (i > 1023)
            {
                newMsg[i+1] = '\0';
                doneRecieving = true; 
                break;
            } 
        }
        else
        {
            doneRecieving = true; 
            newMsg[i+1] = '\0';
            break;
        }
    }
}
