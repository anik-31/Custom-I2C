#include "stm32f4xx.h"

#define I2C_MASTER_ADDRESS  0x10  // Master address (arbitrary, usually ignored)
#define I2C_SLAVE_ADDRESS   0x28  // Address of the slave (ESP32)
#define I2C_SPEED           100000  // 100 kHz

void I2C_Master_Init(void);
void I2C_Master_Write(uint8_t slave_addr, uint8_t *data, uint8_t length);

int main(void) {
    uint8_t message[] = "Hello, ESP32!";

    
    I2C_Master_Init();

    while (1) {
        
        I2C_Master_Write(I2C_SLAVE_ADDRESS, message, sizeof(message) - 1);

        
        for (volatile int i = 0; i < 500000; i++);
    }
}

void I2C_Master_Init(void) {
    /
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // Configure PB8 and PB9 as alternate function (AF4 for I2C1)
    GPIOB->MODER &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9);
    GPIOB->MODER |= GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1; // Alternate function
    GPIOB->OTYPER |= GPIO_OTYPER_OT_8 | GPIO_OTYPER_OT_9; // Open-drain
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8 | GPIO_OSPEEDER_OSPEEDR9; // High speed
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR8_0 | GPIO_PUPDR_PUPDR9_0; // Pull-up
    GPIOB->AFR[1] |= (4 << GPIO_AFRH_AFSEL8_Pos) | (4 << GPIO_AFRH_AFSEL9_Pos); // AF4

    // Enable I2C1 clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    
    I2C1->CR2 = 16; // APB1 clock frequency (16 MHz)
    I2C1->CCR = 80; // Clock control (100 kHz)
    I2C1->TRISE = 17; // Maximum rise time
    I2C1->CR1 = I2C_CR1_PE; // Enable I2C
}

void I2C_Master_Write(uint8_t slave_addr, uint8_t *data, uint8_t length) {
    
    while (I2C1->SR2 & I2C_SR2_BUSY);

    
    I2C1->CR1 |= I2C_CR1_START;

   
    while (!(I2C1->SR1 & I2C_SR1_SB));

    
    I2C1->DR = (slave_addr << 1);

    
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    (void)I2C1->SR2; 

    
    for (uint8_t i = 0; i < length; i++) {
        I2C1->DR = data[i];
        while (!(I2C1->SR1 & I2C_SR1_TXE)); 
    }

    // Generate stop condition
    I2C1->CR1 |= I2C_CR1_STOP;
}
