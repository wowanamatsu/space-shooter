#ifndef ENEMY_H
#define ENEMY_H

#include "stdfx.hpp"

class Enemy {

private:

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

    float speed;

public:

    Enemy(float posX, float posY) {
        inimigo.loadFromFile("./assets/enemy/ship.png");
        sprite.setTexture( inimigo );
        sprite.setPosition( {posX, -posY} );
        speed = 2.f;
    }

    void render( sf::RenderWindow& window ) {
        window.draw( sprite );
    }

    void update() {
        sprite.move( { 0, speed } );
    }

    void setPosition( sf::Vector2f pos ) { sprite.setPosition( pos ); }

    sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }
    sf::Vector2f getPosition() { return sprite.getPosition(); }

};
#endif