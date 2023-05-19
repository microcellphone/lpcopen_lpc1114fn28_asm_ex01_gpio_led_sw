/*
===============================================================================
 Name        : lpcopen_lpc1114fn28_asm_ex01_gpio_led_sw.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "led.h"
#include "sw.h"

// TODO: insert other definitions and declarations here
extern void gpio_config_request(void);

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
	int8_t SW1_status;
	int8_t SW2_status;
	int8_t SW3_status;
	int8_t SW4_status;


	gpio_config_request();

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
//    	SW1_status = (LPC_GPIO[SW1_PORT].DATA[(1 << SW1_BIT)]) >> SW1_BIT;
    	SW1_status = Chip_GPIO_GetPinState(LPC_GPIO, SW1_PORT, SW1_BIT);
    	if(SW1_status) {							// SW1(OFF)
//    		LPC_GPIO[LED1_PORT].DATA[(1 << LED1_BIT)] |=  (1 << LED1_BIT);	// PIO0_7->High（LED1 on）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED1_PORT, LED1_BIT, true);
    	}else{	// SW1(ON)
//    		LPC_GPIO[LED1_PORT].DATA[(1 << LED1_BIT)] &= ~(1 << LED1_BIT);	// PIO0_7->Low（LED1 off）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED1_PORT, LED1_BIT, false);
    	}
//    	SW2_status = (LPC_GPIO[SW2_PORT].DATA[(1 << SW2_BIT)]) >> SW2_BIT;
    	SW2_status = Chip_GPIO_GetPinState(LPC_GPIO, SW2_PORT, SW2_BIT);
    	if(SW2_status) {							// SW2(OFF)
//    		LPC_GPIO[LED2_PORT].DATA[(1 << LED2_BIT)] |=  (1 << LED2_BIT);	// R_PIO1_0->High（LED2 off）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED2_PORT, LED2_BIT, true);
    	}else{								// SW2(ON)
//    		LPC_GPIO[LED2_PORT].DATA[(1 << LED2_BIT)] &= ~(1 << LED2_BIT);	// R_PIO1_0->Low（LED2 on）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED2_PORT, LED2_BIT, false);
    	}
//    	SW3_status = (LPC_GPIO[SW3_PORT].DATA[(1 << SW3_BIT)]) >> SW3_BIT;
    	SW3_status = Chip_GPIO_GetPinState(LPC_GPIO, SW3_PORT, SW3_BIT);
    	if(SW3_status) {	// SW3(OFF)
//    		LPC_GPIO[LED3_PORT].DATA[(1 << LED3_BIT)] |=  (1 << LED3_BIT);	// PIO1_4->High（LED3 off）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED3_PORT, LED3_BIT, true);
    	}else{								// SW3(ON)
//    		LPC_GPIO[LED3_PORT].DATA[(1 << LED3_BIT)] &= ~(1 << LED3_BIT);	// PIO1_4->Low（LED3 on）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED3_PORT, LED3_BIT, false);
    	}
//    	SW4_status = (LPC_GPIO[SW4_PORT].DATA[(1 << SW4_BIT)]) >> SW4_BIT;
    	SW4_status = Chip_GPIO_GetPinState(LPC_GPIO, SW4_PORT, SW4_BIT);
    	if(SW4_status) {	// SW4(OFF)
//    		LPC_GPIO[LED4_PORT].DATA[(1 << LED4_BIT)] |=  (1 << LED4_BIT);	// PIO1_5->High（LED4 off）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED4_PORT, LED4_BIT, true);
    	}else{	// SW4(ON)
//    		LPC_GPIO[LED4_PORT].DATA[(1 << LED4_BIT)] &= ~(1 << LED4_BIT);	// PIO1_5->Low（LED4 on）
    		Chip_GPIO_SetPinState(LPC_GPIO, LED4_PORT, LED4_BIT, false);
    	}
    	i++ ;
    	// "Dummy" NOP to allow source level single
    	// stepping of tight while() loop
    	__asm volatile ("nop");
    }
    return 0 ;
}
