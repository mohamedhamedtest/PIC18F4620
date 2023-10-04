#include "ecu_Dc mottor.h"

Std_returntype dc_motor_initialize(const dc_motor_t *_dc_motor){



Std_returntype ret =E_ok;
 
    if(NULL == _dc_motor){
        ret = E_Not_ok;
    }
    else{
    pin_config_t  motor_con1 ={.port=_dc_motor->dc_motor_pin[0].dc_mottor_port,
      .pin=_dc_motor->dc_motor_pin[0].dc_mottor_pin,
         .logic=_dc_motor->dc_motor_pin[0].dc_mottor_status,
           .direction=OUTPUT,   } ;                  
      
   pin_config_t  motor_con2 ={.port=_dc_motor->dc_motor_pin[1].dc_mottor_port,
       .pin=_dc_motor->dc_motor_pin[1].dc_mottor_pin,
          .logic=_dc_motor->dc_motor_pin[1].dc_mottor_status,
         .direction=OUTPUT } ;                 
      
       gpio_pin_intialize(&motor_con1);
        gpio_pin_intialize(&motor_con2);

      
      
      
    }
    return ret;



}
Std_returntype dc_motor_move_right(const dc_motor_t *_dc_motor){



Std_returntype ret =E_ok;
 
    if(NULL == _dc_motor){
        ret = E_Not_ok;
    }
    else{
          pin_config_t  motor_con1 ={.port=_dc_motor->dc_motor_pin[0].dc_mottor_port,
      .pin=_dc_motor->dc_motor_pin[0].dc_mottor_pin,
         .logic=_dc_motor->dc_motor_pin[0].dc_mottor_status,
           .direction=OUTPUT,   } ;                  
      
   pin_config_t  motor_con2 ={.port=_dc_motor->dc_motor_pin[1].dc_mottor_port,
       .pin=_dc_motor->dc_motor_pin[1].dc_mottor_pin,
          .logic=_dc_motor->dc_motor_pin[1].dc_mottor_status,
         .direction=OUTPUT } ;                 
      gpio_pin_write_logic(&motor_con1,HIGH);
       gpio_pin_write_logic(&motor_con2 ,LOW);
      
    }
    return ret;}
Std_returntype dc_motor_move_left(const dc_motor_t *_dc_motor){



Std_returntype ret =E_ok;
 
    if(NULL == _dc_motor){
        ret = E_Not_ok;
    }
    else{
        
          pin_config_t  motor_con1 ={.port=_dc_motor->dc_motor_pin[0].dc_mottor_port,
      .pin=_dc_motor->dc_motor_pin[0].dc_mottor_pin,
         .logic=_dc_motor->dc_motor_pin[0].dc_mottor_status,
           .direction=OUTPUT,   } ;                  
      
   pin_config_t  motor_con2 ={.port=_dc_motor->dc_motor_pin[1].dc_mottor_port,
       .pin=_dc_motor->dc_motor_pin[1].dc_mottor_pin,
          .logic=_dc_motor->dc_motor_pin[1].dc_mottor_status,
         .direction=OUTPUT } ;                 
      gpio_pin_write_logic(&motor_con1,LOW);
       gpio_pin_write_logic(&motor_con2 ,HIGH);
      
      
    }
    return ret;}
Std_returntype dc_motor_stop(const dc_motor_t *_dc_motor){






Std_returntype ret =E_ok;
 
    if(NULL == _dc_motor){
        ret = E_Not_ok;
    }
    else{
          pin_config_t  motor_con1 ={.port=_dc_motor->dc_motor_pin[0].dc_mottor_port,
      .pin=_dc_motor->dc_motor_pin[0].dc_mottor_pin,
         .logic=_dc_motor->dc_motor_pin[0].dc_mottor_status,
           .direction=OUTPUT,   } ;                  
      
   pin_config_t  motor_con2 ={.port=_dc_motor->dc_motor_pin[1].dc_mottor_port,
       .pin=_dc_motor->dc_motor_pin[1].dc_mottor_pin,
          .logic=_dc_motor->dc_motor_pin[1].dc_mottor_status,
         .direction=OUTPUT } ;                 
     
       gpio_pin_write_logic(&motor_con1,LOW);
       gpio_pin_write_logic(&motor_con2 ,LOW);
      
    }
    return ret;}

