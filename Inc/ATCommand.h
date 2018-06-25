#ifndef __AT_COMMAND_H
#define __AT_COMMAND_H

int at_command(UART_HandleTypeDef *huart, unsigned char *command);
void clear_buffer();
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
