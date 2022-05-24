#ifndef BULLET_H
#define BULLET_H

#include "stdfx.hpp"

class Bullet {

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

    float speed = 20.f;

public:
    Bullet( const float& posX, const float& posY ) {
        texture.loadFromFile("./assets/bullet/bullet.png");
        sprite.setTexture( texture );
        sprite.setPosition( posX, posY );
        sprite.setOrigin({ 3, 5 });
        position.x = posX;
        position.y = posY;
    }

    void render( sf::RenderWindow& window ) {
        window.draw( sprite );
    }

    void update() {
        sprite.move({0, -speed});
    }

    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }

};
#endif