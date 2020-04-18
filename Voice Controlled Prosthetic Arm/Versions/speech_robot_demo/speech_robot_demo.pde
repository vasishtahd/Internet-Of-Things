String s;
String str1="move";
String str2="back";
String str3="rotate";
String str4="halt";
String str5="up";
String str6="down";

void setup()
{
  initialize();
}

void draw()
{
  
  listen();
 
}

void respond(String input){
  if (input.length() > 0){  //User speaks any commands 
  voce.SpeechInterface.setRecognizerEnabled(false);    //stop listening, decode and send command to robot
 
  tts.speak(input);   //Play the spoken words
 
  if(input.equals(str1) == true)
  {
    robot.write('w');
  }
  
  if(input.equals(str2) == true)
  {
    robot.write('s');
  }
  
  if(input.equals(str3) == true)
  {
    robot.write('d');
  }
  
 if(input.equals(str4) == true)
  {
    robot.write('x');
  }
  
  
 if(input.equals(str5) == true)
  {
    robot.write('a');
  }
  
  
 if(input.equals(str6) == true)
  {
    robot.write('u');
  }
  
   
  
  voce.SpeechInterface.setRecognizerEnabled(true);
}
}
 
 void mousePressed()
 {
  respond(s);
 }

