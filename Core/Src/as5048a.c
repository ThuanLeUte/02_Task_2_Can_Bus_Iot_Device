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

#define AS5048A_MAX_VALUE                    (8191.0)

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
as5048a_status_t as5048a_get_rotation_in_degrees(as5048a_t *me, float *degrees)
{
  uint16_t rotation = 0;

  AS_CHECK(as5048a_get_rotation(me, &rotation));

  *degrees = 360.0 * (rotation + AS5048A_MAX_VALUE) / (AS5048A_MAX_VALUE * 2.0);

  return AS5048A_OK;
}

as5048a_status_t as5048a_get_rotation(as5048a_t *me, uint16_t *rotation)
{
  uint16_t raw_rotation = 0;

  AS_CHECK(as5048a_get_raw_rotation(me, &raw_rotation));

  *rotation = (uint16_t) raw_rotation - (uint16_t) me->position;
  if (*rotation > AS5048A_MAX_VALUE)
  {
    *rotation = -((0x3FFF) - *rotation);
  }

  return AS5048A_OK;
}

as5048a_status_t as5048a_get_raw_rotation(as5048a_t *me, uint16_t *rotation)
{
  return m_as5048a_read(me, AS5048A_ANGLE, rotation);
}

void as5048a_set_zero_position(as5048a_t *me, uint16_t position)
{
  me->position = position % 0x3FFF;
}

void as5048a_get_zero_position(as5048a_t *me, uint16_t *position)
{
  *position = me->position;
}

/* Private function definitions---------------------------------------- */
/**
 * @brief         AS5024A read register
 *
 * @param[in]     me        Pointer to as5048a structure
 * @param[in]     reg_addr  Register address
 * @param[in]     p_date    Pointer to data
 * 
 * @attention     None
 *
 * @return        AS5048A_OK
 * @return        AS5048A_ERR_SPI
 */
static as5048a_status_t m_as5048a_read(as5048a_t *me, uint16_t reg_addr, uint16_t *p_data)
{
  uint8_t data[2];
  uint16_t command = 0x4000; // PAR=0 R/W=R;

  if ((NULL == me) || (NULL == me->spi_read) || (NULL == me->spi_write))
    return AS5048A_ERR_PARAM;

  command = command | reg_addr;

  // Add a parity bit on the MSB
  command |= ((uint16_t)m_spi_cal_even_parity(command) << 15);

  // Split the command into two bytes
  data[1] = command & 0xFF;
  data[0] = (command >> 8) & 0xFF;

  CHECK(0 == me->spi_write((uint8_t *)&data, 2, 0xFFFF), AS5048A_ERR_SPI);

  CHECK(0 == me->spi_read((uint8_t *)&data, 2, 0xFFFF), AS5048A_ERR_SPI);

  // Check if error bit is set
  if (data[1] & 0x40)
  {
    return AS5048A_ERR_SPI;
  }

  // Return the data stripping the parity and error bits
  *p_data = (((data[1] & 0xFF) << 8) | (data[0] & 0xFF)) & ~0xC000;

  return AS5048A_OK;
}

/**
 * @brief         Spi calculate even parity
 *
 * @param[in]     value    Input value
 * 
 * @attention     None
 *
 * @return        Parity value
 */
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
