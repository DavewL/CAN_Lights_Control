#include <carloop.h>
#include "CANtx.h"
#include "Globals.h"

extern Carloop<CarloopRevision2> carloop;

void sendStatusCAN(void){
  int millisNow2 = millis();
  static int millisPrev2 = 0;
  int millisDelta2 = millisNow2-millisPrev2;
  millisPrev2 = millisNow2;
  CANMessage message;
  message.id = CNTRLR_STATUS_ID;
  message.len = 6;
  message.data[5] = (byte)0;
  message.data[4] = (byte)0;
  message.data[3] = (byte)0;
  message.data[2] = (byte)0;
  message.data[1] = (byte)0;
  message.data[0] = (byte)0;
  carloop.can().transmit(message);

}
