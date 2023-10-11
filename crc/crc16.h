#ifndef _CRC_CRC16_H
#define _CRC_CRC16_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#include <stddef.h>
#include <stdint.h>

uint16_t crc16(const unsigned char *buf, size_t len);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif
