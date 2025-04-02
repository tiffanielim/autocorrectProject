//
// Created by Tiffanie Lim on 11/6/24.
//

#include "Heap.h"

void Heap::push(const Word& word)
{
    heap.push_back(word);
    std::push_heap(heap.begin(), heap.end(), compare);
}

Word Heap::pop()
{
    std::pop_heap(heap.begin(), heap.end(), compare);
    Word top = heap.back();
    heap.pop_back();
    return top;
}

bool Heap::empty() const
{
    return heap.empty();
}

bool Heap::compare(const Word& a, const Word& b)
{
    return a.getPriority() > b.getPriority();
}
