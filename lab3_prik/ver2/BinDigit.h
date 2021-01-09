#include <ostream>
#ifndef LAB_CPP_BINDIGIT_H
#define LAB_CPP_BINDIGIT_H

class BinDigit
{
public:
    //static const int s_SZ = 6; // длинна (6 цифры + 1 под знак + 1 под \0, т.к строка)
    int m_SZ = 0;
    //конструкторы
    BinDigit(); //по умолчанию
    BinDigit(const char* str_digit); //когда передаем строку
    BinDigit(const BinDigit &digit); //конструктор копирования
    BinDigit(long digit);

    friend std::ostream& operator<< (std::ostream &out, const BinDigit &digit); //вывод
    friend std::istream& operator>> (std::istream &in, BinDigit &digit); //ввод

    friend BinDigit operator+ (const BinDigit &digit_l, const BinDigit &digit_r); //+, если левый операнд экземляр

    BinDigit& operator++(); //версия префикс
    BinDigit& operator--(); //версия префикс

    BinDigit operator++(int); //версия постфикс
    BinDigit operator--(int); //версия постфикс

    BinDigit operator~() const;

    BinDigit& operator= (const BinDigit &digit); //перегрузка оператора присваивания

    void get_digit();
    char* m_digit; // сам массив char'ов
};
int get_sign(const BinDigit &digit);



#endif //LAB_CPP_BINDIGIT_H
//
// Created by kamil on 31.10.2020.
//