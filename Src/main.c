// where is the user LED
// Port: A
// Pin : 5

#define PERI_BASE              (0x40000000UL)
#define AHB1PERI_OFFSET        (0x00020000UL)
#define AHB1PERI_BASE          (PERI_BASE + AHB1PERI_OFFSET)

#define GPIOA_OFFSET           (0x00000000UL)
#define GPIOA_BASE             (AHB1PERI_BASE + GPIOA_OFFSET)

#define RCC_OFFSET             (0x00003800UL)
#define RCC_BASE               (AHB1PERI_BASE + RCC_OFFSET)

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

}
