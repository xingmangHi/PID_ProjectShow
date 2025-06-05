#include "hw_key.h"



KEY_STATUS key_scan(void)
{
   KEY_STATUS status;
	
	status.up = DL_GPIO_readPins(KEY_PORT,KEY_KEY_UP_PIN) ? 1 : 0;
	status.down = DL_GPIO_readPins(KEY_PORT,KEY_KEY_DOWN_PIN) ? 1 : 0;
	status.left = DL_GPIO_readPins(KEY_PORT,KEY_KEY_LEFT_PIN) ? 1 : 0;
	status.right = DL_GPIO_readPins(KEY_PORT,KEY_KEY_RIGHT_PIN) ? 1 : 0;	
	
	return status;
}