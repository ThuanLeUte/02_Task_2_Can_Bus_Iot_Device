/**
 * @file       bsp.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "bsp.h"
#include "usart.h"

/* Private defines ---------------------------------------------------- */
#define PRINT_BUFFER_SIZE 250

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static void bsp_printf_valist(const char *fmt, va_list argp);

/* Function definitions ----------------------------------------------- */
void bsp_log_data(const char *fmt, ...)
{
  va_list argp;

  va_start(argp, fmt);
  bsp_printf_valist(fmt, argp);
  va_end(argp);
}

/* Private function definitions---------------------------------------- */
/**
 * @brief         Print uart
 * 
 * @param[in]     fmt      Pointer to format data
 * @param[in]     argp     Arguments
 *
 * @attention     None
 * 
 * @return        None
 */
static void bsp_printf_valist(const char *fmt, va_list argp)
{
  char msg_buff[PRINT_BUFFER_SIZE];

  vsprintf(msg_buff, fmt, argp);
  sprintf(&msg_buff[strlen(msg_buff)], "\r\n");

  // Uart transmit
  HAL_UART_Transmit(&huart1, (uint8_t *)msg_buff, strlen(msg_buff), HAL_MAX_DELAY);
}

/* End of file -------------------------------------------------------- */
