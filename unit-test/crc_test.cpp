/*
** The crc unit test is licensed under the Apache License, Version 2.0, and a copy of the license is included in this file.
**
**Author:Wang Yaofu 2018 voipman@qq.com
**Description: The unit test file of crc.
*/

#include "ut/test_harness.h"
#include "../crc/crc8.h"
#include "../crc/crc16.h"
#include "../crc/crc32.h"
#include "../crc/crc64.h"
#include "../crc/crc_poly.h"
#include <iostream>
#include <string.h>

TEST(CRC8Test, BasicTest)
{
    const char* inData = "123456789";
    uint8_t expect = 0xa2;
    EXPECT_EQ(crc8_msb(inData, 9), expect);

    const char* data = "Hello World!!!";
    expect = 0x68;
    EXPECT_EQ(crc8_msb(data, strlen(data)), expect);

    expect = 0x2c;
    EXPECT_EQ(crc8_lsb(data, strlen(data)), expect);
}

TEST(CRC16Test, BasicTest)
{
    const char* inData = "123456789";
    uint16_t expect = 0x31C3;

    EXPECT_EQ(crc16(inData, 9), expect);
}

TEST(CRC32Test, BasicTest)
{
    const char* inData = "123456789";
    uint32_t expect = 0xCBF43926;

    EXPECT_EQ(crc32(inData, 9), expect);
}

TEST(CRC64Test, BasicTest)
{
    const char* inData = "123456789";

    uint64_t expect = 0xe9c6d914c4b8d9caL;
    EXPECT_EQ(crc64(inData, 9), expect);
}

TEST(CRC8PolyTest, BasicTest)
{
    uint8_t poly = 0x31;
    uint8_t crcTab[0xFF+1] = {0};
    uint8_t expect = 0x00;
    EXPECT_EQ(crc8_poly_msb(poly, 0), expect);
    expect = 0x31;
    EXPECT_EQ(crc8_poly_msb(poly, 1), expect);
    expect = 0xac;
    EXPECT_EQ(crc8_poly_msb(poly, 0xFF), expect);

    /**
    for (int i = 0; i <= 0xff; ++i) {
        if (i % 8 == 0) {
            printf("\n");
        }
        crcTab[i] = crc8_poly_lsb(poly, i);
        printf("0x%.2x, ", crcTab[i]);
    }
     */
}

TEST(CRC16PolyTest, BasicTest)
{
    // poly = x^16 + x^12 + x^5 + 1 = 0x1021
    uint16_t poly = 0x1021;
    uint16_t crcTab[0xFF+1] = {0};
    uint16_t expect = 0x0000;
    EXPECT_EQ(crc16_poly_msb(poly, 0), expect);
    expect = 0x1021;
    EXPECT_EQ(crc16_poly_msb(poly, 1), expect);
    expect = 0x1ef0;
    EXPECT_EQ(crc16_poly_msb(poly, 0xFF), expect);
}

TEST(CRC32PolyTest, BasicTest)
{
    uint32_t poly = 0xedb88320;
    uint32_t crcTab[0xFF+1] = {0};
    uint32_t expect = 0x00000000L;
    EXPECT_EQ(crc32_poly(poly, 0), expect);
    expect = 0x77073096L;
    EXPECT_EQ(crc32_poly(poly, 1), expect);
    expect = 0x2d02ef8dL;
    EXPECT_EQ(crc32_poly(poly, 0xFF), expect);
}

