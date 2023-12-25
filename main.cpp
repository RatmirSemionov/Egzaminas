#include "mylib.h"

int main()
{
    char Pasirinkimas;
    string inputFileName, outputFileName;

    cout << "Ar norite pamatyti zodzius tekste, kurie kartojasi daugiau nei viena karta? (T - taip, N - ne) " << endl;
    cin >> Pasirinkimas;
    if (Pasirinkimas == 'T') {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        countWords(inputFileName, outputFileName);
    }
    else {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        findWordLocations(inputFileName, outputFileName);
    }

    return 0;
}
