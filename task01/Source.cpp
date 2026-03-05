// Source.cpp
#include "Header.h"

bool OpenFile(ifstream& File, const string& filename)
{
    File.open(filename);
    if (!File.is_open())
    {
        // FIX_ME: (использовался cerr, заменено на cout)
        // cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        cout << "Ошибка: Не удалось открыть файл " << filename << endl;
        return false;
    }
    return true;
}

bool SafeReadInt(ifstream& File, int& value)
{
    string line;
    if (getline(File, line))
    {
        istringstream iss(line);
        if (iss >> value)
        {
            return true;
        }
    }
    return false;
}

bool HasEnoughNumbersInLine(ifstream& File, int expectedCount)
{
    string line;
    getline(File, line);
    istringstream iss(line);
    int num, count = 0;
    while (iss >> num)
    {
        count++;
    }
    if (count != expectedCount)
    {
        cout << "Ошибка: Ожидалось " << expectedCount << " чисел, но найдено " << count << endl;
        return false;
    }
    return true;
}

void CheckExtraCharacters(ifstream& File)
{
    string extra;
    if (File >> extra)
    {
        cout << "Предупреждение: В файле есть лишние данные: " << extra << endl;
    }
}