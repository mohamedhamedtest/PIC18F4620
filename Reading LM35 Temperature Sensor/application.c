 
/*
 * File:   application.c
 * Author: Mohamed
 *
 * Created on June 29, 2023, 2:15 PM
 */
#include"application.h"

dc_motor_t dc_motor_1 = {
    .dc_motor_pin[0].port = PORTD_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTD_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};

dc_motor_t dc_motor_2 = {
    .dc_motor_pin[0].port = PORTD_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTD_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};

chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN2,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN3,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN4,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN5,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW
};

adc_conf_t adc_1 = {
    .ADC_InterruptHandler = NULL,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};
led_t led1={
.port_name=  PORTD_INDEX,
.pin=       GPIO_PIN4,
.led_status=GPIO_LOW
};
led_t led2={
.port_name=  PORTD_INDEX,
.pin=       GPIO_PIN5,
.led_status=GPIO_LOW
};

uint16 lm35_res_1, lm35_res_2,lm35_res_3, lm35_res_1_Celsius_mv = 0, lm35_res_2_Celsius_mv = 0 ,lm35_res_3_Celsius_mv=0;
uint8 lm35_res_1_txt[7], lm35_res_2_txt[7] ,lm35_res_3_txt[7];

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
  ret = lcd_4bit_send_string_pos(&lcd_1, 1, 4, "MOHAMED HAMED");
    __delay_ms(2000);
    ret = lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
    
    
    ret = lcd_4bit_send_string_pos(&lcd_1, 2, 5, "LM35 Test");
    ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, "Temp1: ");
    ret = lcd_4bit_send_string_pos(&lcd_1, 4, 1, "Temp2: ");

    
    while(1){
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN0, &lm35_res_1);
        ret = ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN1, &lm35_res_2);

        
        lm35_res_1_Celsius_mv = lm35_res_1 * 4.88f; /* 5000(mv) / 1024(10-Bit) => 4.88 */
        lm35_res_2_Celsius_mv = lm35_res_2 * 4.88f; /* 5000(mv) / 1024(10-Bit) => 4.88 */
        
        lm35_res_1_Celsius_mv /= 10; /* The sensitivity of LM35 is 10 mV/degree Celsius */
        lm35_res_2_Celsius_mv /= 10; /* The sensitivity of LM35 is 10 mV/degree Celsius */

        
        ret = convert_uint16_to_string(lm35_res_1_Celsius_mv, lm35_res_1_txt);
        ret = convert_uint16_to_string(lm35_res_2_Celsius_mv, lm35_res_2_txt);
        
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 8, lm35_res_1_txt);
        ret = lcd_4bit_send_string_pos(&lcd_1, 4, 8, lm35_res_2_txt);

        
        if(lm35_res_1_Celsius_mv > 25){
            ret = dc_motor_move_right(&dc_motor_1);
                        __delay_ms(250);
                     ret=   led_turn_off(&led1);

        }
        else{
           ret = dc_motor_stop(&dc_motor_1);
            __delay_ms(250);
                     ret=   led_turn_on(&led1);

        }
    
        if(lm35_res_2_Celsius_mv > 25){
            ret = dc_motor_move_right(&dc_motor_2);
                        __delay_ms(250);
                   ret=   led_turn_off(&led2);

        }
        else{
            ret = dc_motor_stop(&dc_motor_2);
           __delay_ms(250);
              ret=   led_turn_on(&led2);
        }
        
      
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
    ret = lcd_4bit_intialize(&lcd_1);
    ret = ADC_Init(&adc_1);
    ret = dc_motor_initialize(&dc_motor_1);
    ret = dc_motor_initialize(&dc_motor_2);
    
    ret =led_initialize(&led1);
     ret =led_initialize(&led2);
//    ecu_layer_intialize();
}
