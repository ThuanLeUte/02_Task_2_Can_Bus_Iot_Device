/**
 * @file       sys.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      System module to handle system CAN bus
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "sys_can.h"
#include "can_driver.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
//static sys_can_msg_update_logical_t m_can_msg_update_logical;

/* Private function prototypes ---------------------------------------- */
static void m_sys_can_pack_msg_update_logical(can_tx_msg_handler_t *p_tx_buff);
static void m_sys_can_update_tx_header(can_tx_msg_handler_t *p_tx_buff, uint8_t msg_id);

/* Function definitions ----------------------------------------------- */
void sys_can_send_msg(msg_handle_send_t msg_handle)
{
  switch (msg_handle)
  {
  case TX_MSG_UPDATE_LOGICAL:
    m_sys_can_pack_msg_update_logical(&can_tx_buffer[tx_msg_out]);
    m_sys_can_update_tx_header(&can_tx_buffer[tx_msg_out], 12);
    break;

  default:
    break;
  }

  // Can send out
  can_driver_msg_send();
}

void sys_can_receive_msg(void)
{

}

/* Private function definitions---------------------------------------- */
static void m_sys_can_pack_msg_update_logical(can_tx_msg_handler_t *p_tx_buff)
{
  p_tx_buff->tx_data[0] = 1;
  p_tx_buff->tx_data[1] = 2;
  p_tx_buff->tx_data[2] = 3;
  p_tx_buff->tx_data[3] = 4;
  p_tx_buff->tx_data[4] = 5;
  p_tx_buff->tx_data[5] = 6;
  p_tx_buff->tx_data[6] = 7;
  p_tx_buff->tx_data[7] = 8;
}

static void m_sys_can_update_tx_header(can_tx_msg_handler_t *p_tx_buff, uint8_t msg_id)
{
  p_tx_buff->can_tx_header.StdId = msg_id;
  p_tx_buff->can_tx_header.DLC   = 8;
  p_tx_buff->can_tx_header.IDE   = CAN_ID_STD;
  p_tx_buff->can_tx_header.RTR   = CAN_RTR_DATA;
}

/* End of file -------------------------------------------------------- */
