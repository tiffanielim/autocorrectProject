//
// Created by Tiffanie Lim on 11/4/24.
//

///manages on/off states using StateEnum as keys

#ifndef CS8_CURSOR_STATES_H
#define CS8_CURSOR_STATES_H
#include <map>
#include "StateEnum.h"

class States {
private:
    std::map<StateEnum, bool> _states;

public:
    States(); //initializes all states to false

    void enableState(StateEnum state); //sets state to true
    void disableState(StateEnum state); //sets state to false
    void toggleState(StateEnum state); //switches state from true to false or vice versa
    bool checkState(StateEnum state) const; //returns current value of the state

};


#endif //CS8_CURSOR_STATES_H
