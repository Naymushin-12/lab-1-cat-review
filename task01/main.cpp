// main.cpp
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");

    ifstream File;
    if (!OpenFile(File, "T.txt"))
    {
        return 1;
    }

    int N, Z;
    string skipLine;

    // FIX_ME: (прямое чтение без проверки на ошибки)
    // File >> N >> Z;
    if (!SafeReadInt(File, N) || !SafeReadInt(File, Z))
    {
        cout << "Ошибка: Не удалось прочитать N и Z" << endl;
        return 1;
    }

    // FIX_ME: (отсутствовали проверки на корректность N и Z)
    // В исходном коде не было проверок
    if (N <= 0)
    {
        cout << "Ошибка: N должно быть положительным числом" << endl;
        return 1;
    }
    if (Z < 0)
    {
        cout << "Ошибка: Z должно быть неотрицательным" << endl;
        return 1;
    }

    getline(File, skipLine); // Переход на следующую строку

    vector<int> Weights(N);
    // FIX_ME: (неправильное объявление вектора для налогов - использовалась переменная Z вместо N)
    // vector<int> Taxes(Z);
    vector<int> Taxes(N);

    // FIX_ME: (отсутствовала проверка, что в строке ровно N чисел)
    if (!HasEnoughNumbersInLine(File, N))
    {
        cout << "Ошибка: Недостаточно весов в файле" << endl;
        return 1;
    }
    File.clear();
    File.seekg(0, ios::beg);
    for (int i = 0; i < 2; ++i) getline(File, skipLine); // Пропуск первых двух строк

    for (int i = 0; i < N; ++i)
    {
        File >> Weights[i];
        // FIX_ME: (отсутствовала проверка на отрицательные веса)
        if (Weights[i] < 0)
        {
            cout << "Ошибка: Вес артефакта " << i + 1 << " отрицательный" << endl;
            return 1;
        }
    }

    // FIX_ME: (отсутствовала проверка, что в строке ровно N чисел для налогов)
    if (!HasEnoughNumbersInLine(File, N))
    {
        cout << "Ошибка: Недостаточно налогов в файле" << endl;
        return 1;
    }
    File.clear();
    File.seekg(0, ios::beg);
    for (int i = 0; i < 3; ++i) getline(File, skipLine); // Пропуск первых трех строк

    for (int i = 0; i < N; ++i)
    {
        File >> Taxes[i];
        // FIX_ME: (отсутствовала проверка на отрицательные налоги)
        if (Taxes[i] < 0)
        {
            cout << "Ошибка: Налог артефакта " << i + 1 << " отрицательный" << endl;
            return 1;
        }
    }

    // FIX_ME: (отсутствовала проверка на лишние символы в файле)
    CheckExtraCharacters(File);

    int MaxWeight = 0;
    for (int Weight : Weights)
    {
        MaxWeight += Weight;
    }

    vector<int> MinTax(MaxWeight + 1, numeric_limits<int>::max());
    MinTax[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int w = MaxWeight; w >= Weights[i]; --w)
        {
            if (MinTax[w - Weights[i]] != numeric_limits<int>::max())
            {
                // FIX_ME: (использованы старые названия переменных, хотя в исходном уже исправлено, но оставлю для примера)
                // MinTax[w] = min(MinTax[w], MinTax[w - Weights[i]] + oldTaxName);
                MinTax[w] = min(MinTax[w], MinTax[w - Weights[i]] + Taxes[i]);
            }
        }
    }

    int MinTaxValue = numeric_limits<int>::max();
    int TotalWeight = 0;

    // FIX_ME: (ошибка в условии цикла - должно быть w <= MaxWeight, а не w < MaxWeight)
    // for (int w = Z + 1; w < MaxWeight; ++w)
    for (int w = Z + 1; w <= MaxWeight; ++w)
    {
        if (MinTax[w] < MinTaxValue)
        {
            MinTaxValue = MinTax[w];
            TotalWeight = w;
        }
    }

    if (MinTaxValue == numeric_limits<int>::max())
    {
        cout << "Невозможно набрать вес больше " << Z << " кг" << endl;
        return 1;
    }

    vector<int> SelectedArtifacts;
    int CurrentWeight = TotalWeight;

    for (int i = N - 1; i >= 0; --i)
    {
        if (CurrentWeight >= Weights[i] && MinTax[CurrentWeight] == MinTax[CurrentWeight - Weights[i]] + Taxes[i])
        {
            SelectedArtifacts.push_back(i + 1);
            CurrentWeight -= Weights[i];
        }
    }

    // FIX_ME: (неправильный порядок вывода: сначала индексы, потом вес и ценность)
    // cout << "Индексы артефактов: ";
    // for (int Index : SelectedArtifacts) cout << Index << " ";
    // cout << "\nСуммарный вес: " << TotalWeight << " кг";
    // cout << "\nОбщая ценность: " << MinTaxValue << endl;

    cout << "Суммарный вес: " << TotalWeight << " кг" << endl;
    cout << "Общая ценность: " << MinTaxValue << endl;
    cout << "Индексы артефактов: ";
    for (int i = SelectedArtifacts.size() - 1; i >= 0; --i)
    {
        cout << SelectedArtifacts[i] << " ";
    }
    cout << endl;

    return 0;
}