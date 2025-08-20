#include "STM32F446XX_GPIO_DRIVER.h"

/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi){
	if(EnOrDi == ENABLE)
	    {
	        if(pGPIOx == GPIOA)
	        {
	            GPIOA_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOB)
	        {
	            GPIOB_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOC)
	        {
	            GPIOC_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOD)
	        {
	            GPIOD_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOE)
	        {
	            GPIOE_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOF)
	        {
	            GPIOF_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOG)
	        {
	            GPIOG_PCLK_EN();
	        }
	        else if(pGPIOx == GPIOH)
	        {
	            GPIOH_PCLK_EN();
	        }
	    }
	    else
	    {
	        if(pGPIOx == GPIOA)
	        {
	            GPIOA_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOB)
	        {
	            GPIOB_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOC)
	        {
	            GPIOC_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOD)
	        {
	            GPIOD_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOE)
	        {
	            GPIOE_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOF)
	        {
	            GPIOF_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOG)
	        {
	            GPIOG_PCLK_DI();
	        }
	        else if(pGPIOx == GPIOH)
	        {
	            GPIOH_PCLK_DI();
	        }
	    }
}

void GPIO_PeriClockEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi){

	if(EnOrDi == ENABLE){

		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}

	}else{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}

	}//Else End

}// API ENDS HERE

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t temp=0;

	//1.Configure the mode of the GPIO Pin

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		// The above condition is for Modes other that  Interrupts because that gonna require some other configuration
		// The non interrupt mode
		temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber) );
																// Multiplying 2 with the pin number because of the 2 bit fields in the moder register
		// For Example if the pin number is 1
		// it will be multiplied by 2 and results in = 2
		// So the pin Mode value will be left shifted 2 times. like that...

		// Storing the temp value in the actual register
		//Before storing the value make sure the register is cleared
		pGPIOHandle->pGPIOx->MODER &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode); // Clearing
		pGPIOHandle->pGPIOx ->MODER |= temp;// Setting
	}
	else{
		// This part will code later. Interrupt mode
	}

	temp = 0;

	//2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode); // Clearing
	pGPIOHandle->pGPIOx->OSPEEDER |= temp;

	temp= 0;

	//3. Configure the pupd settings
	temp= (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode); // Clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp=0;

	//4. Congigure the output type
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (1 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= (0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode); // Clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp =0;

	//5. Configure the Alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
		// CONFIGURE THE ALF FUNCTION REGISTER

		// The AFR is divided into lower and higher register
		// Necessary Mathematics has to be done to deliver the values to the appropriate register and bit position

		uint8_t temp1,temp2;

		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8 ;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8 ;

		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4* temp2)); // Clearing

		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ));

	}


}// Function ENds

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}

}// FUNCTION ENDS HERE

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t value ;
	value = (uint8_t) ((pGPIOx->IDR >> PinNumber) & 0x00000001); // Some trick is done here to obtain the input pin data
	return value;
}//FUNCTION ENDS HERE

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx ){
	uint16_t value ;
	value = (uint16_t) pGPIOx->IDR;// Some trick is done here to obtain the input pin data
	return value;
}//FUNCTION ENDS HERE


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

	if(Value == GPIO_PIN_SET){
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= (1 << PinNumber);

	}else{
		//write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}

}//FUNCTION ENDS HERE

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){

	pGPIOx->ODR = Value;

}//Function ENds here

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	pGPIOx->ODR ^= (1 << PinNumber);
}// FUNCTION ends here

























