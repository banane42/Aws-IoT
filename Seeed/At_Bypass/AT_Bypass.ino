#include <UART_Interface.h>
#include <ublox_sara_r4.h>

Ublox_sara_r4 ublox = Ublox_sara_r4();

void setup() {
  Log_info("Begin...");
  ublox.powerOn();
  while (false == ublox.isAlive()) {
    Log_info("Waiting for module to alive...");
    delay(1000);
  }
  Log_info("Power On O.K!");

  if (!ublox.initialAtCommands())
  {
    Log_error("Failed to initialzie module.");
  }

  Log_info("Start AT commands loop");

}

void loop() {

  while(SerialGSM.available()){

    //byte yeet = SerialGSM.read();
    SerialDebug.write(SerialGSM.read());
    
  }

  while(SerialDebug.available()){

    //byte yeet = SerialDebug.read();
    //SerialDebug.write(SerialDebug.read());
    SerialGSM.write(SerialDebug.read());
    
  }
  //AT_bypass();
}
