#include <UbidotsArduino.h>


#include <SPI.h>
#include <WiFi.h>

#include <UbidotsArduino.h>
#define ID  " "  // Put here your Ubidots variable ID
#define TOKEN  " "  // Put here your Ubidots TOKEN



char ssid[] = "D-Link_DIR-600M"; //  your network SSID (name)
char pass[] = "d1i2v3a4";       // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

Ubidots client(TOKEN);

void setup(){
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true);
    }

    String fv = WiFi.firmwareVersion();
    if (fv != "1.1.0") {
        Serial.println("Please upgrade the firmware");
    }

    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }
        
}
void loop(){
        float value = analogRead(A0);
        client.add(ID, value);
        client.sendAll();
}
