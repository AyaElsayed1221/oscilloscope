#ifndef ADC_INT_H_
#define ADC_INT_H_

// ---------------------------------------- Enums ---------------------------------------- //

typedef enum
{
	ADC_EXTERNAL_AREF,
	ADC_EXTERNAL_AVCC,
	ADC_INTERNAL_AREF
} ADC_ENUM_VOLTAGE_SOURCE;

typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
} ADC_ENUM_CHANNELS;

typedef enum
{
	ADC_PRESCALER_2,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
} ADC_ENUM_PRESCALERS;

// ---------------------------------------- Functions ---------------------------------------- //

void ADC_Init(ADC_ENUM_VOLTAGE_SOURCE Copy_VoltageSource, ADC_ENUM_PRESCALERS Copy_Prescaler);

void ADC_EnableAutoTrigger();

void ADC_DisableAutoTrigger();

void ADC_SelectChannel(ADC_ENUM_CHANNELS Copy_Channel);

uint8_t ADC_ReadDigitalValue();

#endif
