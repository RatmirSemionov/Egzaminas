#include "mylib.h"

int main()
{
    string inputFileName, outputFileName;
    cout << "Iveskite failo pavadinima: ";
    cin >> inputFileName;
    cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
    cin >> outputFileName;

    countWords(inputFileName, outputFileName);

    return 0;
}
