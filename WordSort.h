//
// Created by Tiffanie Lim on 11/6/24.
//

///sorts words based on how closely they match the input

#ifndef AUTOCORRECT_WORDSORT_H
#define AUTOCORRECT_WORDSORT_H
#include "Word.h"
#include "FileReader.h"
#include <vector>

class WordSort {
private:
    std::vector<Word> words;

    //compares input and word to assign priority (higher = better match)
    int calculatePriority(const std::string& input, const std::string& word);

public:
    WordSort(const std::string& dictionaryPath); //loads words from file
    std::vector<Word> getSortedWords(const std::string& input);
};

#endif //AUTOCORRECT_WORDSORT_H
