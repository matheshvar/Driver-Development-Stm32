

/* This is the mcu Specific Header file */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdio.h>
#include <stdint.h>

#define __vo volatile

/*
 * Some Generic Macros
 */
/*************************************************************************************************************************************/
#define ENABLE				1
#define DISABLE				0
#define SET 				ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET





/*****************************************************************************************************************************************/
/*=================================================================================================================================*/

/* BASE ADDRESSES OF FLASH AND SRAM MEMORIES */

#define FLASH_BASE_ADDR		0x08000000U		/*BASE ADDRESS OF THE FLASH*/
#define SRAM1_BASE_ADDR		0x20000000U		/*BASE ADDRESS OF THE SRAM1*/
#define SRAM2_BASE_ADDR		0x2001C000U
#define ROM_BASE_ADDR		0x1FFF0000U   // SYS_MEM_BASE_ADDR
#define SRAM 				SRAM1_BASE_ADDR

/* BASE ADDRESSES OF AHBx and APBx PERIPHERALS */

#define PERIPH_BASE_ADDR		0x40000000U
#define APB1_PERI_BASE_ADDR		PERIPH_BASE_ADDR
#define APB2_PERI_BASE_ADDR		0x40010000U
#define AHB1_PERI_BASE_ADDR		0x40020000U
#define AHB2_PERI_BASE_ADDR		0x50000000U
#define AHB3_PERI_BASE_ADDR		0x60000000U

/*PERIPHERAL BASE ADDRESS CONNECTED TO THE AHB1 BUS */

#define GPIOA_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR 		(AHB1_PERI_BASE_ADDR + 0x1C00)
#define RCC_BASE_ADDR			(AHB1_PERI_BASE_ADDR + 0x3800)
//#define CRC_BASE_ADDR			(AHB1_PERI_BASE_ADDR + 0x3000)
//#define FRI_BASE_ADDR			(AHB1_PERI_BASE_ADDR + 0x3C00)
//#define BKPSRAM_BASE_ADDR		(AHB1_PERI_BASE_ADDR + 0x4000)
//#define	DMA1_BASE_ADDR		(AHB1_PERI_BASE_ADDR + 0x6000)
//#define	DMA2_BASE_ADDR		(AHB1_PERI_BASE_ADDR + 0x6400)
//#define USB_OTG_HS_BASE_ADDR	(AHB1_PERI_BASE_ADDR + 0x1C00)

/*PERIPHERAL BASE ADDRESS CONNECTED TO THE APB1 BUS */

#define	I2C1_BASE_ADDR			(APB1_PERI_BASE_ADDR + 0x5400)
#define	I2C2_BASE_ADDR			(APB1_PERI_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR			(APB1_PERI_BASE_ADDR + 0x5C00)


#define	USART2_BASE_ADDR        (APB1_PERI_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR        (APB1_PERI_BASE_ADDR + 0x4800)

#define UART4_BASE_ADDR         (APB1_PERI_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR         (APB1_PERI_BASE_ADDR + 0x5000)

#define SPI2_BASE_ADDR		    (APB1_PERI_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR		    (APB1_PERI_BASE_ADDR + 0xC800)


/* PERIPHERAL BASE ADDRESS CONNECETD TO APB2 BUS*/
#define SPI1_BASE_ADDR			(APB2_PERI_BASE_ADDR + 0x3000)
#define SPI4_BASE_ADDR			(APB1_PERI_BASE_ADDR + 0x3400)

#define USART1_BASE_ADDR     	(APB2_PERI_BASE_ADDR + 0x1000)
#define USART6_BASE_ADDR     	(APB2_PERI_BASE_ADDR + 0x1400)

#define SYSCFG_BASE_ADDR     	(APB2_PERI_BASE_ADDR + 0x3800)

#define EXTI_BASE_ADDR      	(APB2_PERI_BASE_ADDR + 0x3C00)


/*
 * *********************************************************************************************
 *			Peripheral register definition structures
 **********************************************************************************************
 *  		Peripheral register definition structure for GPIO
 */

