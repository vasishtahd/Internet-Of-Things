#include <SoftwareSerial.h>

char var;
int m1=6;
int m12=7;
int m2=8;
int m22=9;
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m22, OUTPUT);





}

void loop() // run over and over
{
  if (Serial.available())
 { var = Serial.read();
 if(var=='w')
    {  digitalWrite(m1, HIGH);   
        
       digitalWrite(m12, LOW);   
        
          digitalWrite(m2, HIGH);   
        
       digitalWrite(m22, LOW);   
        delay(5000);
    }
    if(var=='s')
    {  digitalWrite(m12, HIGH);   
        
       digitalWrite(m1, LOW);   
        
          digitalWrite(m22, HIGH);   
       
       digitalWrite(m2, LOW);   
       
    }
    if(var=='a')
    {  digitalWrite(m1, HIGH);   
         
       digitalWrite(m12, LOW);   
        
          digitalWrite(m2, LOW);   
         
       digitalWrite(m22,HIGH);   
        delay(1000);
    }
     if(var=='d')
    {  digitalWrite(m1, LOW);   
               digitalWrite(m12, HIGH);   
        
          digitalWrite(m2, HIGH);   
        
       digitalWrite(m22, LOW);   
        delay(1000);
    }
        
  
}
}
