/*
 * Before configuring any pheripheral we have to enable the clock of that particular pheripheral
 * To do that first we have to identify the in which bus the respective pheripheral is connected
 * So ADC Is connected to APB2 so we have to set the respective bit of the RCC APB 2 Enable Reg bus
 *
 */
#include <stdint.h>

#define RCC_APB2ENR_BASE_ADDR		0x40023800UL

#define RCC_APB2ENR_OFFSET			0x44UL

#define RCC_APB2ENR_ADDR 			(RCC_APB2ENR_BASE_ADDR + RCC_APB2ENR_OFFSET)

#define ADC_BASE_ADDR 				0x40012000UL

#define ADC_CR1_REG_OFFSET			0x04UL

#define ADC_CR1_REG_ADDR			(ADC_BASE_ADDR+ ADC_CR1_REG_OFFSET)

int main(void)
{
    /* Loop forever */
	// UL stands for Unsigned long int takes 4 bytes/32bits

	uint32_t *pADC_CR1_REG = (uint32_t*) ADC_CR1_REG_ADDR; // ADC_CR1_REG

	uint32_t *pRCC_APB2ENR_ADDR = (uint32_t*) RCC_APB2ENR_ADDR;

	// 1. Enable the clock of the ADC1 REG using RCC_APB2 Enable reg
	*pRCC_APB2ENR_ADDR |= (1 << 8);

	// 2. Make the 8th bit high In the ADC CR1 Reg
	*pADC_CR1_REG |= (1 << 8);

	for(;;);
}
