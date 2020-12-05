

#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#define NUM_OF_TESTS 100
#define M_PI 3.14
class AstroidTest : public ::testing::Test
{
protected:
    Astroid* ast;
    void SetUp() override {
         ast = new Astroid;
    }
    void TearDown() override {
        delete ast;
    }
};

TEST_F(AstroidTest, default_constr) {

    EXPECT_DOUBLE_EQ(1, ast->get_r());
    EXPECT_DOUBLE_EQ(1, ast->get_x0());

}
TEST_F(AstroidTest, custom_constr)
{
    for (int i = 0; i < NUM_OF_TESTS; i++)
    {
        Astroid ast(i);

        EXPECT_DOUBLE_EQ(i, ast.get_r());
        int temp1 = pow(i, 0.67) * 100;
        int temp2= ast.get_x0() * 100;
        EXPECT_DOUBLE_EQ(temp1, temp2);
    }
}
TEST_F(AstroidTest, set_r_throw)
{
    for (int i = -NUM_OF_TESTS; i < 0; i++)
    {
        
        EXPECT_THROW(ast->set_r(i), char*);
       
    }
}
TEST_F(AstroidTest, get_length_0_t)
{
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = 0; j < M_PI / 2; j += 0.1)
        {
            float temp = 1.5 * i * pow(sin(j), 2);
            EXPECT_DOUBLE_EQ(temp, ast.get_length_0_t(j));
        }
    }
}
TEST_F(AstroidTest, get_length_0_t_throw)
{
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = -NUM_OF_TESTS/2; j < 0; j += 0.1)
        {
            
            EXPECT_THROW(ast.get_length_0_t(j), char*);
        }
        for (float j = M_PI/2; j < NUM_OF_TESTS/2; j += 0.1)
        {

            EXPECT_THROW(ast.get_length_0_t(j), char*);
        }
    }
}
TEST_F(AstroidTest, get_radius) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = 0; j < M_PI / 2; j += 0.1)
        {
            float temp = 1.5 * i * sin(2 * j);
            EXPECT_DOUBLE_EQ(temp, ast.get_radius(j));
        }
    }
}
TEST_F(AstroidTest, get_radius_throw) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = -NUM_OF_TESTS / 2; j < 0; j += 0.1)
        {

            EXPECT_THROW(ast.get_radius(j), char*);
        }
        for (float j = M_PI / 2; j < NUM_OF_TESTS / 2; j += 0.1)
        {

            EXPECT_THROW(ast.get_radius(j), char*);
        }
    }
}
TEST_F(AstroidTest, get_x_from_t) {
    
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = 0; j < M_PI / 2; j += 0.1)
        {
            float temp = i * pow(cos(j), 3);
            EXPECT_DOUBLE_EQ(temp, ast.get_x_from_t(j));
        }
    }
}
TEST_F(AstroidTest, get_x_from_t_throw) {

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = -NUM_OF_TESTS / 2; j < 0; j += 0.1)
        {

            EXPECT_THROW(ast.get_x_from_t(j), char*);
        }
        for (float j = M_PI / 2; j < NUM_OF_TESTS / 2; j += 0.1)
        {

            EXPECT_THROW(ast.get_x_from_t(j), char*);
        }
    }
}
TEST_F(AstroidTest, get_y_from_t) {

    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = 0; j < M_PI / 2; j += 0.1)
        {
            float temp = i * pow(sin(j), 3);
            EXPECT_DOUBLE_EQ(temp, ast.get_y_from_t(j));
        }
    }
}
TEST_F(AstroidTest, get_y_from_t_throw) {

    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        for (float j = -NUM_OF_TESTS / 2; j < 0; j += 0.1)
        {

            EXPECT_THROW(ast.get_y_from_t(j), char*);
        }
        for (float j = M_PI / 2; j < NUM_OF_TESTS / 2; j += 0.1)
        {

            EXPECT_THROW(ast.get_y_from_t(j), char*);
        }
    }
}
TEST_F(AstroidTest, get_s) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        float m = pow(i, 2);
        float s = 0.375 * M_PI * m;
        EXPECT_DOUBLE_EQ(ast.get_s(), s);
    }
}
TEST_F(AstroidTest, get_x0) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);
        
        float temp = (pow(i, 0.67));

        EXPECT_DOUBLE_EQ(ast.get_x0(), temp);
    }
}
TEST_F(AstroidTest, get_y_from_x) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);

        for (int x = -ast.get_x0(); x < ast.get_x0(); x += 1) {
            float temp = pow(i, 0.67) - pow(abs(x), 0.67);
            float y = pow(abs(temp), 1.5);
            EXPECT_DOUBLE_EQ(y, ast.get_y_from_x(x));
        }
    }
}
TEST_F(AstroidTest, get_y_from_x_throw) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
        Astroid ast(i);

        
        for (int x = -NUM_OF_TESTS / 2; x< -ast.get_x0()-1; x += 1)
        {

            EXPECT_THROW(ast.get_y_from_x(x), char*);
        }
        for (int x = ast.get_x0()+1; x < NUM_OF_TESTS/2; x += 1)
        {

            EXPECT_THROW(ast.get_y_from_x(x), char*);
        }
    }
}
TEST_F(AstroidTest, set_r) {
    for (int i = 1; i < NUM_OF_TESTS; i++) {
    
        ast->set_r(i);
        EXPECT_DOUBLE_EQ(i, ast->get_r());
    
    }
}
