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

void Syslog::setserver(uint8_t * server_ip);
    /* Variable: ip_syslogserver */
}

void Syslog::logger(uint8_t priority, uint8_t severity, const char[] message) {

}

