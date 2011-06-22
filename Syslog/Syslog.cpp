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

void Syslog::begin(uint8_t * server_ip);
    UDP Udp;
    /* Variable: ip_syslogserver */
    ip_syslogserver = server_ip;
}

void Syslog::logger(uint8_t priority, uint8_t severity, const char[] tag const char[] message) {
    char syslogmessage[255];
    // now fill the buffer according to RFC 3164
    // The format is this:
    // Syslog := TIMESTAMP MDG
    // TIMESTAMP := Mmm dd hh:mm:ss 
    //     where Mmm is one of Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    //     and where single digit dd (day) values must be (blank)number
    //     and where time numbers range from 00 to 24 or 00 to 59
    //  MSG := TAG CONTENT



    Udp.sendPacket( , ip_syslogserver, SYSLOG_DEFAULT_PORT)
}

