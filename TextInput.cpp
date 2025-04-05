//
// Created by Tiffanie Lim on 11/5/24.
//

#include "TextInput.h"

TextInput::TextInput(float width, float height, float x, float y, const std::string& wordBank)
        : box(sf::Vector2f(width, height)), maxLength(100), isActive(false),
          cursor(text.getCharacterSize()), autoCorrect(wordBank)
{
    text.setFont(Font::getFont("futura"));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5.f, y + 5.f);

    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2.f);
    box.setPosition(x, y);

}

void TextInput::handleEvent(const sf::Event& event)
{
    //handles text entry when active
    if (event.type == sf::Event::TextEntered)
    {
        if (isActive)
            processInput(event.text.unicode);
    }
    //activates input box if clicked
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            isActive = true;
        else
            isActive = false;
    }
    //handles ctrl+z or cmd+z undo
    if (event.type == sf::Event::KeyPressed)
    {
        if ((event.key.control || event.key.system) && event.key.code == sf::Keyboard::Z)
            undo();
    }
}

void TextInput::update(sf::Time deltaTime)
{
    cursor.update(deltaTime);
}

void TextInput::render(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);
    if (isActive)
    {
        cursor.render(window);
        displaySuggestions(window);
    }
}

void TextInput::processInput(sf::Uint32 unicode)
{
    if (unicode == '\b')
        deleteCharacter();
    else if (unicode < 128 && content.length() < maxLength)
    {
        backspace.saveState(content); //saves state for undo
        content.insert(content.begin() + cursor.getPosition(), static_cast<char>(unicode));
        text.setString(content);
        cursor.moveRight();
        updateSuggestions();
        cursor.updatePosition(text);
    }
}

void TextInput::deleteCharacter()
{
    unsigned int cursorPos = cursor.getPosition();
    if (!content.empty() && cursorPos > 0)
    {
        backspace.saveState(content); //same thing, saves state for undo
        content.erase(cursorPos - 1, 1); //removes char before cursor
        cursor.moveLeft();
        text.setString(content);
        cursor.updatePosition(text);
        updateSuggestions();
    }
}

void TextInput::undo()
{
    std::string previousState = backspace.undo();
    if (!previousState.empty())
    {
        content = previousState;
        text.setString(content);
        cursor.setPosition(content.size()); //puts cursor at end
        cursor.updatePosition(text);
        updateSuggestions();
    }
}

void TextInput::updateSuggestions()
{
    suggestions = autoCorrect.getSortedWords(content);
    suggestionsHeap = Heap(); //rebuilds heap with new words

    for (const auto& word : suggestions)
        suggestionsHeap.push(word);
}

void TextInput::displaySuggestions(sf::RenderWindow& window)
{
    float offsetY = box.getPosition().y + box.getSize().y + 5.f;
    int count = 0;

    for (auto suggestion : suggestions)
    {
        if (count >= 10) break;
        sf::Text suggestionText(suggestion.getWord(), Font::getFont("futura"), 20);
        suggestionText.setFillColor(sf::Color::Black);
        suggestionText.setPosition(box.getPosition().x, offsetY);
        window.draw(suggestionText);
        offsetY += 25.f;
        count++;
    }
}
