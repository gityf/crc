#ifndef _CRC_CRC_POLY_H
#define _CRC_CRC_POLY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

// LSB-first
uint8_t crc8_poly_lsb(uint8_t poly, uint8_t value);

// MSB-first
uint8_t crc8_poly_msb(uint8_t poly, uint8_t value);

// LSB-first
uint16_t crc16_poly_lsb(uint16_t poly, uint16_t value);

// MSB-first
uint16_t crc16_poly_msb(uint16_t poly, uint16_t value);

// LSB-first
uint32_t crc32_poly(uint32_t poly, uint16_t value);

// LSB-first
uint64_t crc64_poly(uint64_t poly, uint16_t value);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif // _CRC_CRC_POLY_H
