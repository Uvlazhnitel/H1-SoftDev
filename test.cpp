#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <string>

int main() {
    std::string inputFileName = "examples.txt";    // Input file name
    std::string outputFileName = "output1.txt";  // Output file name

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open " << inputFileName << std::endl;
        return 1;
    }

    std::map<char, std::map<std::string, int>> wordCounts;
    std::string word;

    // Read and filter words from the input file
    while (inputFile >> word) {
        std::string cleanWord;
        for (char ch : word) {
            if (isalpha(ch)) {  // Keep only alphabet characters
                cleanWord += tolower(ch);
            }
        }
        if (!cleanWord.empty()) {
            wordCounts[cleanWord[0]][cleanWord]++;
        }
    }

    inputFile.close();

    // Determine the most frequent word for each letter
    std::map<char, std::string> mostFrequentWords;
    for (const auto& p : wordCounts) {
        int maxFreq = 0;
        std::string mostFreqWord;
        for (const auto& wp : p.second) {
            if (wp.second > maxFreq) {
                maxFreq = wp.second;
                mostFreqWord = wp.first;
            }
        }
        mostFrequentWords[p.first] = mostFreqWord;
    }

    // Output the most frequent words to the output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open " << outputFileName << std::endl;
        return 1;
    }

    for (char letter = 'a'; letter <= 'z'; ++letter) {
        outputFile << letter << ": ";
        if (mostFrequentWords.find(letter) != mostFrequentWords.end()) {
            outputFile << mostFrequentWords[letter];
        }
        outputFile << std::endl;
    }

    outputFile.close();
    return 0;
}
