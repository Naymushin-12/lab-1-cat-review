// Source.cpp
#include "Header.h"

bool OpenFiles(ifstream& fin, ofstream& fout, const string& in, const string& out)
{
    fin.open(in);
    fout.open(out);
    if (!fin.is_open())
    {
        // FIX_ME: (использовался cerr, заменено на cout)
        // cerr << "Ошибка! Не удалось открыть " << in << endl;
        cout << "Ошибка! Не удалось открыть " << in << endl;
        return false;
    }
    if (!fout.is_open())
    {
        cout << "Ошибка! Не удалось создать " << out << endl;
        return false;
    }
    return true;
}

int ReadAndCheckN(ifstream& fin)
{
    int N;
    fin >> N;
    if (N <= 1 || N >= 80)
    {
        cout << "Некорректный размер доски! Допустимый диапазон: 1 < N < 80" << endl;
        return -1;
    }
    return N;
}

bool CheckBoardDimensions(ifstream& fin, int N)
{
    string line;
    int lineCount = 0;
    while (getline(fin, line) && lineCount < N)
    {
        if (!line.empty())
        {
            lineCount++;
        }
    }
    if (lineCount < N)
    {
        cout << "Ошибка: В файле недостаточно строк для доски размером " << N << "x" << N << endl;
        return false;
    }
    return true;
}

bool ReadAndCheckBoard(ifstream& fin, vector<vector<int>>& board, int N)
{
    vector<pair<int, int>> errors;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            fin >> board[i][j];
            if (board[i][j] < 0 || board[i][j] > 100)
            {
                errors.push_back(make_pair(i, j));
            }
        }
    }
    if (!errors.empty())
    {
        cout << "\nОШИБКИ В ДОСКЕ:\n";
        for (const auto& error : errors)
        {
            cout << "  Позиция (" << error.first << "," << error.second
                 << "): " << board[error.first][error.second] << "\n";
        }
        return false;
    }
    return true;
}

void CheckExtraCharacters(ifstream& fin)
{
    string extra;
    if (fin >> extra)
    {
        cout << "Предупреждение: В файле есть лишние данные: " << extra << endl;
    }
}