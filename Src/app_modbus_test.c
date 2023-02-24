/*
 * app_modbus_test.c
 *
 *  Created on: Feb 23, 2023
 *      Author: xuanthodo
 */

#include "app_modbus_test.h"
#include "modbus.h"
#include "utils/utils_logger.h"

enum {
	MODBUS_SEND_REQUEST,
	MODBUS_WAIT_FOR_GET_RESPONSE
};


static const uint16_t modbus_request_interval = 1000; //1000 ms
static const uint16_t modbus_app_timeout = 5000; //1000 ms
static const MODBUS_t read_holding_req = {
		.address = 10,
		.function_code = MODBUS_READ_INPUT_REGISTER,
		.data = {
			.read_req = {
				.addr = 0x0000,	// Register address
				.quantity = 2	// read 2 bytes
			}
		},
};

static MODBUS_t response;


static uint8_t modbus_state = MODBUS_SEND_REQUEST;

void modbus_test_run(){
	static uint32_t start_tx_time = 0;
	switch (modbus_state) {
		case MODBUS_SEND_REQUEST:
			if(HAL_GetTick() - start_tx_time < modbus_request_interval){
				break;
			}
			utils_log_info("MODBUS send request\r\n");
			start_tx_time = HAL_GetTick();
			MODBUS_transmit(&read_holding_req);
			modbus_state = MODBUS_WAIT_FOR_GET_RESPONSE;
			break;
		case MODBUS_WAIT_FOR_GET_RESPONSE:
			if(MODBUS_receive(&response)){
				utils_log_info("MODBUS_received:\r\n");
				utils_log_info("Addr: %d\r\n", response.address);
				utils_log_info("Function code: %x\r\n", response.function_code);
				utils_log_info("Byte Cnt: %x\r\n", response.data.read_res.byte_cnt);
				utils_log_info("Data: [");
				for (size_t i = 0; i < response.data.read_res.byte_cnt; i++)
				{
					utils_log_raw("%2x", response.data.read_res.data[i]);
				}
				utils_log_raw("]\r\n");
				modbus_state = MODBUS_SEND_REQUEST;
			}

			if (HAL_GetTick() - start_tx_time > modbus_app_timeout){
				utils_log_info("Modbus timeout for receive\r\n");
				modbus_state = MODBUS_SEND_REQUEST;
			}
			break;
		default:
			break;
	}
}

