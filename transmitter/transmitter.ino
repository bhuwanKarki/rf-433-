
#include <VirtualWire.h> // include the VirtualWire library

// pin 2 for X and 3 for Y 
#define Xpin A2 // x 
#define Ypin A3 // y
int X = 0; 
int Y = 0; 


void setup() {
  
  vw_setup(2000);
  vw_set_tx_pin(10);
  Serial.begin(9600); 
}

void loop() {
  
  X = analogRead(Xpin); 
  Y = analogRead(Ypin);
  
  X = map(X, 0, 1023, 0, 10); 
  Y = map(Y, 0, 1023, 0, 10); 
  if (X == 3 && Y == 3) { 
    char *msg = "x"; 
   
    vw_send((uint8_t *)msg, strlen(msg)); 
    Serial.println("STOPPED"); 
  }
  if (X == 3 && Y >= 3) { 
    char *msg = "w"; 
    vw_send((uint8_t *)msg, strlen(msg)); 
    Serial.println("GOING FORWARD");

  }
  if (X <= 3 && Y == 3) { 
    char *msg = "a"; 
    vw_send((uint8_t *)msg, strlen(msg)); 
    vw_wait_tx(); 
    Serial.println("GOING LEFT"); 

  }
  if (X == 3 && Y <= 3) { 
    char *msg = "s";
    vw_send((uint8_t *)msg, strlen(msg));
    digitalWrite(13, false); 
    Serial.println("GOING BACKWARD"); 
  }
  if ( X >= 3 && Y == 3) { 
    char *msg = "d"; 
    vw_send((uint8_t *)msg, strlen(msg)); 
    vw_wait_tx(); 
    Serial.println("GOING RIGHT"); 
  }

}
