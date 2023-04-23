#include <avr/io.h>
#include "USART_int.h"

char *USART_TransmitData;
char *USART_ReceivedData;
uint8_t USART_ReceivedDataSize;

void USART_Init(uint32_t Copy_BaudRate, USART_ENUM_CHAR_SIZE Copy_CharSize, USART_ENUM_PARITY Copy_Parity, USART_ENUM_STOP_BITS Copy_StopBits)
{
	// Set UBRR = F_CPU / 16 / BAUD_RATE - 1
	uint16_t Local_UBRR = F_CPU / 16 / Copy_BaudRate - 1;
	UBRRL = (Local_UBRR);
	UBRRH = (Local_UBRR >> 8);

	// Set Parity , Stop Bits, Char Size
	UCSRC = (1 << URSEL) | (Copy_Parity << UPM0) | (Copy_StopBits << USBS) | (Copy_CharSize << UCSZ0);

	// Enable Receiver & Transmitter
	UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void USART_TransmitChar(char Copy_Data)
{
	// Wait For Data Register To Be Empty (Ready For New Data To Be Put Into)
	while ((UCSRA & (1 << UDRE)) == 0)
		;

	// Copy Data Into Buffer
	UDR = Copy_Data;
}