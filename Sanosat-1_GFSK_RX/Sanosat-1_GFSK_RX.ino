
#include <SPI.h>
#include <Wire.h>
#include <RH_RF24.h>

// Singleton instance of the radio driver
RH_RF24 rf24(10,2,9);

struct RFM_PACKET {
   uint8_t CALL_SIGN[7];
   int PACKET_TYPE;
   int TEMP_COM;
   int V_BAT;
   int I_CHARGE;
   int TEMP_BAT;
   int RADIATION;
   int NO_RESETS;
   boolean DEPLOYMENT_STATUS;
    };



void setup() {
  Serial.begin(9600);

  if (!rf24.init())
    Serial.println("init failed");

    rf24.setFrequency(436.235);
    //uint8_t GPIO_MODES[]={ 0x84, 0x08, 0x0C, 0x54, 0xA7, 0x0B, 0x00 };  //GPIO3 as Received Data
   // rf24.command(0x13, GPIO_MODES , sizeof(GPIO_MODES) );
    rf24.setCRCPolynomial(RH_RF24::CRC_CCITT);
    rf24.setModemConfig(RH_RF24::GFSK_Rb0_5Fd1);
    Serial.print("Testing:");
}

void loop() {
  struct RFM_PACKET *GFSK_PACKET;
  uint8_t buf[RH_RF24_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
    if(rf24.recv(buf,&len))
    {
      GFSK_PACKET = (struct RFM_PACKET *)buf;
      Serial.print("RSSI:");
      Serial.print((uint8_t)rf24.lastRssi(),DEC);
      Serial.print("Packet Type:");
      Serial.print(GFSK_PACKET->PACKET_TYPE);
      Serial.print(",TCOM: ");
      Serial.print(GFSK_PACKET->TEMP_COM);
      Serial.print(",VBat:");
      Serial.print(GFSK_PACKET->V_BAT);

      Serial.print(",Ichg: ");
      Serial.print(GFSK_PACKET->I_CHARGE);
      Serial.print(",TBAT:");
      Serial.print(GFSK_PACKET->TEMP_BAT);
      Serial.print(",RAD: ");
      Serial.print(GFSK_PACKET->RADIATION);
      Serial.print(",NOR:");
      Serial.print(GFSK_PACKET->NO_RESETS);
      Serial.print(",DEP:");
      Serial.println(GFSK_PACKET->DEPLOYMENT_STATUS);
    }
  
}
