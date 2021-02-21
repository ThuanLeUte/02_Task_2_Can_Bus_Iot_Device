/**
 * @file       as5048.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-12-26
 * @author     Thuan Le
 * @brief      Driver support as5048a (Magnetic Encoder SPI)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __AS5048A_H
#define __AS5048A_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief AS5048A stattus enum
 */
typedef enum
{
  AS5048A_OK,
  AS5048A_ERR_PARAM,
  AS5048A_ERR_SPI
}
as5048a_status_t;

/**
 * @brief AS5048A structure
 */
typedef struct 
{
  int (*spi_read)  (uint8_t *p_data, uint16_t len, uint32_t time_out);
  int (*spi_write) (uint8_t *p_data, uint16_t len, uint32_t time_out);
}
as5048a_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief  <function description>
 *
 * @param[in]     <param_name>  <param_despcription>
 * @param[out]    <param_name>  <param_despcription>
 * @param[inout]  <param_name>  <param_despcription>
 *
 * @attention  <API attention note>
 *
 * @return  
 *  - 0: Success
 *  - 1: Error
 */
as5048a_status_t as5048a_get_raw_rotation(as5048a_t *me, uint16_t *rotation);

#endif // __AS5048A_H

/* End of file -------------------------------------------------------- */
