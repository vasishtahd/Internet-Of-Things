 
 
#include 
#include 
 
char formkey[] = ""; //Replace with your Key
byte mac[] = { 0x90,0xA2,0xDA,0x00,0x55,0x8D};  //Replace with your Ethernet shield MAC
byte ip[] = { 192,168,0,109};  //The Arduino device IP address
byte subnet[] = { 255,255,255,0};
byte gateway[] = { 192,168,0,254};
byte server[] = { 209,85,229,101 }; // Google IP
Client client(server, 80);
 
void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip , gateway , subnet);
  delay(1000);
  Serial.println("connecting...");
}
 
void loop(){
  String data;
  data+="";
  data+="entry.0.single=";
  data+=analogRead(A0);
  data+="&entry.2.single=";
  data+=analogRead(A1);
  data+="&submit=Submit";
 
  if (client.connect()) {
    Serial.println("connected");
 
    client.print("POST /formResponse?formkey=");
    client.print(formkey);
    client.println("&ifq HTTP/1.1");
    client.println("Host: spreadsheets.google.com");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Connection: close");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.print(data);
    client.println();
 
    Serial.print("POST /formResponse?formkey=");
    Serial.print(formkey);
    Serial.println("&ifq HTTP/1.1");
    Serial.println("Host: spreadsheets.google.com");
    Serial.println("Content-Type: application/x-www-form-urlencoded");
    Serial.println("Connection: close");
    Serial.print("Content-Length: ");
    Serial.println(data.length());
    Serial.println();
    Serial.print(data);
    Serial.println();
 
  }
  delay(1000);
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
  }
 
  delay(10000);
 
}
