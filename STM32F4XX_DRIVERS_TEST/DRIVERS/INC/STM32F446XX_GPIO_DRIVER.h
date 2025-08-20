

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "STM32F446XX.h"
#include <stdint.h>


typedef struct
{
	/*
	 * Pin Number can hold the value of 0 - 15 that is why 1 BYTE Is Sufficient (8bit)
	 * Same goes for all gpio pins which has the control over mode, number, speed, o/p type.. etc...
	 */
    uint8_t GPIO_PinNumber;         /* Possible values from @GPIO_PIN_NUMBERS                           */
    uint8_t GPIO_PinMode;           /* Possible values from @GPIO_PIN_MODES                             */
    uint8_t GPIO_PinSpeed;          /* Possible values from @GPIO_PIN_SPEED                             */
    uint8_t GPIO_PinPuPdControl;    /* Possible values from @GPIO_PIN_PULL_UP_PULL_DOWN                 */
    uint8_t GPIO_PinOPType;         /* Possible values from @GPIO_PIN_OUTPUT_TYPE                       */
    uint8_t GPIO_PinAltFunMode;     /* Has value only when @GPIO_PIN_MODES is set to Alt functionality  */

}GPIO_PinConfig_t;

/*
 * Handle structure for a GPIO pin
 */
typedef struct
{
    GPIO_RegDef_t *pGPIOx;              /* This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig;    /* This holds GPIO pin configuration settings
                              */
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0       0
#define GPIO_PIN_NO_1       1
#define GPIO_PIN_NO_2       2
#define GPIO_PIN_NO_3       3
#define GPIO_PIN_NO_4       4
#define GPIO_PIN_NO_5       5
#define GPIO_PIN_NO_6       6
#define GPIO_PIN_NO_7       7
#define GPIO_PIN_NO_8       8
#define GPIO_PIN_NO_9       9
#define GPIO_PIN_NO_10      10
#define GPIO_PIN_NO_11      11
#define GPIO_PIN_NO_12      12
#define GPIO_PIN_NO_13      13
#define GPIO_PIN_NO_14      14
#define GPIO_PIN_NO_15      15


/*
 * GPIO Pin Possible Modes
 * @GPIO_PIN_MODES
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define	GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT 	4 // Interrupt Falling edge
#define GPIO_MODE_IT_RT		5 // Interrupt Rising Edge
#define	GPIO_MODE_IT_RFT	6 // Interrupt Rising Falling Edge

/*
 * GPIO Pin Possible Output Types
 * @GPIO_PIN_OUTPUT_TYPE
 */
#define GPIO_OP_TYPE_PP 	0 // Output type Push Pull
#define GPIO_OP_TYPE_OD		1 // Output type Open drain

/*
 * GPIO Pin Possible Output speed */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*
 * GPIO Pin  Pull up and pull down configuration macros
 * @GPIO_PIN_SPEED
 */
#define GPIO_NO_PUPD		0
#define GPIO_PU				1
#define GPIO_PD				2














/***************************************************************************************************************************************
 * 		API Supported By this driver
 * 		For More Information about the API's Check the function definitions
 ****************************************************************************************************************************************
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);
/*
 * By using this function we are going to enable the clock or disable it for a given gpio base address
 * that is why we will use our Gpio_reg_def as a parameter as the first parameter
 * And the second parameter is enable or disable
 */



void GPIO_Init(GPIO_Handle_t *pGPIOHandle); // Gpio Initialization
/*
 *
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);// Gpio DeInitialization
/*
 * Used to De initialize which means sending the registers back to its reset states or reset values
 * There is  a register already available to do this which is in RCC Section
 * So we need not to reset each register manually
 * In one shot we can do that and that is PHERIPHERAL RESET REGISTER RCC_AHB1RSTR
 * REFER SECTION 6.3.5 IN THE REFERENCE MANUAL
 *
 */


uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);



void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi);
// Used to config the IRQ Number of the Gpio Pin Like Enabling it, Priority etc..


void GPIO_IRQHandling(uint8_t PinNumber);
// When ever the interrupt occurs the user can call this function to handle it
































#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
