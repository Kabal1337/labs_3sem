#include <iostream>
#include "BinDigit.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

int com_num = 0;
int flag = 1;
int flag2 = 1;

std::string temp_str;

char* temp_char_array;

int main()
{
    BinDigit second_digit;
    BinDigit main_digit;
    while(com_num != 9) {
        cout << "1. insert digit" << endl;
        cout << "2. show digit" << endl;
        cout << "3. sum two digits" << endl;
        cout << "4. increment" << endl;
        cout << "5. decrement" << endl;
        cout << "6. show additional code" << endl;
        cout << "7. get sign" << endl;
        cout << "8. get good view of digit" << endl;
        cout << "9. exit" << endl;
        cout << "Введите команду: " << endl;
        cin >> com_num;
        switch(com_num){
            case 1:
                cout << "Введите число (пример: 10000, где 1 - знаковый разряд)" << endl;
                if(flag == 1){
                    //first time!
                    cin >> temp_str;
                    char* temp_char_array = new char(temp_str.length() + 1);
                    for(int i = 0; i < temp_str.length() + 1; i++)
                    {
                        temp_char_array[i] = temp_str[i];
                    }
                    BinDigit temp_digit(temp_char_array);
                    try{
                        main_digit = temp_digit;
                    }catch(std::range_error &ex){
                        cout << ex.what() << endl;
                        return 0;
                    }
                    flag = 0;
                }else{
                    cin >> main_digit;
                }
                break;
            case 2:
                cout << "Вот число которые было введено: " << main_digit << endl;
                break;
            case 3:
                cout << "Введите второе число с которым будем складывать: ";
                if(flag2 == 1){
                    //first time!
                    cin >> temp_str;
                    char* temp_char_array = new char(temp_str.length() + 1);
                    for(int i = 0; i < temp_str.length() + 1; i++)
                    {
                        temp_char_array[i] = temp_str[i];
                    }
                    BinDigit temp_digit(temp_char_array);
                    second_digit = temp_digit;
                    flag = 0;
                }else{
                    cin >> second_digit;
                }
                try{
                    cout << "Сумма чисел: " << main_digit + second_digit << endl;
                }catch(std::range_error &ex){
                    cout << endl << ex.what() << endl;
                    return 0;
                }
                break;
            case 4:
                cout << "Число увеличенное на 1: " << ++main_digit << endl;
                break;
            case 5:
                cout << "Число уменьшенное на 1: " << --main_digit << endl;
                break;
            case 6:
                cout << "ДК: " << ~main_digit << endl;
                break;
            case 7:
                if(get_sign(main_digit) == 1){
                    cout << "Знак числа: -" << endl;
                }else{
                    cout << "Знак числа: +" << endl;
                }
                break;
            case 8:
                main_digit.get_digit();
                break;
            case 9:
                return 0;
            default:
                cout << "Нет такой команды!" << endl;
                break;
        }
    }


    return 0;
}


//
// Created by kamil on 31.10.2020.
//

