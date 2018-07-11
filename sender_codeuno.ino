#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(2,3);

void setup(){
	
	//Serial.begin(9600);
  Serial.begin(9600);
	ArduinoSerial.begin(4800);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);

}

void loop(){

  int sensorValue = analogRead(A0); //nilai diganti dengan input LAT LONG
	ArduinoSerial.print(sensorValue);
  ArduinoSerial.println("\n");
	//while(ArduinoSerial.available()>0){
	//float val = ArduinoSerial.parseFloat();
	//if(ArduinoSerial.read()== '\n'){
	//Serial.println(val);
	

delay(30);
}
