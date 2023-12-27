#include "mylib.h"
int main()
{
    char Pasirinkimas;
    string inputFileName, outputFileName, domainFileName;

    cout << "Ar norite pamatyti zodzius tekste, kurie kartojasi daugiau nei viena karta? (Jei taip, rasykite K)" << endl;
    cout << "Ar norite pamatyti, kurioje eiluteje yra zodziai, kurie kartojasi daugiau nei viena karta? (Jei taip, rasykite E)" << endl;
    cout << "Ar norite pamatyti URL linkus, kurie yra tekste? (Jei taip, rasykite L)" << endl;
    cin >> Pasirinkimas;
    if (Pasirinkimas == 'K') {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        countWords(inputFileName, outputFileName);
    }
    else if (Pasirinkimas == 'E') {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        findWordLocations(inputFileName, outputFileName);
    }
    else if (Pasirinkimas == 'L') {
        set<string> domain;
        cout << "Iveskite failo pavadinima su domenais: ";
        cin >> domainFileName;
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        Domains(domainFileName, domain);
        findURL(domain, inputFileName, outputFileName);
    }
    else {
        cout << "Neteisingas ivedimas, programa baigiasi." << endl;
        return 0;
    }

    return 0;
}
