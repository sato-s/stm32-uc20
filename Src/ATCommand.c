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

int clear_buffer(){
  UserTxBufPtrIn=0;
  for( int i = 0; i < sizeof(UserTxBuffer);  ++i ){
       UserTxBuffer[i] = (char)0;
  }
}

int at_command(UART_HandleTypeDef *huart, unsigned char *command){
    clear_buffer();
    unsigned char *cmd = "ATI\r\n";
    uint32_t len = strlen(cmd);

    int status = HAL_UART_Transmit_IT(huart, (uint8_t *)command , strlen(command));
	return status;
}
