//
// Created by Tiffanie Lim on 11/4/24.
//

#ifndef CS8_CURSOR_STATES_H
#define CS8_CURSOR_STATES_H
#include <map>
#include "StateEnum.h"

class States {
private:
    std::map<StateEnum, bool> _states;

public:
    States();

    void enableState(StateEnum state);
    void disableState(StateEnum state);
    void toggleState(StateEnum state);
    bool checkState(StateEnum state) const;

};


#endif //CS8_CURSOR_STATES_H
