#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

const int SCREEN_W  = 1024;
const int SCREEN_H  = 900;
const int FPS       = 60;

sf::RenderWindow window( sf::VideoMode(SCREEN_W, SCREEN_H ), "Space Shooter");
sf::Event e;


//Helpers
void debug(std::string strText="", unsigned int intText=0) {
    sf::Font font;
    sf::Text text;

    font.loadFromFile("./fonts/Metropolian-Display.ttf");
    text.setFont( font );
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition({20, 20});

    if( strText != "" or intText != 0)
        text.setString(strText + " "  + std::to_string(intText));

    window.draw(text);
}
