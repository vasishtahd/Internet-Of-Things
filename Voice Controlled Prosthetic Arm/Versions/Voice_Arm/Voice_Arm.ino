#include <Servo.h> 

Servo myservo1; //Thumb
Servo myservo2; //Index
Servo myservo3; //Middle
Servo myservo4; //Ring
Servo myservo5; //Little

String voice;
int led = 13 ; //Connect LED 1 To Pin #2
int Thumb = 3;
int Index = 4;
int Middle = 5;
int Ring = 6;
int Little = 7;

//--------------------------Call A Function-------------------------------// 

//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  myservo1.attach(Thumb);
  myservo2.attach(Index);
  myservo3.attach(Middle);
  myservo4.attach(Ring);
  myservo5.attach(Little);
  Serial.println("Ready....");
  
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "*grab")
       {
         Serial.println("Grab");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         
       }  //Turn Off All Pins (Call Function)
       else if(voice == "*release")
       {
         Serial.println("Release");
         myservo1.write(0);
         myservo2.write(0);
         myservo3.write(0);
         myservo4.write(0);
         myservo5.write(0);
         delay(150);
       } //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
      else if(voice == "*1") 
      {
         Serial.println("One");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         myservo2.write(0);
         delay(150);
      }
      else if(voice == "*2") 
      {
         Serial.println("Two");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         myservo2.write(0);
         myservo3.write(0);
         delay(150);
      }
      else if(voice == "*3") 
      {
         Serial.println("Three");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         myservo2.write(0);
         myservo3.write(0);
         myservo4.write(0);
         delay(150);
      }
      else if(voice == "*4") 
      {
         Serial.println("Four");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         myservo2.write(0);
         myservo3.write(0);
         myservo4.write(0);
         myservo5.write(0);
         delay(150);
      }
      else if(voice == "*5") 
      {
         Serial.println("Five");
         myservo1.write(180);
         myservo2.write(180);
         myservo3.write(180);
         myservo4.write(180);
         myservo5.write(180);
         delay(150);
         myservo1.write(0);
         myservo2.write(0);
         myservo3.write(0);
         myservo4.write(0);
         myservo5.write(0);
         delay(150);
      }
 
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating
