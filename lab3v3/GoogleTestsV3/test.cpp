#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#include <set>
#define NUM_OF_TESTS 100

class SeqTest : public ::testing::Test
{
protected:
    Sequence* seq;
    void SetUp() override {
        seq = new  Sequence;
    }
    void TearDown() override {
        delete seq;

    }
};

TEST_F(SeqTest, default_constr) {

    EXPECT_DOUBLE_EQ(0, seq->get_length());

}
TEST_F(SeqTest, one_el_constr) {

    for (int i = 0; i < NUM_OF_TESTS; i++)
    {

        Sequence* seq1 = new Sequence(i);
        EXPECT_DOUBLE_EQ(1, seq1->get_length());
        EXPECT_DOUBLE_EQ(i, seq1->get_el(0));
        delete seq1;
    }

}
TEST_F(SeqTest, custom_constr) {
    int arr[NUM_OF_TESTS];
    for (int i = 0; i < NUM_OF_TESTS; i++)
    {
        arr[i] = i;
        Sequence* seq1 = new Sequence(i + 1, arr);
        EXPECT_DOUBLE_EQ(i, seq1->get_el(i));
        EXPECT_DOUBLE_EQ(i + 1, seq1->get_length());
        delete seq1;

    }
}



TEST_F(SeqTest, add_el) {
    
    for (int i = 0; i < NUM_OF_TESTS; i++)
    {   
        seq->add_el(i);
        EXPECT_EQ(seq->get_el(i), i);
    }
    
}

TEST_F(SeqTest, get_el) {
    for (int i = 0; i < NUM_OF_TESTS; i++)
    {
        seq->add_el(i);

        EXPECT_EQ(seq->get_el(i), i);
    }

}
TEST_F(SeqTest, uniq) {
    int arr[NUM_OF_TESTS];
    Sequence* seq1;
    std::set <int>* st;
    for (int i = 0; i < NUM_OF_TESTS / 2; i++)
    {
        st = new std::set<int>;
        arr[i] = i;
        seq1 = new Sequence(i + 1, arr);
        for (int j = 0; j < i + 1; j++)
        {
            st->insert(arr[i]);

        }
        EXPECT_DOUBLE_EQ(st->size() - 1, seq->uniq());
        delete st;
        delete seq1;
    }

}
TEST_F(SeqTest, unite) {
    int arr[NUM_OF_TESTS];
    int temp_arr[NUM_OF_TESTS];
    Sequence* seq1;

    Sequence* seq2;

    Sequence* seq3;
    for (int i = 0; i < NUM_OF_TESTS / 2; i++)
    {
        int temp_arr[NUM_OF_TESTS];

        arr[i] = i;
        seq1 = new Sequence(i + 1, arr);
        seq2 = new Sequence(i + 1, arr);

        seq3 = seq1->unite(seq2);
        for (int j = 0; j < i + 1; j++) {
            temp_arr[j] = arr[j];
        }
        for (int j = 0; j < i + 1; j++) {
            temp_arr[i + j + 1] = arr[j];
        }
        for (int j = 0; j < 2 * i; j++) {
            EXPECT_EQ(seq3->get_el(j), temp_arr[j]);
        }

        delete seq1;
        delete seq2;


    }
    
}