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

void findWordLocations(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Nepavyko atidaryti failo: " << inputFileName << endl;
        return;
    }

    map<string, std::pair<int, std::set<int>>> wordDetails; // set tures linijos numerius
    string line, word;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        ++lineNumber;
        std::istringstream iss(line);
        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), isCustomPunct), word.end());
            word.erase(remove_if(word.begin(), word.end(), ::isdigit), word.end());
            word = toLowerLT(word);
            if (!isNumber(word) && !word.empty()) {
                wordDetails[word].first += 1;          // Zodzio kartojimas
                wordDetails[word].second.insert(lineNumber); // linijos numeris
            }
        }
    }
    inputFile.close();

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Nepavyko atidaryti faila: " << outputFileName << endl;
        return;
    }
    outputFile << string(161, '-') << endl;
    outputFile << left << setw(20) << "Zodis" << "|" << "Eiluciu numeriai" << endl;
    outputFile << string(161, '-') << endl;

    for (const auto &pair : wordDetails) {
        const string &word = pair.first;
        int count = pair.second.first;
        const std::set<int> &lines = pair.second.second;

        if (count > 1) { // Tikrinama, ar zodis atsiranda tekste daugiau nei viena karta
            int UTF8Taisymas = word.size() - UTF8(word);
            outputFile << left << setw(20 + UTF8Taisymas) << word << "| ";
            for (int lineNum : lines) {
                outputFile << lineNum << " ";
            }
            outputFile << "\n";
            outputFile << string(161, '-') << "\n";

        }
    }

    outputFile.close();
}
