#include <avr/io.h>
#include "USART/USART_int.h"
#include "ADC/ADC_int.h"

int main(int argc, char const *argv[])
{
  USART_Init(9600, USART_CHAR_SIZE_8_BIT, USART_PARITY_NONE, USART_STOP_BITS_ONE);

  // Initializing ADC
  ADC_Init(ADC_EXTERNAL_AVCC, ADC_PRESCALER_128);
  ADC_SelectChannel(ADC_CHANNEL_0);
  ADC_EnableAutoTrigger();

  uint8_t ADC_Value;
  while (1)
  {
    ADC_Value = (uint8_t)(ADC_ReadDigitalValue() >> 2);
    USART_TransmitChar(ADC_Value);
  }

  return 0;
}