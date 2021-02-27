/**
 * @file       can_driver.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-02-26
 * @author     Thuan Le
 * @brief      Driver support Can Bus
 * @note       None
 * @example    None
 */

/**
 * =============================================================================
 *                   ##### Can Buffer Transmit and Receive #####
 * =============================================================================
 * (+) Transmit Buffer: Three transmit mailboxes. Mailbox can handler 1 message
 * => 3 messages Buffer
 * 
 * (+) Receive Buffer: Two receive FIFOs are used to store messages.
 * Three messages can be stored in each FIFO => 6 messages Buffer
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __CAN_DRIVER_H
#define __CAN_DRIVER_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include "can.h"

/* Public defines ----------------------------------------------------- */
#define CAN_RX_BUFFER_SIZE 20
#define CAN_TX_BUFFER_SIZE 20

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief Can message ID enum
 */
typedef enum
{
  MASTER_MSG_CONFIG_NODE_ID  = 0x10U,
  MASTER_MSG_CONFIG_HOLE_ID  = 0x11U,
}
can_msg_id_t;

/**
 * @brief Can rx message handler struture
 */
typedef struct
{
  CAN_RxHeaderTypeDef can_rx_header;
  uint8_t rx_data[8];
}
can_rx_msg_handler_t;

/**
 * @brief Can tx message handler struture
 */
typedef struct
{
  CAN_TxHeaderTypeDef can_tx_header;
  uint8_t tx_data[8];
}
can_tx_msg_handler_t;

extern uint8_t rx_msg_in;
extern uint8_t rx_msg_out;
extern uint8_t tx_msg_in;
extern uint8_t tx_msg_out;
extern uint32_t tx_mail_box;

extern can_rx_msg_handler_t can_rx_buffer[CAN_RX_BUFFER_SIZE];
extern can_tx_msg_handler_t can_tx_buffer[CAN_TX_BUFFER_SIZE];

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         AS5024A get rotation in degrees
 *
 * @param[in]     me        Pointer to as5048a structure
 * @param[in]     degrees   Pointer to degrees
 * 
 * @attention     None
 *
 * @return        AS5048A_OK
 * @return        AS5048A_ERR_SPI
 */
void can_driver_begin(void);

/**
 * @brief         AS5024A get rotation in degrees
 *
 * @param[in]     me        Pointer to as5048a structure
 * @param[in]     degrees   Pointer to degrees
 * 
 * @attention     None
 *
 * @return        AS5048A_OK
 * @return        AS5048A_ERR_SPI
 */
void can_driver_msg_send(void);

#endif // __CAN_DRIVER_H

/* End of file -------------------------------------------------------- */
