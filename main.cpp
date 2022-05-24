#include "stdfx.hpp"
#include "player.hpp"
#include "enemy.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Space Shooter");
    window.setFramerateLimit( FPS );

    Player player;

    std::vector<Enemy> enemies;
    

    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape )
                window.close();

        window.clear();

        //Update
        player.update();

        if(enemies.size() < 10) {
            Enemy e(
                rand()% SCREEN_W + (rand()% 200),
                rand()% SCREEN_H + (rand()% 300)
            );
            enemies.push_back(e);
        }

        
        for(int i=0; i<enemies.size(); i++) {
            enemies[i].render(window);
            enemies[i].update();

            if(enemies[i].getPosition().y > SCREEN_H) {
                enemies.erase(enemies.begin() + i);
            }
        }
        debug(window, "", enemies[0].getPosition().y);
        debug(window, "", enemies.size(), {20, 60});
        

        //Draw
        player.render( window );


        window.display();
    }

    window.close();
    return 0;
}
