/**
 * @file qsl_msg.ino
 * @brief Morse code transmitter
 * @author Rishav, ORION Space
 * @date 2022/09/05
 */

#include "mini_morse.h"

const String msg = "Thank you!";
const uint16_t msg_delay = 5000; // millis

void setup()
{
  Serial.begin(115200);
  
  if (!minimorse_init())
  {
    Serial.println("RFM error!");
    while (1)
    {
    }
  }
  else
  {
    Serial.println("\nRFM success!\n");
  }  
}

void loop()
{
  minimorse_transmit_msg(msg);
  Serial.println();
  delay(msg_delay);
}
