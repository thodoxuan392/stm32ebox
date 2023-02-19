/*
 * app_modbus_test.c
 *
 *  Created on: Feb 19, 2023
 *      Author: xuanthodo
 */

#include "main.h"
#include "modbus.h"
#include "utils_logger.h"

#define MODBUS_TIMEOUT 100 //100 MS
#define MODBUS_POLL_INTERVAL 1000 //1000 MS

// Internal functions
static void modbus_log_message(MODBUS_t* message);


enum {
	MODBUS_SEND_REQUEST = 0,
	MODBUS_WAIT_FOR_RECEIVE
};

static uint8_t modbus_task_state = MODBUS_SEND_REQUEST;

void modbus_run(){
	static uint32_t tx_time = 0;
	static uint32_t rx_time = 0;
	static MODBUS_t rx_message;
	switch (modbus_task_state) {
		case MODBUS_SEND_REQUEST:
			// Check time interval
			if(HAL_GetTick() - rx_time < MODBUS_POLL_INTERVAL){
				break;
			}
			MODBUS_t tx_message = {
				.address = 0x05,		// Modbus Slave Address
				.function_code = MODBUS_READ_INPUT_REGISTER,
				.data = {
					.read_req = {
						.addr = 0x0000,		// Register Address is 0x00
						.quantity = 10		// Read 10 Register
					}
				}
			};
			MODBUS_transmit(&tx_message);
			// Start transmission 
			tx_time = HAL_GetTick();
			modbus_task_state = MODBUS_WAIT_FOR_RECEIVE;
			break;
		case MODBUS_WAIT_FOR_RECEIVE:
			// Check timeout
			if(HAL_GetTick() - tx_time >= MODBUS_TIMEOUT){
				utils_log_error("MODBUS timeout for receive\r\n");
				modbus_task_state = MODBUS_SEND_REQUEST;
				rx_time  = HAL_GetTick();
				break;
			}
			if(MODBUS_receive(&rx_message)){
				utils_log_info("MODBUS receive message\r\n");
				modbus_log_message(&rx_message);
				modbus_task_state = MODBUS_SEND_REQUEST;
				rx_time  = HAL_GetTick();
				break;
			}
			break;
		default:
			break;
	}
}

// Internal function
static void modbus_log_message(MODBUS_t* message){
	utils_log_info("Slave Address: %x\r\n", message->address);
	utils_log_info("Function Code: %x\r\n", message->function_code);
	utils_log_info("Data Raw:\r\n[");
	uint16_t data_len = sizeof(message->data);
	uint8_t* data_p = (uint8_t*)&message->data;
	for(int i=0; i< data_len; i++){
		utils_log_info("%x", data_p[i]);
	}
	utils_log_info("]\r\n");
}
