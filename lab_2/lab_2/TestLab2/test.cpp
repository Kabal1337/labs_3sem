#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>

class AstroidTest : public ::testing::Test
{
protected:
    Astroid* nik;
    void SetUp() override {
       nik = new Astroid;
    }
    void TearDown() override {
        delete nik;
    }
};

TEST(AstroidTest, TestName) {
    Astroid* ast = new Astroid;
	EXPECT_EQ(1, 1);
	

}