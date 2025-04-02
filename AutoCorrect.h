//
// Created by Tiffanie Lim on 11/6/24.
//

#ifndef AUTOCORRECT_AUTOCORRECT_H
#define AUTOCORRECT_AUTOCORRECT_H
#include <string>
#include <vector>
#include "Word.h"
#include "FileReader.h"
#include "WordSort.h"

class AutoCorrect {
private:
    WordSort wordSort;
public:
    AutoCorrect(const std::string& wordBankPath);
    std::vector<Word> getSortedWords(const std::string& input);
};


#endif //AUTOCORRECT_AUTOCORRECT_H
