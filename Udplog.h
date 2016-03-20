/*
Udplog.h - - Library for logging over a UDP network connection
Created by Reno de Jong, march 2016

Example PHP listener:
<?php
$port = 1337;
$ip = "0.0.0.0" // IP to listen to. Use 0.0.0.0 for all
$log_target = "/tmp/udp.log";
// use tail -f /tmp/udp.log (in linux) to show the log realtime from anywhere
//Create a UDP socket
if(!($sock = socket_create(AF_INET, SOCK_DGRAM, 0)))
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
    die("Couldn't create socket: [$errorcode] $errormsg \n");
}

echo "Socket created \n";
// Bind the source address
if( !socket_bind($sock, $ip , $port) )
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
    die("Could not bind socket : [$errorcode] $errormsg \n");
}
?>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Udplog_h
#define Udplog_h
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

class UdpLog
{
public:
  UdpLog(const char *serverIP, int localPort);
  void log(String message);
  int localPort;
private:
  const char *_serverIP;
  int _localPort;
  WiFiUDP _udp;
};

#endif//Udplog_h
