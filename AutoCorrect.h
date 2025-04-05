//
// Created by Tiffanie Lim on 11/6/24.
//

/// handles the main autocorrect functionality
/// sorts word suggestions based on user input

#ifndef AUTOCORRECT_AUTOCORRECT_H
#define AUTOCORRECT_AUTOCORRECT_H
#include <string>
#include <vector>
#include "Word.h"
#include "FileReader.h"
#include "WordSort.h"

class AutoCorrect {
private:
    WordSort wordSort; //loads and sorts words based on similarity (which is the priority)
public:
    //constructor that initializes the word sorter using the word bank file
    AutoCorrect(const std::string& wordBankPath);

    //returns a list of suggested words sorted by relevance to the input
    std::vector<Word> getSortedWords(const std::string& input);
};


#endif //AUTOCORRECT_AUTOCORRECT_H
