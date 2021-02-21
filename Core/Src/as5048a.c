/**
 * @file       as5048.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2020-12-26
 * @author     Thuan Le
 * @brief      Driver support as5048a (Magnetic Encoder SPI)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "as5048a.h"

/* Private defines ---------------------------------------------------- */
#define AS5048A_CLEAR_ERROR_FLAG             (0x0001)
#define AS5048A_PROGRAMMING_CONTROL          (0x0003)
#define AS5048A_OTP_REGISTER_ZERO_POS_HIGH   (0x0016)
#define AS5048A_OTP_REGISTER_ZERO_POS_LOW    (0x0017)
#define AS5048A_DIAG_AGC                     (0x3FFD)
#define AS5048A_MAGNITUDE                    (0x3FFE)
#define AS5048A_ANGLE                        (0x3FFF)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
#define CHECK(expr, ret)            \
  do {                              \
    if (!(expr)) {                  \
      return (ret);                 \
    }                               \
  } while (0)

#define AS_CHECK(expr)              \
  do {                              \
    as5048a_status_t ret = (expr);  \
    if (AS5048_OK != ret) {         \
      return (ret);                 \
    }                               \
  } while (0)

/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */
static as5048a_status_t m_as5048a_read(as5048a_t *me, uint16_t reg_addr, uint16_t *data);
static uint8_t m_spi_cal_even_parity(uint16_t value);

/* Function definitions ----------------------------------------------- */
as5048a_status_t as5048a_get_raw_rotation(as5048a_t *me, uint16_t *rotation)
{
  return m_as5048a_read(me, AS5048A_ANGLE, rotation);
}

/* Private function definitions---------------------------------------- */
static as5048a_status_t m_as5048a_read(as5048a_t *me, uint16_t reg_addr, uint16_t *P_data)
{
  uint8_t data[2];

  // if ((NULL == me) || (NULL == me->spi_read) || (NULL == me->spi_write))
    // return AS5048A_ERR_PARAM;

  uint16_t command = 0;
  command = command | reg_addr;

  // Add a parity bit on the MSB
  command |= ((uint16_t)m_spi_cal_even_parity(command) << 15);

  // Split the command into two bytes
  data[1] = command & 0xFF;
  data[0] = (command >> 8) & 0xFF;

  CHECK(0 == me->spi_write((uint8_t *)&data, 2, 0xFFFF), AS5048A_ERR_SPI);

  CHECK(0 == me->spi_read((uint8_t *)&data, 2, 0xFFFF), AS5048A_ERR_SPI);

  if (data[1] & 0x40)
  {
    return AS5048A_ERR_SPI;
  }
  
  // Return the data stripping the parity and error bits
  *P_data = (((data[1] & 0xFF) << 8) | (data[0] & 0xFF)) & ~0xC000;

  return AS5048A_OK;
}

static uint8_t m_spi_cal_even_parity(uint16_t value)
{
  uint8_t cnt = 0;
  uint8_t i;

  for (i = 0; i < 16; i++)
  {
    if (value & 0x1)
    {
      cnt++;
    }
    value >>= 1;
  }
  return cnt & 0x1;
}

/* End of file -------------------------------------------------------- */
