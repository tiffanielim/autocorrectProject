//
// Created by Tiffanie Lim on 11/6/24.
//

#include "Heap.h"

void Heap::push(const Word& word)
{
    heap.push_back(word);
    std::push_heap(heap.begin(), heap.end(), compare); //maintains heap structure
}

Word Heap::pop()
{
    std::pop_heap(heap.begin(), heap.end(), compare); //moves highest priority to the end
    Word top = heap.back();
    heap.pop_back(); //removes it from vector
    return top;
}

bool Heap::empty() const
{
    return heap.empty();
}

//returns true if a should come after b in the heap
//this makes it a min-heap (lower priority = higher importance)
bool Heap::compare(const Word& a, const Word& b)
{
    return a.getPriority() > b.getPriority();
}
