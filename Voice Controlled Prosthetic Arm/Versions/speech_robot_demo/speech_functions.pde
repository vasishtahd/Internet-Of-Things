//import the libraries
import guru.ttslib.*;
import processing.serial.*;

//give our instances names
Serial robot;
TTS tts;

public void initialize()
{
  voce.SpeechInterface.init("libraries/voce-0.9.1/lib", true, true,"libraries/voce-0.9.1/lib/gram","digits"); //the following initiates the voce library
  robot = new Serial(this,Serial.list()[0],9600);  //start serial port and also tts
  tts = new TTS();
  //the following settings control the voice sound
  tts.setPitch( 90 );
  tts.setPitchRange( 90 );
}

public void listen()
{

  if (voce.SpeechInterface.getRecognizerQueueSize()>0) {    //if voce recognizes anything being said
    s = voce.SpeechInterface.popRecognizedString();      //assign the string that computer heard to the variable s
    println("you said: " + s);                          //print what was heard to the debug window.
  }
}

