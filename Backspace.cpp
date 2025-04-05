//
// Created by Tiffanie Lim on 11/7/24.
//

#include "Backspace.h"

//pushes new input state onto the stack
void Backspace::saveState(const std::string& state)
{
    states.push(state);
}

//returns the last saved state and removes it from the stack
std::string Backspace::undo()
{
    if (!states.empty())
    {
        std::string lastState = states.top();
        states.pop();
        return lastState;
    }
    return "";
}
