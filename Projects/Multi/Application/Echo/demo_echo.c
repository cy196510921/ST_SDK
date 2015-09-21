//#include "sensor_service.h"
#include "bluenrg_sdk_api.h"
/*start adv*/


void User_Process(void)
{
  if(Ble_conn_state){
		ble_device_start_advertising();
    Ble_conn_state = BLE_NOCONNECTABLE;
  }
	
}

/* Device On Message */
void ble_device_on_message(uint8_t type, uint16_t length, uint8_t* value)
{  	
	/*echo data*/
	ble_device_send(type, length, value);
			
}
/* Device on connect */
void ble_device_on_connect(void)
{
	BSP_LED_Toggle(LED0);
}
/* Device on disconnect */
void ble_device_on_disconnect(uint8_t reason)
{
	//BSP_LED_Toggle(LED0);
	/* Make the device connectable again. */
	Ble_conn_state = BLE_CONNECTABLE;
}