typedef struct{
	/*     __vo stands for volatile keyword which is defined in the macro of this header file*/

	__vo uint32_t MODER;			/* GPIO port mode register,			*/
	__vo uint32_t OTYPER;		/* GPIO port output type register,	*/
	__vo uint32_t OSPEEDER;		/* GPIO port output speed register,	*/
	__vo uint32_t PUPDR;			/* GPIO port pull-up/down register, */
	__vo uint32_t IDR;			/* GPIO port input data register,   */
	__vo uint32_t ODR;			/* GPIO port output data register,	*/
	__vo uint32_t BSRR;			/* GPIO port bit set/reset register,*/
	__vo uint32_t LCKR;			/* GPIO port configuration lock register,*/
	__vo uint32_t AFR[2]; 		/* AFR[0]: GPIO alternate function low register,*/
							/* Address offset: 0x20 AFR[1]: GPIO alternate function high register,*/
}GPIO_RegDef_t ;


/* Peripheral definition of rcc registers */

typedef struct
{
    __vo uint32_t CR;           /* RCC clock control register,                                  Address offset: 0x00    */
    __vo uint32_t PLLCFGR;      /* RCC PLL configuration register,                              Address offset: 0x04    */
    __vo uint32_t CFGR;         /* RCC clock configuration register,                            Address offset: 0x08    */
    __vo uint32_t CIR;          /* RCC clock interrupt register,                                Address offset: 0x0C    */
    __vo uint32_t AHB1RSTR;     /* RCC AHB1 peripheral reset register,                          Address offset: 0x10    */
    __vo uint32_t AHB2RSTR;     /* RCC AHB2 peripheral reset register,                          Address offset: 0x14    */
    __vo uint32_t AHB3RSTR;     /* RCC AHB3 peripheral reset register,                          Address offset: 0x18    */
    uint32_t      RESERVED0;    /* RCC reserved register,                                       Address offset: 0x1C    */
    __vo uint32_t APB1RSTR;     /* RCC APB1 peripheral reset register,                          Address offset: 0x20 	*/
    __vo uint32_t APB2RSTR;     /* RCC APB2 peripheral reset register,                          Address offset: 0x24    */
    uint32_t      RESERVED1[2]; /* RCC reserved register,                                       Address offset: 0x28-2C */
    __vo uint32_t AHB1ENR;      /* RCC AHB1 peripheral clock enable register,                   Address offset: 0x30    */
    __vo uint32_t AHB2ENR;      /* RCC AHB2 peripheral clock enable register,                   Address offset: 0x34    */
    __vo uint32_t AHB3ENR;      /* RCC AHB3 peripheral clock enable register,                   Address offset: 0x38    */
    uint32_t      RESERVED2;    /* RCC reserved register,                                       Address offset: 0x3C    */
    __vo uint32_t APB1ENR;      /* RCC APB1 peripheral clock enable register,                   Address offset: 0x40    */
    __vo uint32_t APB2ENR;      /* RCC APB2 peripheral clock enable register,                   Address offset: 0x44    */
    uint32_t      RESERVED3[2];	/* RCC reserved register,                                       Address offset: 0x48-4C */
    __vo uint32_t AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register,	Address offset: 0x50    */
    __vo uint32_t AHB2LPENR;	/* RCC AHB2 peripheral clock enable in low power mode register,	Address offset: 0x54 	*/
    __vo uint32_t AHB3LPENR;	/* RCC AHB3 peripheral clock enable in low power mode register,	Address offset: 0x58 	*/
    uint32_t      RESERVED4;    /* RCC reserved register,                                       Address offset: 0x5C    */
    __vo uint32_t APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register,	Address offset: 0x60    */
    __vo uint32_t APB2LPENR;    /* RCC APB2 peripheral clock enable in low power mode register,	Address offset: 0x64    */
    uint32_t      RESERVED5[2]; /* RCC reserved register,                                       Address offset: 0x68-6C */
    __vo uint32_t BDCR;         /* RCC back up domain control register,                         Address offset: 0x70    */
    __vo uint32_t CSR;          /* RCC clock control & status register,                         Address offset: 0x74    */
    uint32_t      RESERVED6[2]; /* RCC reserved register,                                       Address offset: 0x78-7C */
    __vo uint32_t SSCGR;        /* RCC spread spectrum clock generation register,               Address offset: 0x80    */
    __vo uint32_t PLLI2SCFGR;   /* RCC PLLI2S configuration register,                           Address offset: 0x84    */
    __vo uint32_t PLLSAICFGR;   /* RCC PLL configuration register,                              Address offset: 0x88    */
    __vo uint32_t DCKCFGR;      /* RCC dedicated clock configuration register,                  Address offset: 0x8C    */
    __vo uint32_t CKGATENR;     /* RCC clock gated enable register,                             Address offset: 0x90    */
    __vo uint32_t DCKCFGR2;     /* RCC dedicated clock configuration register 2,                Address offset: 0x94    */
}RCC_RegDef_t;







