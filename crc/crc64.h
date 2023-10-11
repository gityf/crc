#ifndef _CRC_CRC64_H
#define _CRC_CRC64_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

#include <stddef.h>
#include <stdint.h>

uint64_t crc64(const unsigned char *s, size_t l);

#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif
