#include <iostream>
#include <cstring>
#include "BinDigit.h"
#include <string>
 BinDigit::BinDigit(){
//    s_SZ = 3;
//    m_digit = new char(s_SZ);
//    for(int i = 0; i < s_SZ - 1; i++)
//    {
//        m_digit[i] = '0';
//    }
//    m_digit[s_SZ - 1] = '\0';
}

BinDigit::BinDigit(const char* str_digit){
    m_SZ = strlen(str_digit) + 1;
    m_digit = new char(m_SZ);

    for (int i = 0; i < strlen(str_digit); i++) {
        if (str_digit[i] != '0' && str_digit[i] != '1') {
            //std::cout << "Ошибка! Неверный диапазон ввода!" << std::endl;
            throw std::range_error("Invalid sym range!");
            break;
        }
    }

    for(int i = 0; i < m_SZ; i++)
    {
        m_digit[i] = str_digit[i];
    }
    m_digit[m_SZ - 1] = '\0';

}

BinDigit::BinDigit(long digit)
{
    std::string str_digit = std::to_string(digit);

    int count = 0;

    bool is_negative = false;

    for(int i = 0; i < str_digit.length(); i++){
        if(str_digit[i] == '-' || str_digit[i] == '+'){
            if(str_digit[i] == '-') is_negative = true;
            continue;
        }
        count++;
    }

    char* temp_str_digit = new char[count + 1];
    int index = 0;
    for(int i = 0; i < str_digit.length(); i++){
        if(str_digit[i] == '-' || str_digit[i] == '+'){
            if(str_digit[i] == '-') is_negative = true;
            continue;
        }else{
            temp_str_digit[index] = str_digit[i];
            index++;
        }
    }
    temp_str_digit[count] = '\0';


    char* temp_str_bin_digit = new char[(count * 4) + 2];
    index = count * 4;
    int temp_count = 0;
    digit = std::abs(digit);
    while((digit / 2) > 0){
        if((digit % 2) == 0){
            temp_str_bin_digit[index] = '0';
        }else{
            temp_str_bin_digit[index] = '1';
        }
        index--;
        digit = digit / 2;
        temp_count++;
    }
    if((digit % 2) == 0){
        temp_str_bin_digit[index] = '0';
    }else{
        temp_str_bin_digit[index] = '1';
    }
    temp_count++;

    temp_str_bin_digit[(count * 4) + 1] = '\0';
    temp_count++;
    if(is_negative){
        temp_str_bin_digit[0] = '1';
    }else{
        temp_str_bin_digit[0] = '0';
    }
    temp_count++;
    int final_count = (count * 4) + 2 - temp_count;

    for(int i = 1; i <= final_count; i++)
    {
        temp_str_bin_digit[i] = '0';
    }

    m_SZ = strlen(temp_str_bin_digit) + 1;

    m_digit = new char(m_SZ);

    for(int i = 0; i < m_SZ; i++)
    {
        m_digit[i] = temp_str_bin_digit[i];
    }


}

BinDigit::BinDigit(const BinDigit &digit){
    m_SZ = digit.m_SZ;

    if(digit.m_digit)
    {
        m_digit = new char(m_SZ);

        for(int i = 0; i < m_SZ; ++i)
        {
            m_digit[i] = digit.m_digit[i];
        }
    }else m_digit = 0;
}

std::ostream& operator<< (std::ostream &out, const BinDigit &digit)
{
    out << digit.m_digit;
    return out;
}

std::istream& operator>> (std::istream &in, BinDigit &digit) {
    int flag = 0;
    std::string input_digit;
    std::cin >> input_digit;
        for (int i = 0; i < input_digit.length(); i++) {
            if (input_digit[i] != '0' && input_digit[i] != '1') {
                //std::cout << "Ошибка! Неверный диапазон ввода!" << std::endl;
                throw std::range_error("Invalid sym range!");
                break;
            } else {
                flag++;
            }
        }
        if (flag == input_digit.length()) {
            //std::cout << "Успешный ввод!";
            for (int i = 0; i < input_digit.length(); i++) {
                digit.m_digit[i] = input_digit[i];
            }
            digit.m_digit[input_digit.length()] = '\0';
        }
    digit.m_SZ = input_digit.length() + 1;
    return in;
}

BinDigit& BinDigit::operator++(){
    BinDigit temp1(m_digit);
    char* temp_one = new char[m_SZ];
    temp_one[0] = '0';
    for(int i = 1; i < m_SZ - 2; i++)
    {
        temp_one[i] = '0';
    }
    temp_one[m_SZ - 2] = '1';
    temp_one[m_SZ - 1] = '\0';
    BinDigit temp2(temp_one);
    char* sum;
    sum = (temp1 + temp2).m_digit;
    for(int i = 0; i < m_SZ; i++){
        m_digit[i] = sum[i];
    }

    return *this;
}

