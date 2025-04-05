//
// Created by Tiffanie Lim on 11/4/24.
//

///loads and returns sf::Font objects using font name strings

#ifndef CS8_CURSOR_FONT_H
#define CS8_CURSOR_FONT_H
//template <typename T, typename S>
//struct Pair
//{
//    T first;
//    S second
//}; this is what the map holds, objects of these pairs

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class Font {
private:
    inline static std::map<std::string, sf::Font> _fonts; //stores loaded fonts
    static void loadFont(const std::string& fontName); //adds font to _fonts if not already loaded
    static std::string getFontPath(std::string fontName);

public:
    static sf::Font& getFont(const std::string& fontName);

};


#endif //CS8_CURSOR_FONT_H
