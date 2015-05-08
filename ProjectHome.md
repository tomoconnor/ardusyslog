This project develops a library for Arduino that permits to log across the Ethernet shield to a Syslog server.

It has the following goals:

  * Implement a syslog client that speaks UDP.
  * The implementation of TCP transport is not a primary goal but will be a later option
  * Support for IPv6 is not a primary goal but is a later option as soon as the underlying IP socket supports IPv6.
  * Implement support for unstructured messages as well as structured messages thereby implement as much as possible of RFC 5424