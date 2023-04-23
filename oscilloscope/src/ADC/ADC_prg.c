#include <avr/io.h>
#include "ADC_int.h"
#include "UTILS/UTILS_int.h"

uint8_t ADC_VoltageSourceValue = 5;

void ADC_Init(ADC_ENUM_VOLTAGE_SOURCE Copy_VoltageSource, ADC_ENUM_PRESCALERS Copy_Prescaler)
{
	// Select ADC Voltage Source
	switch (Copy_VoltageSource)
	{
	case ADC_EXTERNAL_AVCC:
		SET_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;

	case ADC_INTERNAL_AREF:
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
		break;

	default:
		CLR_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;
	}

	// Set ADC Prescaler
	switch (Copy_Prescaler)
	{
	case ADC_PRESCALER_2:
		ASSIGN_REG(ADCSRA, 1);
		break;

	case ADC_PRESCALER_4:
		ASSIGN_REG(ADCSRA, 2);
		break;

	case ADC_PRESCALER_8:
		ASSIGN_REG(ADCSRA, 3);
		break;

	case ADC_PRESCALER_16:
		ASSIGN_REG(ADCSRA, 4);
		break;

	case ADC_PRESCALER_32:
		ASSIGN_REG(ADCSRA, 5);
		break;

	case ADC_PRESCALER_64:
		ASSIGN_REG(ADCSRA, 6);
		break;

	case ADC_PRESCALER_128:
		ASSIGN_REG(ADCSRA, 7);
		break;

	default:
		ASSIGN_REG(ADCSRA, 0);
		break;
	}

	// Enable Interrupt Requests
	SET_BIT(ADCSRA, ADIE);

	// Enable ADC
	SET_BIT(ADCSRA, ADEN);
}

void ADC_EnableAutoTrigger()
{
	SET_BIT(ADCSRA, ADATE);
}

void ADC_DisableAutoTrigger()
{
	CLR_BIT(ADCSRA, ADATE);
}

void ADC_SelectChannel(ADC_ENUM_CHANNELS Copy_Channel)
{
	ADMUX &= 0xE0;
	ADMUX |= Copy_Channel;
}

uint8_t ADC_ReadDigitalValue()
{
	// ADC Start Single Conversion
	SET_BIT(ADCSRA, ADSC);

	// Loop While:
	//   1) ADC Start Conversion Bit Is High
	//   2) Timeout > 0
	uint16_t Local_Timeout = 0xFFFF;
	while (GET_BIT(ADCSRA, ADSC) && Local_Timeout--)
		;

	return (ADC >> 2);
}
