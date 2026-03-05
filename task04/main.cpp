// main.cpp
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    
    string expression;
    // FIX_ME: (добавлена информация о допустимых символах)
    cout << "Введите выражение (допустимые символы: цифры, +, -, *): ";
    getline(cin, expression);
    
    // FIX_ME: (добавлена проверка корректности ввода)
    int checkPos = 0;
    if (!ValidateExpression(expression, checkPos) || checkPos < expression.length())
    {
        cout << "Ошибка: Некорректное выражение" << endl;
        return 1;
    }
    
    int pos = 0;
    int result = ParseExpression(expression, pos);
    
    cout << "Результат -> " << result << endl;
    
    return 0;
}