BinDigit BinDigit::operator++(int){
    BinDigit temp(m_digit);
    ++(*this);
    return temp;
}

BinDigit& BinDigit::operator--(){
    BinDigit temp1(m_digit);
    char* temp_one = new char[m_SZ];
    temp_one[0] = '1';
    for(int i = 1; i < m_SZ - 2; i++)
    {
        temp_one[i] = '0';
    }
    temp_one[m_SZ - 2] = '1';
    temp_one[m_SZ - 1] = '\0';
    BinDigit temp2(temp_one);
    char* sum;
    sum = (temp1 + temp2).m_digit;
    for(int i = 0; i < m_SZ; i++){
        m_digit[i] = sum[i];
    }

    return *this;
}

BinDigit BinDigit::operator--(int){
    BinDigit temp(m_digit);
    --(*this);
    return temp;
}



BinDigit BinDigit::operator~() const{
    if(m_digit[0] == '0'){
        return BinDigit(m_digit);
    }else if(m_digit[0] == '1'){
        char* m_c_digit = new char[m_SZ];
        m_c_digit[0] = '1';
        for(int i = 1; i < m_SZ - 1; i++)
        {
            if(m_digit[i] == '0')
            {
                m_c_digit[i] = '1';
            }else{
                m_c_digit[i] = '0';
            }

        }
        m_c_digit[m_SZ - 1] = '\0';
        int cur_sum_dis = 0;
        char mind_remains = '0';
        int i_mind_remains = 0;

        for(int i = m_SZ - 2; i >= 0  - 1; i--)
        {
            i_mind_remains = mind_remains - '0';
            if(i == m_SZ - 2){
                cur_sum_dis = 1 + m_c_digit[i] - '0';
            }else{
                cur_sum_dis = i_mind_remains + m_c_digit[i] - '0';
            }

            if(cur_sum_dis == 1){
                m_c_digit[i] = '1';
                break;
            }else{
                m_c_digit[i] = '0';
                mind_remains = '1';
            }
            cur_sum_dis = 0;
        }
        BinDigit temp(m_c_digit);
        return temp;
    }
}

BinDigit operator+(const BinDigit &digit_l, const BinDigit &digit_r) {
    int cur_sum_dis = 0;
    char mind_remains = '0';
    int i_mind_remains = 0;
    int count = strlen(digit_l.m_digit) + 1;
    char* sum_digit = new char[count];
    int index = count - 2;

    if(strlen(digit_l.m_digit) + 1 != strlen(digit_r.m_digit) + 1)
    {
        //std::cout << "Длинны не совпадают! Не буду складывать!" << std::endl;
        throw std::range_error("The lengths don't match!");
    }

    char* l_digit;
    char* r_digit;

    if(digit_l.m_digit[0] == '1'){
        l_digit = (~digit_l).m_digit;
    }else{
        l_digit = (char*) digit_l.m_digit;
    }

    if(digit_r.m_digit[0] == '1'){
        r_digit = (~digit_r).m_digit;
    }else{
        r_digit = (char*) digit_r.m_digit;
    }


    for(int j = count - 2; j >= 0; j--)
    {
        i_mind_remains = mind_remains - '0';

        cur_sum_dis = i_mind_remains + (l_digit[j] - '0') + (r_digit[j] - '0');

        switch (cur_sum_dis) {
            case 0:
                mind_remains = '0';
                sum_digit[index] = '0';
                break;
            case 1:
                mind_remains = '0';
                sum_digit[index] = '1';
                break;
            case 2:
                mind_remains = '1';
                sum_digit[index] = '0';
                break;
            case 3:
                mind_remains = '1';
                sum_digit[index] = '1';
                break;
        }
        if(j == 0 && cur_sum_dis != 0){
            //throw std::range_error("Overload!");
        }
        index--;
        cur_sum_dis = 0;
    }

    sum_digit[count - 1] = '\0';

    BinDigit temp(sum_digit);
    return ~temp;
    //printf("%s", sum_digit);
}

int get_sign(const BinDigit &digit)
{
    if(digit.m_digit[0] == '1'){
        return 1;
    }else{
        return 0;
    }
}

void BinDigit::get_digit() {
    for(int i = 0; i < m_SZ; i++){
        if(i == 0) printf("%c.", m_digit[i]);
        else printf("%c", m_digit[i]);
    }
    printf("\n");
}

BinDigit& BinDigit::operator= (const BinDigit &digit){
    if(this == &digit) return *this;

    //delete[] m_digit;

    m_SZ = digit.m_SZ;

    if(digit.m_digit)
    {
        m_digit = new char[m_SZ];

        for(int i = 0; i < m_SZ; ++i)
        {
            m_digit[i] = digit.m_digit[i];
        }
    }else m_digit = 0;

    return *this;
}



//
// Created by kamil on 31.10.2020.
//
