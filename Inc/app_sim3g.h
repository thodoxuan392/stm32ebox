/*
 * app_sim3g.h
 *
 *  Created on: Nov 22, 2019
 *      Author: VAIO
 */


#ifndef APP_SIM3G_H_
#define APP_SIM3G_H_


enum SIM3G_STATE{
	SIM3G_STATUS = 0,
	WAIT_FOR_SIM3G_STATUS_RESPONSE,
	POWER_ON_SIM3G,
	WAIT_FOR_SIM3G_POWER_ON,
	POWER_OFF_SIM3G,
	WAIT_FOR_SIM3G_POWER_OFF,
	DEFINE_PDP_CONTEXT,
	WAIT_FOR_DEFINE_PDP_CONTEXT_RESPONSE,
	SET_AUTHENTICATION_PARAMETER,
	SET_PDP_CONTEXT_NUMBER,
	PDP_CONTEXT_ACTIVATION,
	WAIT_FOR_PDP_CONTEXT_ACTIVATION_RESPONSE,
	PDP_CONTEXT_DEACTIVATION,
	RECEIVE_DATA_LENGTH_OPTION,
	RECEIVE_DATA_ADDRESS_OPTION,
	ADJUST_NUMBER_OF_RETRANSMISSION,
	WAIT_FOR_ADJUST_NUMBER_OF_RETRANSMISSION_RESPONSE,
	ESTABLISH_CONNECTION,
	WAIT_FOR_ESTABLISH_CONNECTION_RESPONSE,
	SEND_DATA,
	WAIT_FOR_SEND_DATA_RESPONSE,
	DISCONNECT_CONNECTION,
	WAIT_FOR_DISCONNECT_CONNECTION_RESPONSE
};

void Sim3g_Init(void);
#endif /* APP_SIM3G_H_ */


