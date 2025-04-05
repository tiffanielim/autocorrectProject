//
// Created by Tiffanie Lim on 11/4/24.
//

///handles blinking cursor logic and placement in text input box

#ifndef AUTOCORRECT_CURSOR_H
#define AUTOCORRECT_CURSOR_H
#include <SFML/Graphics.hpp>

class Cursor {
private:
    sf::RectangleShape cursor;
    sf::Time blinkTime;
    bool visible;
    unsigned int position;

public:
    Cursor(unsigned int size); //is the vertical line of the curosr

    void update(sf::Time deltaTime); //blinks cursor every 0.5s
    void render(sf::RenderWindow& window); //draws cursor if visible
    void updatePosition(const sf::Text& text); //moves cursor to match character index
    unsigned int getPosition() const;
    void moveLeft();
    void moveRight();
    void setPosition(unsigned int pos);
};

#endif //AUTOCORRECT_CURSOR_H
