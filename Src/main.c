// where is the user LED
// Port: A
// Pin : 5


#define STRUCTMETHOD
#define PERI_BASE              (0x40000000UL)
#define AHB1PERI_OFFSET        (0x00020000UL)
#define AHB1PERI_BASE          (PERI_BASE + AHB1PERI_OFFSET)

#define GPIOA_OFFSET           (0x00000000UL)
#define GPIOA_BASE             (AHB1PERI_BASE + GPIOA_OFFSET)

#define RCC_OFFSET             (0x00003800UL)
#define RCC_BASE               (AHB1PERI_BASE + RCC_OFFSET)

#ifdef STRUCTMETHOD

typedef unsigned long int uint32_t;
typedef struct
{
	volatile uint32_t GPIOx_MODER ;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;
}GPIO_Reg;

typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
  volatile uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
  volatile uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_TypeDef;

#define RCC     (*(RCC_TypeDef *)RCC_BASE)
#define GPIOA   (*(GPIO_Reg *)GPIOA_BASE)

#else
// AHB1 Enable Register offset

#define RCC_AHB1EN_R_OFFSET    (0x30u)
#define RCC_AHB1EN_R           (*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_R_OFFSET))

//GPIO MODE REGISTER
#define GPIOA_MODE_R_OFFSET    (0x00000000UL)
#define GPIOA_MODE_R            (*(volatile unsigned int *)(GPIOA_BASE + GPIOA_MODE_R_OFFSET))

// Output Data Register offset of GPIO
#define OD_R_OFFSET            (0x14UL)
// Output Data Register of GPIOA
#define GPIOA_OD_R             (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))
#endif

// GPIOAEN
#define GPIOAEN                (1U<<0) // enabling GPIOA by giving RCC clock to bit 0

#define PIN5                   (1U << 5)
#define LED_PIN                 PIN5

//Set Bit number 10
// (1U << 10)
// reset bit number 11
// &= ~(1U <<11)



int main (void)
{
	//Test : toggle LED
#ifdef STRUCTMETHOD

	// 1. enable clock access to GPIO A
		RCC.AHB1ENR |=  GPIOAEN;

		// 2. Set GPIO PIN 5 to Output
		GPIOA.GPIOx_MODER |= (1U <<10);
		GPIOA.GPIOx_MODER &= ~(1U <<11);

		while (1)
		{
			//3. Toggle LED
			GPIOA.GPIOx_ODR ^= (LED_PIN);
			for(int i =0; i< 100000; i++){}
		}
#else
	// 1. enable clock access to GPIO A
	RCC_AHB1EN_R |=  GPIOAEN;

	// 2. Set GPIO PIN 5 to Output
	GPIOA_MODE_R |= (1U <<10);
	GPIOA_MODE_R &= ~(1U <<11);

	while (1)
	{
		//3. Toggle LED
		GPIOA_OD_R ^= (LED_PIN);
		for(int i =0; i< 100000; i++){}
	}
#endif

}
