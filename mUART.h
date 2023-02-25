/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on 04 ??????, 2023, 09:54 ?
 */

#ifndef MUART_H
#define	MUART_H

void init_UART(int Baudrate);
void UART_send(char data);
char UART_receive();
void UART_send_str(char *pData);
#endif	/* MUART_H */

