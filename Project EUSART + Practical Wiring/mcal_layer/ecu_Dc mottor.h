/* 
 * File:   ecu_Dc mottor.h
 * Author: T-BOX
 *
 * Created on August 28, 2023, 4:45 PM
 */

#ifndef ECU_DC_MOTTOR_H
#define	ECU_DC_MOTTOR_H

#include "ecu_Dc mottor_con.h"
#include "../mcal_layer/GPIO/hal_gpio.h"

/* ----------------- Macro Declarations -----------------*/
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

typedef struct{
    uint8 dc_mottor_port : 4;
    uint8 dc_mottor_pin : 3;
    uint8 dc_mottor_status : 1;
}Dc_mottor_t;


typedef struct{
    Dc_mottor_t dc_motor_pin[2];
}dc_motor_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_returntype dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_returntype dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_returntype dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_returntype dc_motor_stop(const dc_motor_t *_dc_motor);


#endif	/* ECU_DC_MOTTOR_H */

