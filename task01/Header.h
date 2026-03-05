// Header.h
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

// FIX_ME: (добавлены новые функции для безопасного чтения и проверок)
bool OpenFile(ifstream& File, const string& filename);
bool SafeReadInt(ifstream& File, int& value);
bool HasEnoughNumbersInLine(ifstream& File, int expectedCount);
void CheckExtraCharacters(ifstream& File);

#endif