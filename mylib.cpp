#include "mylib.h"

bool isNumber(const string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

string toLower(const string& s) {
    std::locale loc;
    string lower;
    for (char c : s) {
        lower += std::tolower(c, loc);
    }
    return lower;
}

void countWords(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Nepavyko atidaryti faila: " << inputFileName << endl;
        return;
    }

    map<string, int> wordCount;
    string line, word;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            // Istrinam skyrybos zenklus
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            // Istrinam numerius
            word.erase(remove_if(word.begin(), word.end(), ::isdigit), word.end());
            // Darom taip, kad visi teksto raides butu mazi
            word = toLower(word);
            // Ignoruojam numeriu pasikartijmo skaiciavimo
            if (!isNumber(word)) {
                ++wordCount[word];
            }
        }
    }

    ofstream outputFile(outputFileName);
    for (const auto &pair : wordCount) {
        if (pair.second > 1) {
            outputFile << pair.first << ": " << pair.second << '\n';
        }
    }

    inputFile.close();
    outputFile.close();
}
