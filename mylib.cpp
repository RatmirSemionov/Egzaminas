#include "mylib.h"

bool isNumber(const string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

bool isCustomPunct(char c) {
    static const string punctuations = R"(-—–)";
    return ispunct(static_cast<unsigned char>(c)) || punctuations.find(c) != string::npos;
}

string toLowerLT(const string& s) {
    static const std::unordered_map<char, char> ltLowerMap = {
        {'Ą', 'ą'}, {'Č', 'č'}, {'Ę', 'ę'}, {'Ė', 'ė'}, {'Į', 'į'},
        {'Š', 'š'}, {'Ų', 'ų'}, {'Ū', 'ū'}, {'Ž', 'ž'},
        {'A', 'a'}, {'B', 'b'}, {'C', 'c'}, {'D', 'd'}, {'E', 'e'},
        {'F', 'f'}, {'G', 'g'}, {'H', 'h'}, {'I', 'i'}, {'J', 'j'},
        {'K', 'k'}, {'L', 'l'}, {'M', 'm'}, {'N', 'n'}, {'O', 'o'},
        {'P', 'p'}, {'R', 'r'}, {'S', 's'}, {'T', 't'}, {'U', 'u'},
        {'V', 'v'}, {'Z', 'z'},
    };

    string lower;
    for (char c : s) {
        auto it = ltLowerMap.find(c);
        if (it != ltLowerMap.end()) {
            lower += it->second;
        } else {
            lower += c;
        }
    }
    return lower;
}

int UTF8(const string& str) {
    int count = 0;
    for (unsigned char c : str) {

        if ((c & 0xC0) != 0x80) {
            ++count;
        }
    }
    return count;
}


void countWords(const string& inputFileName, const string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Nepavyko atidaryti faila: " << inputFileName << endl;
        return;
    }

    std::map<string, int> wordCount;
    string line, word;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            // Istrinam skyrybos zenklus
            word.erase(std::remove_if(word.begin(), word.end(), ::isCustomPunct), word.end());
            // Istrinam numerius is zodziu
            word.erase(std::remove_if(word.begin(), word.end(), ::isdigit), word.end());
            // Pakeiciam raides i mazasias
            word = toLowerLT(word);
            // Tikrinam ar zodis nera numeris ir tuscias
            if (!isNumber(word) && !word.empty()) {
                ++wordCount[word];
            }
        }
    }

    std::ofstream outputFile(outputFileName);
    outputFile << string(43, '-') << "\n";
    outputFile << "|" << left << setw(20) << "      Zodis" << "|" << right << setw(20) << "Pakartotinumas   " << "|\n";
    outputFile << string(43, '-') << "\n";
    for (const auto &pair : wordCount) {
        if (pair.second > 1) {
            int UTF8Taisymas = pair.first.size() - UTF8(pair.first);
            outputFile << "|" << left << setw(20 + UTF8Taisymas) << pair.first << "|         " << left << setw(11) << pair.second << "|\n";
            outputFile << string(43, '-') << "\n";
        }
    }
    inputFile.close();
    outputFile.close();
}
