//
// Created by Tiffanie Lim on 11/6/24.
//

#ifndef AUTOCORRECT_HEAP_H
#define AUTOCORRECT_HEAP_H
#include "Word.h"
#include <vector>
#include <algorithm>

class Heap {
private:
    std::vector<Word> heap;
    static bool compare(const Word& a, const Word& b);

public:
    void push(const Word& word);
    Word pop();
    bool empty() const;

};

#endif //AUTOCORRECT_HEAP_H
