#include "main.h"
#include "stm32f4xx_hal.h"

/**
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Increment Index for buffer writing */
  UserTxBufPtrIn++;

  /* To avoid buffer overflow */
  if(UserTxBufPtrIn == APP_RX_DATA_SIZE)
  {
    UserTxBufPtrIn = 0;
  }

  /* Start another reception: provide the buffer pointer with offset and the buffer size */
  HAL_UART_Receive_IT(huart, (uint8_t *)(UserTxBuffer + UserTxBufPtrIn), 1);
}


void at_command(UART_HandleTypeDef *huart, char *command){
    unsigned char *cmd = "ATI\r\n";
    uint32_t len = strlen(cmd);
    HAL_UART_Transmit_IT(&huart, (uint8_t *)cmd , len);
	return;
}
