// I2C Slave Receiver and Transmitter
// by Turgut Guneysu
// 
// Used in demo of micro:bit to Arduino I2C comms
// Receiver will print all characters received.
// Transmitter will use a 32 byte buffer,
//  but messages can be shorter by placing a \n at the end.

#include <Wire.h>

void setup() {
  Wire.begin(13);               // join i2c bus with address #13
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.println("Ready...");
}

void loop() {
}

void receiveEvent(int howMany) {    // I2C Receive Event Handler        
    char c;
  Serial.println(howMany);
  while (Wire.available()) { 
    c = Wire.read(); 
    Serial.print(c);         
  }
  Serial.print(" / LAST char: ");   // Also print the last char as DEC
  Serial.print(c);
  Serial.print(" = ");
  Serial.println(c,DEC);         
}

void requestEvent() {               // I2C Transmit event Handler
  char response[32] = "Hello from Arduino.\n";  
  Wire.write(response);             // respond with \n terminated message
}
