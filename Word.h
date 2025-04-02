//
// Created by Tiffanie Lim on 11/5/24.
//

#ifndef AUTOCORRECT_WORD_H
#define AUTOCORRECT_WORD_H
#include <string>

class Word {
private:
    std::string word;
    int priority;

public:
    Word(const std::string& word);
    const std::string& getWord() const;
    int getPriority() const;
    void setPriority(int priority);
};

#endif //AUTOCORRECT_WORD_H
