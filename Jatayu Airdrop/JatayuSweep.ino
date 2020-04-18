// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 


byte PWM_PIN = 11;
 int flag=0;
int pwm_value;
Servo myservo;  // create servo object to control a servo 
 Servo myservo1;  
Servo myservo2; // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  pinMode(PWM_PIN, INPUT);
  Serial.begin(115200);
  myservo2.attach(8); 
  myservo.attach(9); 
  myservo1.attach(7); 
  myservo.write(0); 
  myservo2.write(0);
  myservo1.write(0); 
  flag=0;
  
  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{
  pwm_value= pulseIn(PWM_PIN, HIGH);
  Serial.println(pwm_value);
  digitalWrite(led, LOW); 
   digitalWrite(led, HIGH); 
  myservo.write(0); 
  myservo2.write(0);
  myservo1.write(0); 
 
  if((pwm_value>1500)&&(pwm_value<1900)){
   
  
  myservo1.write(180); 
  myservo2.write(180); 
  delay(1005); 
  
  if(flag==0){
//Second signal  tap   
    while(1){
        Serial.println("2nd");
        pwm_value= pulseIn(PWM_PIN, HIGH);
        Serial.println(pwm_value);
        if(pwm_value>1500){
        
        flag++;
        Serial.println(flag);
        myservo.write(180); 
    // tell servo to go to position in variable 'pos' 
        delay(5);                       // waits 15ms for the servo to reach the position 
        break;
  
          }
    }
  }
//  for(pos = 180; pos>=0; pos-=4)     // goes from 180 degrees to 0 degrees 
  //{   
    //myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  //  delay(5);                       // waits 15ms for the servo to reach the position 
  //} delay(1000);
  
  for(pos =180; pos>=0; pos-=4)     // goes from 180 degrees to 0 degrees 
  {   myservo1.write(pos); 
    myservo2.write(pos);   
      delay(5);
  }   delay(1000);
 
  

 }
 
} 
