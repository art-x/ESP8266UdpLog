# ESP8266UdpLog
Logs messages over a network using the UDP protocol

Example Usage:

...
#include <UdpLog.h>

unsigned int localPort = 1337;      // local port to listen for UDP packets
const char* logServerIP = "1.2.3.4";
UdpLog udplog(logServerIP, localPort);

void setup() {
}

void loop() {
  udplog.log("Hello from this ESP8266.");
  delay(2000);
}



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
