//
// Created by Tiffanie Lim on 11/6/24.
//

#ifndef AUTOCORRECT_WORDSORT_H
#define AUTOCORRECT_WORDSORT_H
#include "Word.h"
#include "FileReader.h"
#include <vector>

class WordSort {
private:
    std::vector<Word> words;
    int calculatePriority(const std::string& input, const std::string& word);

public:
    WordSort(const std::string& dictionaryPath);
    std::vector<Word> getSortedWords(const std::string& input);
};

#endif //AUTOCORRECT_WORDSORT_H
