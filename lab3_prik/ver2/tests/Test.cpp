#include "gtest/gtest.h"
#include "../BinDigit.h"

TEST(BinDigitConstructor, Constructor){
    BinDigit digit("0001");
    EXPECT_TRUE(0 == memcmp("0001", digit.m_digit, strlen(digit.m_digit) + 1));
    BinDigit digit2 (digit);
    EXPECT_TRUE(0 == memcmp("0001", digit2.m_digit, strlen(digit2.m_digit) + 1));
    BinDigit digit3(54);
    EXPECT_TRUE(0 == memcmp("000110110", digit3.m_digit, strlen(digit3.m_digit) + 1));
    BinDigit digit4(-54);
    EXPECT_TRUE(0 == memcmp("100110110", digit4.m_digit, strlen(digit4.m_digit) + 1));
}

TEST(BinDigitMethods, TestException){
    ASSERT_ANY_THROW(BinDigit digit("5001"));
    BinDigit digit1("0001");
    BinDigit digit2("00001");
    ASSERT_ANY_THROW(digit2 + digit1);
    BinDigit digit3("1111");
    BinDigit digit4("0001");
    ASSERT_ANY_THROW(digit3 + digit4);
//    ASSERT_ANY_THROW(std::cin >> digit);
}

TEST(BinDigitMethods, Parameters){
    BinDigit digit1("0001");
    digit1++;
    EXPECT_TRUE(0 == memcmp("0010", digit1.m_digit, strlen(digit1.m_digit) + 1));
//    digit1--;
//    ASSERT_TRUE(0 == memcmp("0001", digit1.m_digit, strlen(digit1.m_digit) + 1));
    BinDigit digit2 = ~digit1;
    EXPECT_TRUE(0 == memcmp("0010", digit2.m_digit, strlen(digit2.m_digit) + 1));
    EXPECT_EQ(0, get_sign(digit2));
}




//
// Created by kamil on 09.11.2020.
//

