//
// Created by Tiffanie Lim on 11/5/24.
//

#include "Word.h"

Word::Word(const std::string& word)
    : word(word), priority(0)
    {}

const std::string& Word::getWord() const {
    return word;
}

int Word::getPriority() const {
    return priority;
}

void Word::setPriority(int priority)
{
    this->priority = priority;
}
