//
// Created by Tiffanie Lim on 11/7/24.
//

///stores previous states of input so user can undo

#ifndef AUTOCORRECT_BACKSPACE_H
#define AUTOCORRECT_BACKSPACE_H
#include <stack>
#include <string>

class Backspace {
private:
    std::stack<std::string> states; //stack to hold input history

public:
    void saveState(const std::string& state); //saves current input state to the stack
    std::string undo(); //removes and returns the last saved state
};

#endif //AUTOCORRECT_BACKSPACE_H
