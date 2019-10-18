#include <stm32f0xx.h>
#include <stm32f0_helpers.h>
#include "gpio.h"

/*
 * RX_INT: PB10
 * TX_INT: PB11
 * CAN_RES: PB12
 * LED_YEL: PB3 
 * LED_RED: PB2
 * PWR_IN: PB0
 * PWR_DEN: PB1
 */

void gpio_init(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIO_CONFIGURE_OUTPUT(GPIOB, PWR_IN_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, PWR_DEN_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, LED_RED_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, LED_YEL_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, RX_INT_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, TX_INT_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_OUTPUT(GPIOB, CAN_RES_Pin, GPIO_SPEED_LOW, GPIO_PUSH_PULL); 

    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIO_CONFIGURE_OUTPUT(GPIOA, SWDIO_Pin,  GPIO_SPEED_LOW, GPIO_PUSH_PULL); 
    GPIO_CONFIGURE_INPUT(GPIOA, SWCLK_Pin);
    GPIO_CONFIGURE_PULL_UP_DOWN(GPIOA, SWCLK_Pin, GPIO_PULL_UP);
}

void gpio_deinit(void)
{
    GPIO_CONFIGURE_INPUT(GPIOA, SWDIO_Pin);
    GPIO_CONFIGURE_PULL_UP_DOWN(GPIOA, SWCLK_Pin, GPIO_PULL_NONE);
    GPIO_CONFIGURE_ALTERNATE_FUNCTION(GPIOA, SWDIO_Pin, GPIO_AF_0);
    GPIO_CONFIGURE_ALTERNATE_FUNCTION(GPIOA, SWCLK_Pin, GPIO_AF_0);
}