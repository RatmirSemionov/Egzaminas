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

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::ifstream;
using std::map;
using std::ofstream;

void countWords(const string& inputFileName, const string& outputFileName);
bool isNumber(const string& s);
string toLower(const string& s);

#endif // MYLIB_H_INCLUDED
