#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>

RF24 radio(22,0);
const uint64_t pipeA = 0xF0F0F0F0E1LL;
const uint64_t pipeB = 0xF0F0F0F0D2LL; // Setting pipes

int main(int argc, char** argv) {
  uint32_t debut;
  bool timeout;
  uint16_t received;

  radio.begin();
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(pipeB);
  radio.openReadingPipe(1,pipeA);
  radio.printDetails();
  radio.startListening();
  
while(1) {

  radio.startListening();
  debut=millis();
  timeout = false;

  while(!radio.available()){ //Wait for incoming data
    if(millis()-debut > 800) { 
      timeout=true;
      break;
    }
  }

  if(timeout) {
    printf("Erreur: timeout \n"); //Took too much time and did not receive something
  } else {
    radio.read(&data, sizeof(data));
    printf("reponse: %zu\n",received); // Print received data
  }
  sleep(1); // Give it time
 }
return(0);
}
