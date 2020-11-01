#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>

class AstroidTest : public ::testing::Test
{
protected:
    Astroid* ast;
    void SetUp() override {
        Astroid* ast = new Astroid;
    }
    void TearDown() override {
        delete ast;
    }
};

TEST_F(AstroidTest, TestName) {
    
	EXPECT_DOUBLE_EQ(1, ast->get_r());
	

}