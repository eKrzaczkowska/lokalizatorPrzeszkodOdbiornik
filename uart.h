#ifndef __UART
#define __UART

#define FOSC 8000000UL	//clock speed
#define BAUD 9600
#define MYUBRR ((FOSC/(16UL*BAUD))-1)

void USART_Init(uint32_t ubr);
void USARTWriteChar(char data);
void USART_TransmitString(char *data);

#endif
