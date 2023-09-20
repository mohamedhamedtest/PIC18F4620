/* 
 * File:   application.h
 * Author: Mohamed
 *
 * Created on June 29, 2023, 4:31 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* Section : Includes */
#include"ECU_Layer/LED/ecu_led.h"
#include"ECU_Layer/button/ecu_button.h"
#include"ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/DC_MOTOR/ecu_dc_motor.h"
#include"ECU_Layer/7_Segment/ecu_seven_segment.h"
#include"ECU_Layer/KeyPad/ecu_keypad.h"
#include"ECU_Layer/Chr_LCD/ecu_chr_lcd.h"
#include"MCAL_Layer/interrupt/mcal_external_interrupt.h"
#include"MCAL_Layer/EEPROM/hal_eeprom.h"
#include"MCAL_Layer/ADC/hal_adc.h"
#include"MCAL_Layer/Timer0/hal_timer0.h"
#include"MCAL_Layer/Timer1/hal_timer1.h"
#include"MCAL_Layer/Timer2/hal_timer2.h"
#include"MCAL_Layer/CCP/hal_ccp.h"
#include"MCAL_Layer/usart/hal_usart.h"
#include"MCAL_Layer/SPI/hal_spi.h"
#include"MCAL_Layer/I2C/hal_i2c.h"







void application_intialize(void);


/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */
#endif	/* APPLICATION_H */

