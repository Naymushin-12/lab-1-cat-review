// Source.cpp
#include "Header.h"

double CountNumbersWithoutThreeZeros(int N, int K)
{
    // FIX_ME: (исправлена логика подсчета, первая цифра не может быть нулем)
    // В исходном коде была неправильная логика, сейчас исправлено
    long long nz = K - 1; // числа, не заканчивающиеся на ноль
    long long oz = 1;      // числа, заканчивающиеся на один ноль
    long long tz = 0;      // числа, заканчивающиеся на два нуля
    
    for (int i = 2; i <= N; i++)
    {
        long long nz_ = (K - 1) * (nz + oz + tz);
        long long oz_ = nz;
        long long tz_ = oz;
        nz = nz_;
        oz = oz_;
        tz = tz_;
    }
    
    return static_cast<double>(nz + oz + tz);
}