

int hrs = 9, mins = 0, sec = 0;
int b = 0, flag = 0;

int a[15];
int alength = 4;


int hourGap = 4, sprayTime = 2;
int pump = 10;
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void setup()
{
  Serial.begin(9600);


  pinMode(pump, OUTPUT);


}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void loop()
{
  mainTime();

  if (hourGap == 1)
  { alength = 13;
  }
  if (hourGap == 2)
  { alength = 7;
  }
  if (hourGap == 3)
  { alength = 5;
  }
  if (hourGap == 4)
  { alength = 4;
  }
  if (hourGap == 5)
  { alength = 3;
  }

  int j = 0;
  a[j] = 6;
  for (j = 1; j < alength; j++)
  {
    a[j] = a[j - 1] + hourGap;


  }


  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.println(sec);

  Serial.print("H.G:");
  Serial.print(hourGap);
  Serial.print("   S.T:");
  Serial.println(sprayTime);
  delay(1000);
  for (j = 0; j < alength; j++)
  {
    if ( (hrs == a[j])  && (hrs <= 18) && (mins == 0))
    {
      pumpStart();

    }
  }
  if (hrs == 19)
  {
    a[0] = 6;
  }

  if (Serial.available() > 0) {
    // read the incoming byte:
    char inputs = Serial.read();

    // say what you got:
    Serial.print("Input Received is ");
    Serial.print(inputs);
    Serial.println();
    boolean a;
    if (inputs == 'a')
    {
      a = hourGapSet();
    }
    if (inputs == 'b')
    {
      a = sprayTimeSet();
    }
    if (inputs == 'c')
    {
      a = demoPumpStart();
    }
  }

}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

void mainTime()
{ long curMs = 1000;
  delay(1000) ;

  if (curMs > 999)
  {
    sec++ ;
  }

  if (sec == 60)
  {
    mins++;
    sec = 0;
  }

  if (mins == 60)
  {
    hrs++;
    mins = 0;
  }

  if (hrs == 24)
  {
    hrs = 0;
  }
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean hourGapSet()
{
  Serial.print("Give Hour Gap: ");
  byte  inputs = Serial.read();

  // say what you got:
  Serial.print(inputs);
  Serial.println();
  hourGap = inputs;
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean sprayTimeSet()
{ Serial.flush();
  Serial.print("Give Spray Time: ");
  int  inputs = Serial.read();
  delay(2000);
  // say what you got:
  Serial.print("Spray Time Received is ");
  Serial.print(inputs);
  Serial.println();
  sprayTime = inputs;

}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean demoPumpStart()
{

  Serial.print(" Pump  On");
  int i;
  digitalWrite(pump, HIGH);

  for (i = 0; i < (2 * sprayTime); i++)
  {
    delay(1000 * 30);
  }

  digitalWrite(pump, LOW);

  mins = mins + sprayTime;
  delay(500);
  Serial.print(" Pump  Off");
  return false;
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

boolean pumpStart()
{

  Serial.print("pump on");
  digitalWrite( pump , HIGH);
  int i;
  for (i = 0; i < (2 * sprayTime); i++)
  {
    delay(1000 * 30);
  }

  digitalWrite( pump , LOW );
  mins += sprayTime;
  delay(500);

  return false;
}


