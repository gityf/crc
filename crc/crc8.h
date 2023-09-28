#ifndef _CRC_CRC8_H
#define _CRC_CRC8_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#include <stdint.h>

// LSB-first
uint8_t crc8_lsb(const unsigned char *buf, size_t len);

// MSB-first
uint8_t crc8_msb(const unsigned char *buf, size_t len);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif
