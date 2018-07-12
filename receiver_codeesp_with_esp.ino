#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "kebonatap"
#define WIFI_PASSWORD "cabekeriting"

#define FIREBASE_HOST "trial-2004b.firebaseio.com"
#define FIREBASE_AUTH "qfubcGoUzimx5tp4doG2T1CXH80vdlZKjwEFDiya"

SoftwareSerial NodeSerial(D3,D2);

void setup(){
	//pinMode(D2,INPUT);
  //pinMode(D3,OUTPUT);
	Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
	//Serial.begin(9600);
	NodeSerial.begin(4800);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //startTime = millis();
}

void loop(){
	//int sensorValue = analogRead(A0);
	//NodeMCU.print(sensorValue);
  //NodeSerial.print(10); 
	//NodeSerial.println("\n");
  while(NodeSerial.available()>0);
  float val = NodeSerial.parseFloat();
  if(NodeSerial.read()== '\n'){
    String valName = Firebase.pushFloat("val", val);
    if(Firebase.failed()){
      Serial.println(Firebase.error());          
    }
  //if(currentTime - startTime > period){    
  }
  
  //Serial.println(val);
	delay(2000);
}
