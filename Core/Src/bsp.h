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
#ifndef __BSP_H
#define __BSP_H

/* Includes ----------------------------------------------------------- */
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
#define LOG(...)            bsp_log_data(__VA_ARGS__)

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Logging data
 * 
 * @param[in]     <format>      Pointer to format data
 *
 * @attention     None
 * 
 * @return        None
 */
void bsp_log_data(const char *fmt, ...);

#endif // __BSP_H

/* End of file -------------------------------------------------------- */
