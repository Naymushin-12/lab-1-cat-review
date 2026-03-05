// Source.cpp
#include "Header.h"

void SkipSpaces(const string& s, int& pos)
{
    while (pos < s.length() && isspace(s[pos]))
    {
        pos++;
    }
}

int ParseNumber(const string& s, int& pos, int currentNumber)
{
    SkipSpaces(s, pos);
    if (pos >= s.length() || !isdigit(s[pos]))
    {
        return currentNumber;
    }
    currentNumber = currentNumber * 10 + (s[pos] - '0');
    pos++;
    
    // FIX_ME: (заменен цикл на рекурсию)
    // while (pos < s.length() && isdigit(s[pos])) { ... }
    return ParseNumber(s, pos, currentNumber);
}

int ParseTerm(const string& s, int& pos)
{
    int value = ParseNumber(s, pos);
    SkipSpaces(s, pos);
    
    // FIX_ME: (заменен цикл while на рекурсию)
    if (pos < s.length() && s[pos] == '*')
    {
        pos++;
        int nextValue = ParseTerm(s, pos);
        value *= nextValue;
    }
    
    return value;
}

int ParseExpression(const string& s, int& pos)
{
    int value = ParseTerm(s, pos);
    SkipSpaces(s, pos);
    
    // FIX_ME: (заменен цикл while на рекурсию)
    if (pos < s.length() && (s[pos] == '+' || s[pos] == '-'))
    {
        char op = s[pos];
        pos++;
        int nextValue = ParseExpression(s, pos);
        if (op == '+')
        {
            value += nextValue;
        }
        else
        {
            value -= nextValue;
        }
    }
    
    return value;
}

bool ValidateExpression(const string& s, int& pos)
{
    SkipSpaces(s, pos);
    if (pos >= s.length())
    {
        return true;
    }
    
    if (!isdigit(s[pos]) && s[pos] != '+' && s[pos] != '-' && s[pos] != '*')
    {
        return false;
    }
    
    pos++;
    return ValidateExpression(s, pos);
}