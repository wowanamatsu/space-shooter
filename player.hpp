#pragma once
#include "stdfx.hpp"
#include "bullet.hpp"


class Player {
private:
    sf::Texture texture;
    sf::Sprite  sprite;

    sf::Vector2f position;
    sf::Vector2f velocity;

    float acceleration;

    std::vector<Bullet> bullets;
    float bulletCD = 0;

public:
    Player() {
        texture.loadFromFile("./assets/player/ship3.png");
        sprite.setTexture( texture );
        sprite.setPosition( position );
        sprite.setOrigin( { 50, 136/2  } ); 

        acceleration = 10.f;
        sprite.setPosition( SCREEN_W/2, SCREEN_H - sprite.getGlobalBounds().height );
    }

    void render() {
        window.draw( sprite );

        if( bullets.size()>0 ) {
            for( int i=0; i<bullets.size(); i++ ) {
                bullets[i].render();
                bullets[i].update();
                if( bullets[i].getPosition().y < -20 ) {
                    bullets.erase(bullets.begin()+i);
                }
                debug("Bullets", bullets.size());
            }
        }
    }

    void update() { 
        sprite.move( velocity );

        if( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) && getLeft() >= 0 ) {
            velocity.x = -acceleration;
        } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) && getPosition().x+getWidth()/2 <= SCREEN_W ) {
            velocity.x = acceleration;
        } else velocity.x = 0;

        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ) {
            bulletCD++;
            if( bulletCD >= 7.0f ) {
                shoot();
                bulletCD = 0.f;
            }
        }
    }

    void shoot() {
        if( bullets.size() <= 5 ) {
            Bullet b(getPosition().x, getPosition().y - 70);
            bullets.push_back(b);
        }
    }

    void setPosition( sf::Vector2f pos ) { sprite.setPosition( pos ); }

    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }

    float getLeft() { return sprite.getGlobalBounds().left; }
    float getWidth() { return sprite.getGlobalBounds().width; }

};