/*
 * Peripheral definition (peripheral base address typecasted to xxx_RegDef_t)
 */

/* GPIO_RegDef_t *pGPIOA = GPIOA(base address of gpioa);*/


#define GPIOA					((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t *)GPIOD_BASE_ADDR)
#define GPIOE					((GPIO_RegDef_t *)GPIOE_BASE_ADDR)
#define GPIOF					((GPIO_RegDef_t *)GPIOF_BASE_ADDR)
#define GPIOG					((GPIO_RegDef_t *)GPIOG_BASE_ADDR)
#define GPIOH					((GPIO_RegDef_t *)GPIOH_BASE_ADDR)


#define RCC 					((RCC_RegDef_t *)RCC_BASE_ADDR)

/*Clock Enable Macros for GPIOx Peripherals */

/* Go the address pointed by rcc and access the member AHB1ENR
 (*pointer).member
 RCC->AHB1ENR
 (*RCC).AHB1ENR  -- The compiler will reading this as *(RCC.AHB1ENR)

 because the member-access operator (.) binds tighter than the dereference operator (*). That means you’re attempting to treat the value of RCC.AHB1ENR as an address and dereference it—almost certainly not what you want.
 */

#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1<<7))

/*Clock Enable Macros for I2Cx Peripherals */
#define I2C1_PCLK_EN()		(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()		(RCC->APB1ENR |= (1<<23))

/*Clock Enable Macros for SPIx Peripherals*/
/* PCLK -> PERIPHERAL CLOCK */
#define SPI1_PCLK_EN()		(RCC->APB2ENR |= (1<<12))
#define SPI4_PCLK_EN()		(RCC->APB2ENR |= (1<<13))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |= (1<<15))

/*Clock Enable Macros for USARTc Peripherals */
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN()	(RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_EN()		(RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_EN()		(RCC->APB1ENR |= (1<<20))
#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1<<4))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1<<5))

/*Clock Enable Macros for SYSCFG peripheral*/
#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1<<14)) /* SYSCFG peripheral clock enabled */

/*Clock Disable Macros for GPIOx Peripherals*/
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<7))

/* Clock Disable Macros for I2Cx peripherals*/
#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<23))

/*Clock Disable Macros for USARTx Peripherals*/
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()	(RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()		(RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()		(RCC->APB1ENR &= ~(1<<20))
#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1<<4))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1<<5))

/*Clock Disable Macros for SYSCFG Peripheral*/
#define SYSCFG_PCLK_DI()    (RCC->APB2ENR &= ~(1<<14))

/* Macros to reset GPIOx Peripherals*/
#define GPIOA_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 0 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOB_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 1 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOC_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 2 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOD_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 3 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOE_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 4 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOF_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 5 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOG_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 6 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)
#define GPIOH_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 7 )); (RCC->AHB1RSTR &= ~(1 <<0 )); }while(0)

#include "STM32F446XX_GPIO_DRIVER.h"
/* ==============================================================================================================================*/

#endif /* INC_STM32F446XX_H_ */
