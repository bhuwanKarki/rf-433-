#include <VirtualWire.h>// import the Virtual Wire library
#include <AFMotor.h> // import the Adafruit Motor Shield library
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
void setup()
{
Serial.begin(9600); // begin serial communication @ 9600 baud
pinMode(13, OUTPUT);
vw_setup(2000); // set up the receiver @ 2000 bits per second
vw_set_rx_pin(11); // set up the receiver on digital pin 
vw_rx_start(); // Tell the D2 to listen for signals from the transmitter
motor1.setSpeed(105); // You can choose any speed from 0 to 255
motor2.setSpeed(105); // Set the speed of motor2 to 125
}
void loop()
{
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
if (vw_get_message(message, &messageLength)) // if the receiver gets a message
{
for (int i = 0; i < messageLength; i++)
{
Serial.write(message[i]); // print in the received message in the serial monitor
if (message[i] == 'w'){ // if message received is 'w', make the motors move forward
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
if (message[i] == 'x'){ // if message received is 'x', make the motors stop
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
if(message[i] == 'a'){ // if message received is 'a', make the motors move left
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
if(message[i] == 's') { // if the message received is 's' , make the motors move backwards 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
if (message[i] == 'd') { //if the message received is 'd', make the motors move right
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

}
Serial.println();
}
} 




