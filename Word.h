//
// Created by Tiffanie Lim on 11/5/24.
//

///represents a word suggestion with a priority valu

#ifndef AUTOCORRECT_WORD_H
#define AUTOCORRECT_WORD_H
#include <string>

class Word {
private:
    std::string word;
    int priority;

public:
    Word(const std::string& word); //sets word and initializes priority to 0
    const std::string& getWord() const;
    int getPriority() const;
    void setPriority(int priority);
};

#endif //AUTOCORRECT_WORD_H
