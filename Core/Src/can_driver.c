/**
 * @file       can_driver.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      Driver support Can Bus
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "can_driver.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
uint8_t rx_msg_in  = 0;
uint8_t rx_msg_out = 0;

uint8_t tx_msg_in  = 0;
uint8_t tx_msg_out = 0;
uint32_t tx_mail_box;

can_rx_msg_handler_t can_rx_buffer[CAN_RX_BUFFER_SIZE];
can_tx_msg_handler_t can_tx_buffer[CAN_TX_BUFFER_SIZE];

/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void can_driver_begin(void)
{
  // Activate notification
  HAL_CAN_ActivateNotification(&hcan, CAN_IT_TX_MAILBOX_EMPTY);
  HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_RX_FIFO1_MSG_PENDING);

  // Start can
  HAL_CAN_Start(&hcan);
}

void can_driver_msg_send(void)
{
  // Wait until have atleat 1 mailbox free
  while (HAL_CAN_GetTxMailboxesFreeLevel(&hcan) == 0)
  {
    // Do nothing
  }

  if ((HAL_CAN_GetState(&hcan) == HAL_CAN_STATE_READY) || (HAL_CAN_GetState(&hcan) == HAL_CAN_STATE_LISTENING))
  {
    HAL_CAN_AddTxMessage(&hcan, &can_tx_buffer[tx_msg_out].can_tx_header, can_tx_buffer[tx_msg_out].tx_data, &tx_mail_box);
  }
  else
  {
    // Do nothing
  }
}

/* Private function definitions---------------------------------------- */
/** @defgroup CAN_Exported_Functions_Group5 Callback functions
 *  @brief    CAN Callback functions
 *
  ==============================================================================
                          ##### Callback functions #####
  ==============================================================================
    [..]
    This subsection provides the following callback functions:

      (+) HAL_CAN_RxFifo0MsgPendingCallback
      (+) HAL_CAN_RxFifo1MsgPendingCallback

      (+) HAL_CAN_rx_mail_box0CompleteCallback
      (+) HAL_CAN_rx_mail_box1CompleteCallback
      (+) HAL_CAN_rx_mail_box2CompleteCallback

      (+) HAL_CAN_ErrorCallback
 */

/**
 * @brief         Rx FIFO 0 message pending callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &can_rx_buffer[rx_msg_in].can_rx_header, can_rx_buffer[rx_msg_in].rx_data);
  rx_msg_in++;
  if (rx_msg_in >= CAN_RX_BUFFER_SIZE)
  {
    rx_msg_in = 0;
  }
}

/**
 * @brief         Rx FIFO 1 message pending callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &can_rx_buffer[rx_msg_in].can_rx_header, can_rx_buffer[rx_msg_in].rx_data);
  rx_msg_in++;
  if (rx_msg_in >= CAN_RX_BUFFER_SIZE)
  {
    rx_msg_in = 0;
  }
}

/**
 * @brief         Transmission Mailbox 0 complete callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
}

/**
 * @brief         Transmission Mailbox 1 complete callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan)
{
}

/**
 * @brief         Transmission Mailbox 1 complete callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan)
{
}

/**
 * @brief         Can error callback.
 *
 * @param[in]     hcan pointer to a CAN_HandleTypeDef structure that contains
 *                the configuration information for the specified CAN.
 * 
 * @attention     None
 *
 * @return        None
 */
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
  HAL_CAN_ResetError(hcan);
}

/* End of file -------------------------------------------------------- */
