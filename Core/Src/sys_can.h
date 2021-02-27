/**
 * @file       sys_can.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      System module to handle system CAN bus
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYS_CAN_H
#define __SYS_CAN_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief Can message send handler enum
 */
typedef enum
{
  TX_MSG_UPDATE_LOGICAL,
  TX_MSG_COUNT
}
msg_handle_send_t;

/**
 * @brief Can message receive handler enum
 */
typedef enum
{
  RX_MSG_CTR,
  RX_MSG_COUNT
}
msg_handle_receive_t;

/**
 * @brief Can message update logical struct
 */
typedef struct
{
  uint8_t divice_id;
  uint8_t data_1;
  uint8_t data_2;
  uint8_t data_3;
  uint8_t data_4;
  uint8_t data_5;
  uint8_t data_6;
  uint8_t data_7;
}
sys_can_msg_update_logical_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         System boot
 *
 * @param[in]     None
 * 
 * @attention     None
 *
 * @return        None
 */
void sys_can_send_msg(msg_handle_send_t msg_handle);

/**
 * @brief         System run
 *
 * @param[in]     None
 * 
 * @attention     None
 *
 * @return        None
 */
void sys_can_receive_msg(void);

#endif // __SYS_CAN_H

/* End of file -------------------------------------------------------- */
