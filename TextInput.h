//
// Created by Tiffanie Lim on 11/5/24.
//

///handles input box logic including typing, cursor, undo, and suggestions

#ifndef AUTOCORRECT_TEXTINPUT_H
#define AUTOCORRECT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include "Cursor.h"
#include "Backspace.h"
#include "AutoCorrect.h"
#include "Word.h"
#include "Heap.h"
#include <string>
#include <vector>

class TextInput {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string content;
    bool isActive;
    unsigned int maxLength;
    Cursor cursor;
    Backspace backspace;
    AutoCorrect autoCorrect;
    std::vector<Word> suggestions;
    Heap suggestionsHeap;

    void processInput(sf::Uint32 unicode); //handles character typing and backspace
    void deleteCharacter(); //removes character before cursor
    void undo(); //reverts to previous state using Backspace
    void updateSuggestions(); //refreshes suggestion list from AutoCorrect
    void displaySuggestions(sf::RenderWindow& window); //draws suggestions below box

public:
    TextInput(float width, float height, float x, float y, const std::string& wordBank);

    void handleEvent(const sf::Event& event); //handles mouse, key, and typing events
    void update(sf::Time deltaTime); //blinks cursor
    void render(sf::RenderWindow& window); //draws text box and suggestions
};

#endif //AUTOCORRECT_TEXTINPUT_H
