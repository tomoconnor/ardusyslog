/*
  Syslog.cpp - An Arduino library for a sending Syslog messages.
  Copyright (C) 2011 Markus Heller <heller@relix.de>
  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "Syslog.h"
#include "Udp.h"

void Syslog::setLoghost(uint8_t * server_ip) {
    UDP Udp;
    /* Variable: ip_syslogserver */
    ip_syslogserver = server_ip;
}

void Syslog::setOwnHostname(const char[] my_hostname) {
    /* Variable: my_own_hostname 
      The HOSTNAME field SHOULD contain the hostname and the domain name of
      the originator in the format specified in STD 13 [RFC1034].  This
      format is called a Fully Qualified Domain Name (FQDN) in this
      document.
   
      In practice, not all syslog applications are able to provide an FQDN.
      As such, other values MAY also be present in HOSTNAME.  This document
      makes provisions for using other values in such situations.  A syslog
      application SHOULD provide the most specific available value first.
      The order of preference for the contents of the HOSTNAME field is as
      follows: 
 
      1.  FQDN
      2.  Static IP address
      3.  hostname
      4.  Dynamic IP address
      5.  the NILVALUE

      If an IPv4 address is used, it MUST be in the format of the dotted
      decimal notation as used in STD 13 [RFC1035].  If an IPv6 address is
      used, a valid textual representation as described in [RFC4291],
      Section 2.2, MUST be used.
   
      Syslog applications SHOULD consistently use the same value in the
      HOSTNAME field for as long as possible.
   
      The NILVALUE SHOULD only be used when the syslog application has no
      way to obtain its real hostname.  This situation is considered highly
      unlikely.
    */
    my_own_hostname = my_hostname;
}

void Syslog::setAppname(const char[] my_appname) {
    /* Variable: my_own_appname
      The APP-NAME field SHOULD identify the device or application that
      originated the message.  It is a string without further semantics.
      It is intended for filtering messages on a relay or collector.
   
      The NILVALUE MAY be used when the syslog application has no idea of
      its APP-NAME or cannot provide that information.  It may be that a
      device is unable to provide that information either because of a
      local policy decision, or because the information is not available,
      or not applicable, on the device.
   
      This field MAY be operator-assigned.
    */
    my_own_appname = my_appname;
}

void Syslog::logger(uint8_t priority, uint8_t severity, const char[] tag const char[] message) {
    char syslogmessage[480];
    /*
      now fill the buffer according to RFC 5424
      The format is this:

      SYSLOG-MSG      = HEADER SP STRUCTURED-DATA [SP MSG]

      HEADER          = PRI VERSION SP TIMESTAMP SP HOSTNAME
                        SP APP-NAME SP PROCID SP MSGID
      PRI             = "<" PRIVAL ">"
      PRIVAL          = 1*3DIGIT ; range 0 .. 191
      VERSION         = NONZERO-DIGIT 0*2DIGIT
      HOSTNAME        = NILVALUE / 1*255PRINTUSASCII

      APP-NAME        = NILVALUE / 1*48PRINTUSASCII
      PROCID          = NILVALUE / 1*128PRINTUSASCII
      MSGID           = NILVALUE / 1*32PRINTUSASCII

      TIMESTAMP       = NILVALUE / FULL-DATE "T" FULL-TIME
      FULL-DATE       = DATE-FULLYEAR "-" DATE-MONTH "-" DATE-MDAY
      DATE-FULLYEAR   = 4DIGIT
      DATE-MONTH      = 2DIGIT  ; 01-12
      DATE-MDAY       = 2DIGIT  ; 01-28, 01-29, 01-30, 01-31 based on
                                ; month/year
      FULL-TIME       = PARTIAL-TIME TIME-OFFSET
      PARTIAL-TIME    = TIME-HOUR ":" TIME-MINUTE ":" TIME-SECOND
                        [TIME-SECFRAC]
      TIME-HOUR       = 2DIGIT  ; 00-23
      TIME-MINUTE     = 2DIGIT  ; 00-59
      TIME-SECOND     = 2DIGIT  ; 00-59
      TIME-SECFRAC    = "." 1*6DIGIT
      TIME-OFFSET     = "Z" / TIME-NUMOFFSET
      TIME-NUMOFFSET  = ("+" / "-") TIME-HOUR ":" TIME-MINUTE

      STRUCTURED-DATA = NILVALUE / 1*SD-ELEMENT
      SD-ELEMENT      = "[" SD-ID *(SP SD-PARAM) "]"
      SD-PARAM        = PARAM-NAME "=" %d34 PARAM-VALUE %d34
      SD-ID           = SD-NAME
      PARAM-NAME      = SD-NAME
      PARAM-VALUE     = UTF-8-STRING ; characters '"', '\' and
                                     ; ']' MUST be escaped.
      SD-NAME         = 1*32PRINTUSASCII
                        ; except '=', SP, ']', %d34 (")

      MSG             = MSG-ANY / MSG-UTF8
      MSG-ANY         = *OCTET ; not starting with BOM
      MSG-UTF8        = BOM UTF-8-STRING
      BOM             = %xEF.BB.BF
      OCTET           = %d00-255
      SP              = %d32
      PRINTUSASCII    = %d33-126
      NONZERO-DIGIT   = %d49-57
      DIGIT           = %d48 / NONZERO-DIGIT
      NILVALUE        = "-"
    */

    /* Since we cannot assume to have access to a RealTime Clock on an Arduino board, we follow chapter 6.2.3 of RFC 5424:
      A syslog application MUST use the NILVALUE as TIMESTAMP if the syslog
      application is incapable of obtaining system time.
    */



    Udp.sendPacket( , ip_syslogserver, SYSLOG_DEFAULT_PORT)
}

