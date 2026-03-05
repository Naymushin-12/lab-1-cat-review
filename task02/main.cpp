// main.cpp
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream fin;
    ofstream fout;

    // FIX_ME: (имена файлов изменены с "a.txt" и "b.txt" на "A.txt" и "B.txt")
    if (!OpenFiles(fin, fout, "A.txt", "B.txt"))
    {
        return 1;
    }

    // FIX_ME: (прямое чтение N без проверки заменено на функцию ReadAndCheckN)
    int N = ReadAndCheckN(fin);
    if (N == -1)
    {
        return 1;
    }

    // FIX_ME: (отсутствовала проверка размеров доски)
    if (!CheckBoardDimensions(fin, N))
    {
        return 1;
    }

    fin.clear();
    fin.seekg(0, ios::beg);
    fin >> N; // Повторное чтение N для позиционирования

    // FIX_ME: (переименовано docka на board)
    vector<vector<int>> board(N, vector<int>(N));

    // FIX_ME: (прямое чтение доски заменено на функцию с проверкой)
    if (!ReadAndCheckBoard(fin, board, N))
    {
        return 1;
    }

    // FIX_ME: (отсутствовала проверка на лишние символы)
    CheckExtraCharacters(fin);

    // Динамическое программирование
    vector<vector<int>> dp(N, vector<int>(N));
    dp[N - 1][0] = board[N - 1][0];

    for (int j = 1; j < N; ++j)
    {
        dp[N - 1][j] = dp[N - 1][j - 1] + board[N - 1][j];
    }

    for (int i = N - 2; i >= 0; --i)
    {
        dp[i][0] = dp[i + 1][0] + board[i][0];
    }

    for (int i = N - 2; i >= 0; --i)
    {
        for (int j = 1; j < N; ++j)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + board[i][j];
        }
    }

    int result = dp[0][N - 1];
    fout << result;
    cout << "Минимальная сумма пути: " << result << endl;
    // FIX_ME: (добавлен вывод информации о файле с ответом)
    cout << "Ответ записан в файле B.txt" << endl;

    return 0;
}