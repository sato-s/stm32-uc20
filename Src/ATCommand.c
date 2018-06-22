#include "main.h"
#include "stm32f4xx_hal.h"

void at_command(UART_HandleTypeDef huart, char *command){
	int len = strlen(command);
	int status = HAL_UART_Transmit_IT(&huart, (uint8_t *)command, len);
	HAL_Delay(200);
	HAL_Delay(200);
	HAL_Delay(200);
}
