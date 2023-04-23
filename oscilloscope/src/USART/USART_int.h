#ifndef USART_INT_H_
#define USART_INT_H_

// ---------------------------------------- Enums ---------------------------------------- //

typedef enum
{
	USART_CHAR_SIZE_5_BIT,
	USART_CHAR_SIZE_6_BIT,
	USART_CHAR_SIZE_7_BIT,
	USART_CHAR_SIZE_8_BIT
} USART_ENUM_CHAR_SIZE;

typedef enum
{
	USART_PARITY_NONE,
	USART_PARITY_EVEN = 2,
	USART_PARITY_ODD
} USART_ENUM_PARITY;

typedef enum
{
	USART_STOP_BITS_ONE,
	USART_STOP_BITS_TWO
} USART_ENUM_STOP_BITS;

// ---------------------------------------- Functions ---------------------------------------- //

void USART_Init(uint32_t Copy_BaudRate, USART_ENUM_CHAR_SIZE Copy_CharSize, USART_ENUM_PARITY Copy_Parity, USART_ENUM_STOP_BITS Copy_StopBits);

void USART_TransmitChar(char Copy_Data);

#endif
