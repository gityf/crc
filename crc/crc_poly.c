/*
** The crc is licensed under the Apache License, Version 2.0, and a copy of the license is included in this file.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The source file to calc crc poly.
*/
#include <stdlib.h>
#include "crc_poly.h"

// LSB-first
uint8_t crc8_poly_lsb(uint8_t poly, uint8_t value) {
    uint8_t crc;
    uint8_t j;

    crc = value & 0xFF;
    for (j = 8; j > 0; --j) {
        if (crc & 1) {
            crc = (crc >> 1) ^ poly;
        } else {
            crc = crc >> 1;
        }
    }
    return crc;
}

uint8_t crc8_poly_msb(uint8_t poly, uint8_t value) {
    uint8_t crc;
    uint8_t j;
    uint8_t mask = 0x80;

    crc = value & 0xFF;
    for (j = 8; j > 0; --j) {
        if (crc & mask) {
            crc = (crc << 1) ^ poly;
        } else {
            crc = crc << 1;
        }
    }
    return crc;
}

// LSB-first
uint16_t crc16_poly_lsb(uint16_t poly, uint16_t value) {
    uint16_t crc;
    uint16_t j;

    crc = value & 0xFF;
    for (j = 16; j > 0; --j) {
        if (crc & 1) {
            crc = (crc >> 1) ^ poly;
        } else {
            crc = crc >> 1;
        }
    }
    return crc;
}

// msb first
uint16_t crc16_poly_msb(uint16_t poly, uint16_t value) {
    uint16_t crc;
    uint16_t j;

    crc = value & 0xFF;
    for (j = 16; j > 0; --j) {
        if (crc & 0x8000) {
            crc = (crc << 1) ^ poly;
        } else {
            crc = crc << 1;
        }
    }
    return crc;
}

// LSB-first
uint32_t crc32_poly(uint32_t poly, uint16_t value) {
    uint32_t crc;
    uint16_t j;

    crc = value & 0xFF;
    for (j = 8; j > 0; --j) {
        if (crc & 1) {
            crc = (crc >> 1) ^ poly;
        } else {
            crc = crc >> 1;
        }
    }
    return crc;
}

// LSB-first
uint64_t crc64_poly(uint64_t poly, uint16_t value) {
    uint64_t crc;
    uint16_t j;

    crc = value & 0xFF;
    for (j = 8; j > 0; --j) {
        if (crc & 1) {
            crc = (crc >> 1) ^ poly;
        } else {
            crc = (crc >> 1);
        }
    }
    return crc;
}
