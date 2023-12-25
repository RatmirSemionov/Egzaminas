#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <locale>
#include <unordered_map>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::ifstream;
using std::map;
using std::ofstream;
using std::setw;
using std::right;
using std::left;

void countWords(const string& inputFileName, const string& outputFileName);
bool isNumber(const string& s);
string toLowerLT(const string& s);
bool isCustomPunct(char c);
int UTF8(const string& str);

#endif // MYLIB_H_INCLUDED
