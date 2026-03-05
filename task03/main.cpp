// main.cpp
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    
    int N, K;
    
    cout << "Введите количество разрядов N (1 < N < 20): ";
    cin >> N;
    
    // FIX_ME: (добавлена проверка ввода для N)
    if (cin.fail() || N <= 1 || N >= 20)
    {
        cout << "Некорректные входные данные для N" << endl;
        return 1;
    }
    
    cout << "Введите систему счисления К (2 <= K <= 10, N + K < 26): ";
    cin >> K;
    
    // FIX_ME: (добавлена проверка ввода для K)
    if (cin.fail() || K < 2 || K > 10 || N + K >= 26)
    {
        cout << "Некорректные значения для K" << endl;
        return 1;
    }

    // FIX_ME: (переименована функция и переменная)
    // double bebe = kichnye(N, K);
    double result = CountNumbersWithoutThreeZeros(N, K);
    cout << "Количество чисел, в которых не содержится более двух подряд идущих нулей: " << result << endl;

    return 0;
}