/*
 * File:   main.c
 * Author: T-BOX
 *
 * Created on August 22, 2023, 3:39 PM
 */



#include"application.h"
#include <xc.h>
#define _XTAL_FREQ 8000000 //define crystal frequency to 20MHz

uint32 array[10]={0XC0 , 0XF9,0xA4,0XB0 ,0X99,0X92,0X82,0XF8,0X80,0X90};

/*chr_lcd_8bit_t lcd1={.lcd_rs.port=PORTA_INDEX,.lcd_rs.pin=PIN0,.lcd_rs.logic=LOW,.lcd_rs.direction=OUTPUT,
                      .lcd_en.port=PORTA_INDEX,.lcd_en.pin=PIN1,.lcd_en.logic=LOW,.lcd_en.direction=OUTPUT,
                       .lcd_data[0].port=PORTB_INDEX,.lcd_data[0].pin=PIN0,.lcd_data[0].logic=LOW,.lcd_data[0].direction=OUTPUT,
                       .lcd_data[1].port=PORTB_INDEX,.lcd_data[1].pin=PIN1,.lcd_data[1].logic=LOW,.lcd_data[1].direction=OUTPUT ,
                        .lcd_data[2].port=PORTB_INDEX,.lcd_data[2].pin=PIN2,.lcd_data[2].logic=LOW,.lcd_data[2].direction=OUTPUT,
                          .lcd_data[3].port=PORTB_INDEX,.lcd_data[3].pin=PIN3,.lcd_data[3].logic=LOW,.lcd_data[3].direction=OUTPUT,
                          .lcd_data[4].port=PORTB_INDEX,.lcd_data[4].pin=PIN4,.lcd_data[4].logic=LOW,.lcd_data[4].direction=OUTPUT,
                           .lcd_data[5].port=PORTB_INDEX,.lcd_data[5].pin=PIN5,.lcd_data[5].logic=LOW,.lcd_data[5].direction=OUTPUT,
                           .lcd_data[6].port=PORTB_INDEX,.lcd_data[6].pin=PIN6,.lcd_data[6].logic=LOW,.lcd_data[6].direction=OUTPUT,
                            .lcd_data[7].port=PORTB_INDEX,.lcd_data[7].pin=PIN7,.lcd_data[7].logic=LOW,.lcd_data[7].direction=OUTPUT};

*/
usart_t x = {

    .EUSART_FramingErrorHandler=NULL,
    .EUSART_OverrunErrorHandler=NULL,
    .EUSART_RxDefaultInterruptHandler=NULL,
    .EUSART_TxDefaultInterruptHandler=NULL,
    .baudrate=9600,
    .baudrate_gen_gonfig = BAUDRATE_ASYN_8BIT_lOW_SPEED,
    .usart_tx_cfg.usart_tx_enable=EUSART_ASYNCHRONOUS_TX_ENABLE,
    .usart_tx_cfg.usart_tx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE,
    .usart_tx_cfg.usart_tx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE,
    .usart_rx_cfg.usart_rx_enable=EUSART_ASYNCHRONOUS_RX_ENABLE,
    .usart_rx_cfg.usart_rx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE,
    .usart_rx_cfg.usart_rx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE,
};

led_t led1={
.port_name=  PORTA_INDEX,
.pin=       PIN0,
.led_status=LOW
};
led_t led2={
.port_name=  PORTA_INDEX,
.pin=       PIN1,
.led_status=LOW
};

