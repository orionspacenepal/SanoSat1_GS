/**
 * @file qsl_msg.ino
 * @brief Morse code transmitter
 * @author Rishav, ORION Space
 * @date 2022/09/05
 */
 
#include "mini_morse.h"

const String msg = "Thank you!";
const uint16_t msg_delay = 5000; // millis
const uint8_t led_pin = 13;

void setup()
{
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
    
  if (!minimorse_init())
  {
    Serial.println("Radio error!");
    for (uint8_t i = 0; i < 5; i++)
    {
      digitalWrite(led_pin, HIGH);
      delay(1000);
      digitalWrite(led_pin, LOW);
      delay(1000);
    }
    digitalWrite(led_pin, HIGH);
      
    while (1)
    {
    }
  }
  else
  {
    Serial.println("\nMorse radio is ready!\n");
  }
}

void loop()
{
  digitalWrite(led_pin, HIGH);
  minimorse_transmit_msg(msg);
  Serial.println();
  digitalWrite(led_pin, LOW);
  delay(msg_delay);
}
