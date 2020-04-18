#include <LiquidCrystal.h>

int hrs=9, mins=0, sec=0;
int b=0, flag=0;
int keypad();
int a[15];
int alength=4;

LiquidCrystal lcd(12, 11, 14, 15, 16, 17);
int r1=2, r2=3, r3=4, r4=5;
int c1=6, c2=7, c3=8, c4=9;
int colm1, colm2, colm3, colm4;

int hourGap=4, sprayTime=2;
int pump=10;
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void setup()
{
  
  lcd.begin(16, 2);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void loop() 
{
mainTime();

if(hourGap==1)
{ alength=13;
}
if(hourGap==2)
{ alength=7;
}
if(hourGap==3)
{ alength=5;
}
if(hourGap==4)
{ alength=4;
}
if(hourGap==5)
{ alength=3;
}

int j=0;
a[j]=6;
for(j=1; j<alength; j++)
{
   a[j]=a[j-1]+ hourGap;
   
   
}

keypad(); 
  lcd.setCursor(0,0);
  lcd.print(hrs);
  lcd.print(":");
  lcd.print(mins);
  lcd.print(":");
  lcd.print(sec);

  lcd.setCursor(0,1);
  lcd.print("H.G:");
  lcd.print(hourGap);
  lcd.print("   S.T:");
  lcd.print(sprayTime);
  
for(j=0; j< alength; j++)
{
  if( (hrs==a[j])  && (hrs<=18) && (mins==0))
  {  
     pumpStart();
     lcd.clear();    
}}
if(hrs==19)
  {
  a[0]=6; 
  }


}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void mainTime()
{  long curMs = 1000;
   delay(1000) ;
  
  if(curMs > 999)
    {sec++ ;}
  
  if (sec == 60)
  { lcd.clear();
    mins++;
   sec = 0;}
  
  if (mins == 60)
  { lcd.clear();
    hrs++;
   mins = 0;}
   
  if (hrs == 24)
  {lcd.clear();
    hrs = 0;}}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean hourGapSet()
{  flag=0;
  
   lcd.clear();
   while(flag==0)
  
  { 
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Enter gap hrs:");
    lcd.setCursor(0, 0);
    hourGap=keypad();
    delay(500);
    
    
    if(( hourGap>5)||(hourGap<1))
    {
    lcd.setCursor(0, 0);
    lcd.print("Wrong Input");
    delay(2000);
    lcd.clear();
    delay(1000);
    flag=0;
    }
    
  }

  lcd.clear();
  lcd.setCursor(0, 1); 
  lcd.print("Reset Complete");
  lcd.clear();
  delay(1000);
  return false;
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean sprayTimeSet()
{
  delay(1000);
  lcd.clear();
  flag=1;
  while(flag==1)
  { 
    lcd.setCursor(0, 1);
    lcd.print("Enter spray mins");
    delay(500);
    lcd.setCursor(0, 0);
    sprayTime=keypad();
      
    delay(500);
    if((sprayTime>5)|| (sprayTime<1))
    {
    lcd.setCursor(0, 0);
    lcd.println("Wrong Input");
    delay(2000);
    lcd.clear();  
    flag=1;
    }}

  lcd.print("Reset Complete");
  lcd.clear();
  return false;
  
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean demoPumpStart()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Pump  On");
  int i;
  digitalWrite(pump,HIGH);

  for(i=0; i< 1; i++)
  {
    delay(200*30); 
  }
  
  digitalWrite(pump, LOW);

  mins= mins+ sprayTime;
  delay(500);
  lcd.clear();
  return false;
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean pumpStart()
  {   
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("pump on");   
      digitalWrite( pump , HIGH);
      int i;
      for(i=0; i< (2*sprayTime); i++)
     { 
      delay(1000*30); 
     }
     
     digitalWrite( pump , LOW );
     mins += sprayTime;
     delay(500);
     lcd.clear();
     return false;
  }

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean reset(void)
{ 
  lcd.setCursor(0, 0);
  lcd.print("hello");
  delay(500);
  flag=0;

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Enter hrs");

  
  while(flag==0)
  {
    delay(500);
    lcd.setCursor(0, 0);
    hrs=keypad();
    while(flag==1)
    {
      delay(500);
      lcd.setCursor(1, 0);
      b=keypad();
      delay(1000);
    }
   
  }
 hrs=hrs*10+b;

  lcd.clear();
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("Got hrs");
  delay(500);
  lcd.clear();
  
  lcd.setCursor(0, 1);
  lcd.print("Enter mins");
  
  
  
  while(flag==2)
  {
    delay(1000);
    lcd.setCursor(0, 0);

    mins=keypad();
    delay(1000);
    while(flag==3)
    { 
      lcd.setCursor(1, 0);
      b=keypad();
    }  
  }
  
delay(1000);
mins=mins*10+b;

delay(500);
 lcd.setCursor(0, 0);
 lcd.print("Got mins.");
 lcd.clear();
 
  if((!(hrs<24&&hrs>0))||(!(mins<60&&mins>=0)))
  {
    lcd.print("Reset Failed");
    delay(1000);
    boolean c123=reset();
  }
 lcd.clear();
 
 lcd.print("Reset Successful");
 delay(1000);
 lcd.clear();
 return false; 
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
int keypad(void)
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  colm4=digitalRead(c4);
  if(colm1==LOW)
  {
    lcd.print("1");
    flag++;
    delay(500);
    return(1);
  }
  else
  {
    if(colm2==LOW)
    {  
      lcd.print("2");
      flag++;

      delay(500); 
      return(2);
    }
    else
    {
      if(colm3==LOW)
      { 
        lcd.print("3");
        flag++;
        delay(500);
        return(3);
      }
      else
      {
        if(colm4==LOW)
        { 
          lcd.print("A");
          flag++;
          boolean a=reset();
          delay(500);
          }}}}

  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  colm4=digitalRead(c4);
  if(colm1==LOW)
  { 
    lcd.print("4");
    flag++;
    return(4);
    delay(200);
  }
  else
  {
    if(colm2==LOW)
    { 
      lcd.print("5");
      flag++;
      delay(500);
      return(5);
    }
    else
    {
      if(colm3==LOW)
      { 
        lcd.print("6");
        flag++;
        delay(500);
        return(6);
      }
      else
      {
        if(colm4==LOW)
        { 
          lcd.print("B");
          boolean b=hourGapSet();
          delay(500);
          
        }
      }
    }
  }

  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  colm4=digitalRead(c4);
  if(colm1==LOW)
  { 
    lcd.print("7");
    flag++;
    delay(500);
    return(7);
  }
  else
  {
    if(colm2==LOW)
    { 
      lcd.print("8");
      flag++;
      delay(500);
      return(8);
    }
    else
    {
      if(colm3==LOW)
      { 
        lcd.print("9");
        flag++;
        delay(500);
        return(9);
      }
      else
      {
        if(colm4==LOW)
        { 
          lcd.print("C");
          boolean c=sprayTimeSet();
          delay(200);
          
        }
      }
    }
  }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  colm4=digitalRead(c4);
  if(colm1==LOW)
  { 
    lcd.println("*");
    delay(200);
    return('*');
  }
  else
  {
    if(colm2==LOW)
    { 
      lcd.print("0");
      delay(500);
      flag++;
      return(0);
    }
    else
    {
      if(colm3==LOW)
      { 
        lcd.print("#");
        flag++;
      
      }
      else
      {
        if(colm4==LOW)
        { 
          lcd.println("D");
          delay(500);
          demoPumpStart();
         
        }

      }
    }
  }  }
