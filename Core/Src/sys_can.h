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
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
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
void sys_can_send_msg(void);

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
