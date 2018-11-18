//#defines

// Charge states
#define MAIN 0
#define EQUALIZATION 1
#define FLOAT 2
#define NA 3
#define COMPLETE 4

// Batt states
#define CHARGE 0
#define DISCHARGE 1
#define FAULT 2

//VAL. BMS STATUS FLAG DEFINITIONS
#define NORMAL    0x00
#define WARNING   0x01
#define ALARM     0x02
#define SHUTDOWN  0x03
#define UNDEFINED_STAT 0x04

//HEATER HYSTERESIS DEFINITIONS
#define CHARGE_MIN_TEMP (0)     //0 DEG C
#define CHARGE_MIN_TEMP_OFF (1) //1 DEG C
#define DISCHARGE_MIN_TEMP (-20) //-20 DEG C
#define MODULE_HIGH_TEMP_CHRG_CUTBACK_ON (52) // 50 DEG C
#define MODULE_HIGH_TEMP_CHRG_CUTBACK_OFF (48) // 48 DEG C
#define MODULE_MAX_TEMP (60)   //60 deg C
#define CHRGR_PWR_HEATER_ON_CELL_TEMP (2)  //0 DEG C
#define CHRGR_PWR_HEATER_OFF_CELL_TEMP (3)  //+5 DEG C
#define CHRGR_OFF_HEATER_ON_CELL_TEMP (-18)
#define CHRGR_OFF_HEATER_OFF_CELL_TEMP (-16)
#define BATT_SOC_HEATER_MIN_THRESH (50)  //50 DEG C
#define HEATER_ON_SURFACE_TEMP (680)  //+64 DEG C
#define HEATER_OFF_SURFACE_TEMP (685)  //+65 DEG C
#define HEATER_OFF_CRIT_TEMP (800) //*70 DEG C

//CELL VOLTAGE LEVELS
#define CELL_MAX_VOLTS_L (3450)  //3.7 VOLTS
#define CELL_MAX_VOLTS_H (3550)


//CAN RELATED DEFINES
#define CUMMINS_BAUD (125000)
#define VALENCE_BAUD (250000)

//BATTERY TYPE defines
#define UNKNOWN_BATT (0)
#define VALENCE_REV3 (1)
#define CUMMINS_REV1 (2)
#define SD_CONF (3)

//TEST TYPE defines
#define CYCLE (1)
#define VEHICLE_LOG (2)
#define HOT (3)
#define COLD (4)

//DISCHARGER TYPE defines
#define SD_REPLAY (1)
#define LIST (2)

#define CAN_LOST_TIME 5 //seconds after which CANbus is consdidered lost
