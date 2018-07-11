#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeSerial(D3,D2);

void setup(){
	//pinMode(D2,INPUT);
  //pinMode(D3,OUTPUT);
	Serial.begin(115200);
	//Serial.begin(9600);
	NodeSerial.begin(4800);

}

void loop(){
	//int sensorValue = analogRead(A0);
	//NodeMCU.print(sensorValue);
  //NodeSerial.print(10); 
	//NodeSerial.println("\n");
  while(NodeSerial.available()>0);
  float val = NodeSerial.parseFloat();
  if(NodeSerial.read()== '\n')
  Serial.println(val);
	delay(30);
}
