#include <SPI.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const uint64_t pipeA = 0xF0F0F0F0E1LL;
const uint64_t pipeB = 0xF0F0F0F0D2LL;

int data_to_send = 1;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  radio.setPALevel(RF24_PA_LOW); // Set PALevel to LOW for better range
  radio.openWritingPipe(pipeA);
  radio.openReadingPipe(1, pipeB); // Configure pipes
  radio.stopListening();
}

void loop() {
    radio.write(&data, sizeof(data)); // Send the data
    delay(1000); // Give it time 
}
