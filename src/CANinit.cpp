#include "CANinit.h"
#include "defines.h"
#include "Globals.h"

#include <carloop.h>

Carloop<CarloopRevision2> carloop;

//-----------------INITIALIZE CANBUS---------------------------------------
void initCAN(void){
  //setup CANbus interface
  carloop.begin(CARLOOP_CAN);
  carloop.setCANSpeed(250000);        //must set can speed before enabling bus!
  carloop.enableCAN();                        //enable canbus
}
