# Task01
## Основные изменения:
1. **Разделение на модули**:
   - Код разбит на Header.h, Source.cpp, main.cpp

2. **Исправления в main.cpp**:
   - FIX_ME: Прямое чтение N и Z без проверки
     - Старое: `File >> N >> Z;`
     - Новое: `if (!SafeReadInt(File, N) || !SafeReadInt(File, Z))`
   - FIX_ME: Отсутствие проверки N > 0 и Z >= 0
     - Добавлены проверки
   - FIX_ME: Неправильное объявление вектора для налогов (использовалась Z вместо N)
     - Старое: `vector<int> Taxes(Z);`
     - Новое: `vector<int> Taxes(N);`
   - FIX_ME: Отсутствие проверки на количество чисел в строках
     - Добавлена функция `HasEnoughNumbersInLine`
   - FIX_ME: Отсутствие проверки на отрицательные веса и налоги
     - Добавлены проверки
   - FIX_ME: Отсутствие проверки на лишние символы в файле
     - Добавлена функция `CheckExtraCharacters`
   - FIX_ME: Ошибка в условии цикла поиска минимального налога
     - Старое: `for (int w = Z + 1; w < MaxWeight; ++w)`
     - Новое: `for (int w = Z + 1; w <= MaxWeight; ++w)`
   - FIX_ME: Неправильный порядок вывода
     - Старое: сначала индексы, потом вес и ценность
     - Новое: сначала вес и ценность, потом индексы

3. **Исправления в Source.cpp**:
   - FIX_ME: Использование cerr вместо cout
     - Все cerr заменены на cout
    
# Task02
## Основные изменения:
1. **Разделение на модули**:
   - Код разбит на Header.h, Source.cpp, main.cpp

2. **Исправления в main.cpp**:
   - FIX_ME: Имена файлов изменены с a.txt и b.txt на A.txt и B.txt
     - Старое: `ifstream fin("input.txt"); ofstream fout("output.txt");`
     - Новое: `OpenFiles(fin, fout, "A.txt", "B.txt")`
   - FIX_ME: Прямое чтение N без проверки
     - Старое: `fin >> n;`
     - Новое: `int N = ReadAndCheckN(fin);`
   - FIX_ME: Отсутствие проверки размеров доски
     - Добавлена функция `CheckBoardDimensions`
   - FIX_ME: Переименование docka на board
     - Старое: `vector<vector<int>> docka(n, vector<int>(n));`
     - Новое: `vector<vector<int>> board(N, vector<int>(N));`
   - FIX_ME: Прямое чтение доски без проверки значений
     - Старое: `fin >> board[i][j];`
     - Новое: вызов `ReadAndCheckBoard`
   - FIX_ME: Отсутствие проверки на лишние символы
     - Добавлена функция `CheckExtraCharacters`
   - FIX_ME: Отсутствие информации о файле с ответом
     - Добавлено: `cout << "Ответ записан в файле B.txt" << endl;`

3. **Исправления в Source.cpp**:
   - FIX_ME: Использование cerr вместо cout
     - Все cerr заменены на cout
    
# Task03
## Основные изменения:
1. **Разделение на модули**:
   - Код разбит на Header.h, Source.cpp, main.cpp

2. **Исправления в main.cpp**:
   - FIX_ME: Отсутствие проверки ввода для N
     - Добавлена проверка `if (cin.fail() || N <= 1 || N >= 20)`
   - FIX_ME: Отсутствие проверки ввода для K
     - Добавлена проверка `if (cin.fail() || K < 2 || K > 10 || N + K >= 26)`
   - FIX_ME: Переименование функции и переменной
     - Старое: `double bebe = kichnye(N, K);`
     - Новое: `double result = CountNumbersWithoutThreeZeros(N, K);`

3. **Исправления в Source.cpp**:
   - FIX_ME: Исправлена логика подсчета (первая цифра не может быть нулем)
     - В исходном коде была неверная формула
     - Новая формула учитывает ограничение на первую цифру
    
# Task04
## Основные изменения:
1. **Разделение на модули**:
   - Код разбит на Header.h, Source.cpp, main.cpp

2. **Исправления в main.cpp**:
   - FIX_ME: Добавлена информация о допустимых символах
     - Старое: `cout << "Введите выражение -> ";`
     - Новое: `cout << "Введите выражение (допустимые символы: цифры, +, -, *): ";`
   - FIX_ME: Добавлена проверка корректности ввода
     - Добавлен вызов `ValidateExpression`

3. **Исправления в Source.cpp**:
   - FIX_ME: Замена циклов на рекурсию (согласно условию)
     - В функции ParseNumber: while заменен на рекурсию
     - В функции ParseTerm: while заменен на рекурсию
     - В функции ParseExpression: while заменен на рекурсию
   - FIX_ME: Переименование функций с заглавной буквы
     - Старое: `NumRead`, `CalculateTerm`, `CalculateS`
     - Новое: `ParseNumber`, `ParseTerm`, `ParseExpression`
