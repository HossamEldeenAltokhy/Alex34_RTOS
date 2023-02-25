#include <xc.h>

#include "mUART.h"
#define F_CPU 16000000UL

void init_UART(int Baudrate){
    // Enable RX & TX >> UCSRB
    
    UCSRB |= (1<<RXEN)|(1<<TXEN);
    
//    UBRRL = 103;
    UBRRL = (F_CPU/16.0/Baudrate)-1;
}

void UART_send(char data){
    // Check UDRE flag >> UCSRA
    while(!(UCSRA & (1<<UDRE)));
    UDR = data;
}

void UART_send_str(char *pData){
    for(int counter = 0; pData[counter]!= '\0';counter++){
        UART_send(pData[counter]);
    }
}

char UART_receive(){
    // Check RXC flag >> UCSRA
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}