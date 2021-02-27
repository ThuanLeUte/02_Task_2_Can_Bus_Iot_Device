/**
 * @file       sys.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      System module to handle system state
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYS_H
#define __SYS_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <string.h>

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
void sys_boot(void);

/**
 * @brief         System run
 *
 * @param[in]     None
 * 
 * @attention     None
 *
 * @return        None
 */
void sys_run(void);

#endif // __SYS_H

/* End of file -------------------------------------------------------- */
