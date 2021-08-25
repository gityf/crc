#ifndef _CRC_CRC8_H
#define _CRC_CRC8_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

// LSB-first
uint8_t crc8_lsb(const char *buf, int len);

// MSB-first
uint8_t crc8_msb(const char *buf, int len);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif
