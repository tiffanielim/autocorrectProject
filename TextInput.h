//
// Created by Tiffanie Lim on 11/5/24.
//

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

    void processInput(sf::Uint32 unicode);
    void deleteCharacter();
    void undo();
    void updateSuggestions();
    void displaySuggestions(sf::RenderWindow& window);

public:
    TextInput(float width, float height, float x, float y, const std::string& wordBank);

    void handleEvent(const sf::Event& event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
};

#endif //AUTOCORRECT_TEXTINPUT_H