dc_motor_t dc_mottor_1 ={ .dc_motor_pin[0].dc_mottor_port=PORTA_INDEX,
                          .dc_motor_pin[0].dc_mottor_pin=PIN2,
                            .dc_motor_pin[0].dc_mottor_status= DC_MOTOR_OFF_STATUS,
                             .dc_motor_pin[1].dc_mottor_port=PORTA_INDEX,
                            .dc_motor_pin[1].dc_mottor_pin=PIN3,
                            .dc_motor_pin[1].dc_mottor_status= DC_MOTOR_OFF_STATUS,




};
dc_motor_t dc_mottor_2 ={ .dc_motor_pin[0].dc_mottor_port=PORTA_INDEX,
                          .dc_motor_pin[0].dc_mottor_pin=PIN4,
                            .dc_motor_pin[0].dc_mottor_status= DC_MOTOR_OFF_STATUS,
                             .dc_motor_pin[1].dc_mottor_port=PORTA_INDEX,
                            .dc_motor_pin[1].dc_mottor_pin=PIN5,
                            .dc_motor_pin[1].dc_mottor_status= DC_MOTOR_OFF_STATUS,




};
uint8 c = 0;
int main() {
        uint8 x=0;
    uint32 z = 0;

    Std_returntype ret = E_Not_ok;

    application_int();

   // lcd_8bit_send_string_pos(&lcd1,1,1,"mohamed hamed");
              //             __delay_ms(1000);




    while(1){
   /*     for(z=0 ;z<10 ;z++){
                   ret = gpio_port_write_logic( PORTD_INDEX,array[z]);
                   __delay_ms(250);
              }
      ret = EUSART_ASYNC_WriteByteBlocking('g');
               __delay_ms(1000);
 ret = EUSART_ASYNC_WriteByteBlocking('a');
                         __delay_ms(1000);
  ret = EUSART_ASYNC_WriteByteBlocking('z');
                       __delay_ms(1000);
 ret = EUSART_ASYNC_WriteByteBlocking('a');
                         __delay_ms(1000);
   ret = EUSART_ASYNC_WriteByteBlocking('r');
                         __delay_ms(1000);
  lcd_8bit_send_string_pos(&lcd1,2,5,"gazar");
                           __delay_ms(1000);

     lcd_8bit_send_command(&lcd1,_LCD_CLEAR);

         lcd_8bit_send_string_pos(&lcd1,1,1,"mohamed hamed");
*/


  ret = EUSART_ASYNC_ReadByteBlocking(&c);
         if(c== 'g'){
                       led_turn_on(&led1);
                    ret =  dc_motor_move_right(&dc_mottor_1);

                ret =EUSART_ASYNC_WriteStringBlocking("led1 on \r",9);
                 ret =EUSART_ASYNC_WriteStringBlocking("motor1 on \r",11);


         }
         else if (c=='a'){
                         led_turn_on(&led2);
                       ret =  dc_motor_move_left(&dc_mottor_2);

               ret =EUSART_ASYNC_WriteStringBlocking("led2 on \r",9);
                                ret =EUSART_ASYNC_WriteStringBlocking("motor2 on \r",11);


        }
         else if(c== 'z'){
              ret =  dc_motor_stop(&dc_mottor_1);
                       led_turn_off(&led1);

                  ret =EUSART_ASYNC_WriteStringBlocking("led1 off \r",10);

                ret =EUSART_ASYNC_WriteStringBlocking("motor1 off \r",12);
         }
         else if (c=='a'){

         }
  else if (c=='r'){
      led_turn_off(&led2);

              ret =  dc_motor_stop(&dc_mottor_2);
                   ret =EUSART_ASYNC_WriteStringBlocking("led2 off \r",10);

               ret =EUSART_ASYNC_WriteStringBlocking("motor2 off \r",12);

                  for(z=0 ;z<10 ;z++){
                   ret = gpio_port_write_logic( PORTD_INDEX,array[z]);
                   __delay_ms(250);
              }

  }
    }
    return (EXIT_SUCCESS);
}

void application_int(void){
    Std_returntype ret = E_Not_ok;
    ret = EUSART_ASYNC_Init(&x);
          //  ret = lcd_8bit_intialize(&lcd1);
          ret = gpio_port_direction_intialize( PORTD_INDEX,0x80);


        ret =led_initialize(&led1);
        ret =led_initialize(&led2);

   ret =dc_motor_initialize(&dc_mottor_1 );
      ret =dc_motor_initialize(&dc_mottor_2 );


    //ecu_layer_intialize();
}
