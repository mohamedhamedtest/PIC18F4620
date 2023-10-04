/* 
 * File:   hal_eeprom.h
 * Author: T-BOX
 *
 * Created on September 12, 2023, 5:20 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

#include "pic18f4620.h"
#include"../mcal_layer/mcal_std_types.h" 
#include"../mcal_layer/interupt/mcal_internal_interupt.h"



/* ----------------- Macro Declarations -----------------*/
/* Flash Program or Data EEPROM Memory Select  */
#define ACCESS_FLASH_PROGRAM_MEMORY       1
#define ACCESS_EEPROM_PROGRAM_MEMORY      0
/* Flash Program/Data EEPROM or Configuration Select */
#define ACCESS_CONFIG_REGISTERS           1
#define ACCESS_FLASH_EEPROM_MEMORY        0
/* Flash Program/Data EEPROM Write Enable */
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM   1
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM 0
/* Write Control */
#define INITIATE_DATA_EEPROM_WRITE_ERASE  1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0
/* Read Control */
#define INITIATE_DATA_EEPROM_READ         1

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
Std_returntype Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_returntype Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);

#endif	/* HAL_EEPROM_H */

