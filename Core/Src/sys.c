/**
 * @file       sys_can.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      System module to handle system state
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp.h"
#include "sys_can.h"
#include "can_driver.h"
#include "tim.h"

#include "sys.h"
/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static int x = 0;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
/* Private function definitions---------------------------------------- */
void sys_boot(void)
{
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  can_driver_begin();
}

void sys_run(void)
{
  LOG("1234567: %d", x);
  HAL_Delay(100);
  x++;
  sys_can_send_msg(TX_MSG_UPDATE_LOGICAL);

  for (int pwm = 0; pwm < 200; pwm = pwm + 10)
  {
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, pwm);
    HAL_Delay(100);
  }
  HAL_Delay(2000);
}

/* End of file -------------------------------------------------------- */
