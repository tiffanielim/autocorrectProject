#include <SFML/Graphics.hpp>
#include "TextInput.h"

int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "AutoCorrect Text Input");
    sf::RenderWindow window(sf::VideoMode(600, 760), "AutoCorrect Text Input");

    std::string babyGirlNames = "5000-baby-girl-names.txt";
//    TextInput textBox(400, 50, 200, 250, babyGirlNames);
    TextInput textBox(500, 40, 50, 250, babyGirlNames);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            textBox.handleEvent(event);
        }

        sf::Time deltaTime = clock.restart();
        textBox.update(deltaTime);

        window.clear(sf::Color(251, 198, 207));
        textBox.render(window);
        window.display();
    }

    return 0;
}
