//
// Created by Tiffanie Lim on 11/6/24.
//

///min-heap that sorts Word objects by priority

#ifndef AUTOCORRECT_HEAP_H
#define AUTOCORRECT_HEAP_H
#include "Word.h"
#include <vector>
#include <algorithm>

class Heap {
private:
    std::vector<Word> heap;
    static bool compare(const Word& a, const Word& b); //compares Words to order the words in the heap

public:
    void push(const Word& word); //adds word to heap
    Word pop(); //removes and returns highest priority word
    bool empty() const; //checks if heap is empty

};

#endif //AUTOCORRECT_HEAP_H
