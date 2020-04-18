//Import the Bitvoice library. 
#include <BitVoicer11.h>

//Initiate the BitVoicer Serial Class. 
BitVoicerSerial bvSerial = BitVoicerSerial();

// Store the data type retreived by getData()
byte dataType = 4;

//create an array for all of the outpins. 
int OutPutPins[] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
int pinCount = 22;


void setup() {
  // put your setup code here, to run once:
  // start serial communication at 9600kbs
  Serial.begin(9600);
  // loop to set all pins in array as outputs
  for(int activePin =0; activePin < pinCount; activePin++) {
    pinMode(OutPutPins[activePin],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // we dont need anything in the loop.
}

// this function runs every time serial data is available. 
// in the serial buffer after a loop.
void serialEvent()
{
    //Reads the serial bugger and stores the received data type. 
    dataType = bvSerial.getData();
    
    //check if the data type is the same as the one in coming from bitvoicer.
    if (dataType == BV_INT)
    {
       //The way that this is set up will avoid a bunch of if/else statements for the majority of the outputs. 
       // assign an INT to hold a pin number
       int pinNumber = bvSerial.intData;
       //Write to the pinNumber based on the current state of the output and reverse it. 
       digitalWrite(pinNumber, !digitalRead(pinNumber));
       delay(50);    
    }
    
    // if data type is string do somethign a little bit different. 
    if (dataType == BV_STR)
    {
        if (bvSerial.strData == "AwningL1")
        {
           digitalWrite(52, HIGH);
        }
        else if (bvSerial.strData == "AwningL0")
        {
          digitalWrite(52, LOW);
        }
        else if (bvSerial.strData == "SlideL1")
        {
         digitalWrite(53,HIGH); 
        }
        else if (bvSerial.strData == "SlideL0")
        {
         digitalWrite(53,LOW); 
        }      
    }
}
