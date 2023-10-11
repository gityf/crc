#ifndef _CRC_CRC32_H
#define _CRC_CRC32_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#include <stddef.h>
#include <stdint.h>

uint32_t crc32(const unsigned char *s, size_t len);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif
