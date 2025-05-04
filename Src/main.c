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
#define RCC_AHB1EN_R           (RCC_BASE + AHB1EN_R_OFFSET)

//GPIO MODE REGISTER
#define GPIOA_MODE_R_OFFSET    (0x00000000UL)
#define GPIOA_MODE_R           (GPIOA_BASE + GPIOA_MODE_R_OFFSET)

// GPIOAEN
#define GPIOAEN                (1U<<0) // enabling GPIOA by giving RCC clock to bit 0


