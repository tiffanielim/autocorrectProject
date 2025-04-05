//
// Created by Tiffanie Lim on 11/6/24.
//

#include "AutoCorrect.h"

//constructs the AutoCorrect object and loads the word bank
AutoCorrect::AutoCorrect(const std::string& wordBankPath)
    : wordSort(wordBankPath)
    {}

//returns a sorted list of suggestions based on the user input
std::vector<Word> AutoCorrect::getSortedWords(const std::string& input)
{
    return wordSort.getSortedWords(input);
}

