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
byte my_mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte my_ip[] = { 192,168,178,177 };
byte loghost[] = { 192,168,178,52 };
byte gateway[] = { 192, 168, 178, 1 };   //your router's IP address
byte subnet[] = { 255, 255, 255, 0 };    //subnet mask of the network 

void setup() {
  Ethernet.begin(my_mac, my_ip);
  Serial.begin(9600);
  Syslog.setLoghost(loghost);
  delay(2000);
}
  
void loop() {
  Syslog.logger(2,2,"Arduino","failure");
  Serial.print("msg sent ");
  delay(2000);
}
