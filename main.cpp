#include "stdfx.hpp"
#include "player.hpp"


int main() {

    window.setFramerateLimit( FPS );

    Player player;


    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape )
                window.close();

        window.clear();

        //Update
        player.update();

        //Draw
        player.render();

        window.display();
    }

    window.close();
    return 0;
}
