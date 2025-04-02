//
// Created by Tiffanie Lim on 11/6/24.
//

#include "AutoCorrect.h"

AutoCorrect::AutoCorrect(const std::string& wordBankPath)
    : wordSort(wordBankPath)
    {}

std::vector<Word> AutoCorrect::getSortedWords(const std::string& input)
{
    return wordSort.getSortedWords(input);
}

