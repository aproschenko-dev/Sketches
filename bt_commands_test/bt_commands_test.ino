#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 4

// set up a new serial port
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()
{
  Serial.begin(9600);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  mySerial.begin(9600);
}

void loop()
{
  String command = "";
  while (mySerial.available() > 0)
  {
    char c = mySerial.read();
    Serial.println(c);
    command.concat(c);
  }
  
  command.trim();
  if (command == "")
    return;

  Serial.println("command is -> " + command);

  char charBuf[command.length() + 1];
  command.toCharArray(charBuf, command.length() + 1);
  mySerial.write(charBuf);
}
