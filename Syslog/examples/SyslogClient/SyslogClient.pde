/*
 created 24 Jun 2011
 by Markus Heller
 
 This code is in the public domain.
 */

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <Syslog.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte my_mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x60, 0xC5 };
byte my_ip[] = { 192,168,10,80 };
byte loghost[] = { 192,168,10,58 };
byte gateway[] = { 192, 168, 10, 1 };   //your router's IP address
byte subnet[] = { 255, 255, 255, 0 };    //subnet mask of the network 

void setup() {
  Ethernet.begin(my_mac, my_ip);
  Serial.begin(9600);
  Syslog.setLoghost(loghost);
  Syslog.logger(1,5,"Arduino","setup finished");
  Serial.println("startup msg sent ");
  delay(2000);
}
  
void loop() {
  Syslog.logger(1,6,"Arduino","loop");
  Serial.println("loop msg sent ");
  delay(2000);
}
