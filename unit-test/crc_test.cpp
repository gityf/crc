/*
** Copyright (C) 2018 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The unit test file of crc.
*/

#include "ut/test_harness.h"
#include "../crc/crc16.h"
#include "../crc/crc32.h"
#include "../crc/crc64.h"
#include <iostream>

TEST(CRC16Test, BasicTest)
{
    const char* inData = "123456789";
    uint16_t expect = 0x31C3;

    EXPECT_EQ(crc16(inData, 9), expect);
}

TEST(CRC32Test, BasicTest)
{
    const char* inData = "123456789";
    uint32_t expect = 3421780262 ;

    EXPECT_EQ(crc32(inData, 9), expect);
}

TEST(CRC64Test, BasicTest)
{
    const char* inData = "123456789";

    uint64_t expect = 16845390139448941002L;
    EXPECT_EQ(crc64(inData, 9), expect);
}