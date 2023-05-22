#pragma once

#include "drawBord.hpp"

sf::Color typeColor[6] = {
    sf::Color::Black, // wall
    sf::Color::White, // empty
    sf::Color::Yellow, // wisited
    sf::Color::Red, // start
    sf::Color::Blue, // end
    sf::Color::Cyan // queued
};

sf::Color getColot(int typeNum) {
    return typeColor[typeNum];
}

void drawBord(sf::RenderWindow& window, const Bord& bord) {
    window.clear();
    for (size_t i = 0; i < bord.xSize; i++) {
        for (size_t j = 0; j < bord.ySize; j++) {

            auto newColor = getColot(bord.data[i][j]);
            auto shadowColor = newColor == sf::Color::Black ? sf::Color::White : sf::Color::Black;

            sf::RectangleShape shadow(sf::Vector2f(bord.squerSize, bord.squerSize));
            shadow.setFillColor(shadowColor);
            shadow.setPosition(i*bord.squerSize, j*bord.squerSize);
            window.draw(shadow);

            sf::RectangleShape squere(sf::Vector2f(bord.squerSize - 2, bord.squerSize - 2));
            squere.setFillColor(newColor);
            squere.setPosition(i*bord.squerSize + 1, j*bord.squerSize + 1);
            window.draw(squere);

        }
    }
    window.display();
}