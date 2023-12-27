#include "mylib.h"
#include <Windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char Pasirinkimas;
    char Isvedimas;
    string inputFileName, outputFileName, domainFileName;

    cout << "Ar norite, kad rezultatas dar butu isvestas i ekrana? (Jei taip, rasykite T)" << endl;
    cin >> Isvedimas;

    cout << "Ar norite pamatyti zodzius tekste, kurie kartojasi daugiau nei viena karta? (Jei taip, rasykite K)" << endl;
    cout << "Ar norite pamatyti, kurioje eiluteje yra zodziai, kurie kartojasi daugiau nei viena karta? (Jei taip, rasykite E)" << endl;
    cout << "Ar norite pamatyti URL linkus, kurie yra tekste? (Jei taip, rasykite L)" << endl;
    cin >> Pasirinkimas;
    if (Pasirinkimas == 'K') {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        std::map<string, int> wordCount;
        countWords(inputFileName, outputFileName, wordCount);

        if (Isvedimas == 'T') {
        cout << string(43, '-') << "\n";
        cout << "|" << left << setw(20) << "      Zodis" << "|" << right << setw(20) << "Pakartotinumas   " << "|\n";
        cout << string(43, '-') << "\n";
        for (const auto &pair : wordCount) {
            if (pair.second > 1) {
                int UTF8Taisymas = pair.first.size() - UTF8(pair.first);
                cout << "|" << left << setw(20 + UTF8Taisymas) << pair.first << "|         " << left << setw(11) << pair.second << "|\n";
                cout << string(43, '-') << "\n";
            }
        }
        }
    }
    else if (Pasirinkimas == 'E') {
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        map<string, std::pair<int, std::set<int>>> wordDetails;
        findWordLocations(inputFileName, outputFileName, wordDetails);

        if (Isvedimas == 'T') {
        cout << string(161, '-') << endl;
        cout << left << setw(20) << "Zodis" << "|" << "Eiluciu numeriai" << endl;
        cout << string(161, '-') << endl;

        for (const auto &pair : wordDetails) {
            const string &word = pair.first;
            int count = pair.second.first;
            const std::set<int> &lines = pair.second.second;

            if (count > 1) { // Tikrinama, ar zodis atsiranda tekste daugiau nei viena karta
                int UTF8Taisymas = word.size() - UTF8(word);
                cout << left << setw(20 + UTF8Taisymas) << word << "| ";
                for (int lineNum : lines) {
                    cout << lineNum << " ";
                }
                cout << "\n";
                cout << string(161, '-') << "\n";

            }
        }
        }
    }
    else if (Pasirinkimas == 'L') {
        set<string> domain;
        set<string> validUrls;
        cout << "Iveskite failo pavadinima su domenais: ";
        cin >> domainFileName;
        cout << "Iveskite failo pavadinima su jusu teksta: ";
        cin >> inputFileName;
        cout << "Iveskite failo pavadinima i kuri norite issaugot rezultatus: ";
        cin >> outputFileName;
        Domains(domainFileName, domain);
        findURL(domain, inputFileName, outputFileName, validUrls);

        if (Isvedimas == 'T') {
        cout << string(50, '-') << endl;
        cout << "URL Adresai" << endl;
        cout << string(50, '-') << endl;
        for(const string& url : validUrls) {
            cout << url << endl;
            cout << string(50, '-') << endl;
        }
        }

    }
    else {
        cout << "Neteisingas ivedimas, programa baigiasi." << endl;
        return 0;
    }
    return 0;
}
