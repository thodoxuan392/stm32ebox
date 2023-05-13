#ifndef APP_MODBUS_TEST_H
#define APP_MODBUS_TEST_H

#include "stdint.h"
#include "stdbool.h"

typedef struct {
	float voltage;
	float current;
	float active_power;
	float power_factor;
	float frequency;
	float total_active_power;
}POWER_t;

void POWERMETER485_fsm();
POWER_t* POWERMETER485_get_lastest();
#endif // __APP_MODBUS_TEST_H__