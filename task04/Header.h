// Header.h
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// FIX_ME: (переименованы все функции с заглавной буквы)
int ParseNumber(const string& s, int& pos, int currentNumber = 0);
int ParseTerm(const string& s, int& pos);
int ParseExpression(const string& s, int& pos);
bool ValidateExpression(const string& s, int& pos);
void SkipSpaces(const string& s, int& pos);

#endif