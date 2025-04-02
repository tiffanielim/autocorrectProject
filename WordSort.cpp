//
// Created by Tiffanie Lim on 11/6/24.
//

#include "WordSort.h"

WordSort::WordSort(const std::string& dictionaryPath)
{
    FileReader fileReader(dictionaryPath);
    const auto& wordList = fileReader.getWords();
    for (const auto& word : wordList)
        words.emplace_back(word);
}

int WordSort::calculatePriority(const std::string& input, const std::string& word)
{
    int matchLength = 0;
    for (size_t i = 0; i < input.size() && i < word.size(); ++i) {
        if (input[i] == word[i]) {
            matchLength++;
        } else {
            break;
        }
    }
    return matchLength;
}

std::vector<Word> WordSort::getSortedWords(const std::string& input)
{
    for (auto& word : words)
        word.setPriority(calculatePriority(input, word.getWord()));

    std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
        return a.getPriority() > b.getPriority();
    });
    return words;
}
