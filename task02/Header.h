// Header.h
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// FIX_ME: (добавлены новые функции для проверок)
bool OpenFiles(ifstream& fin, ofstream& fout, const string& in, const string& out);
int ReadAndCheckN(ifstream& fin);
bool CheckBoardDimensions(ifstream& fin, int N);
bool ReadAndCheckBoard(ifstream& fin, vector<vector<int>>& board, int N);
void CheckExtraCharacters(ifstream& fin);

#endif