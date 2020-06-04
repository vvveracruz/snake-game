#include "DEFINITIONS.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

    sf::Texture snakeHeadTexture;
    snakeHeadTexture.loadFromFile( SNAKE_HEAD_FILEPATH ) ;

    sf::Sprite snakeHeadSprite;
    snakeHeadSprite.setTexture( snakeHeadTexture );

    sf::Texture snakeBodyTexture;
    snakeBodyTexture.loadFromFile( SNAKE_BODY_FILEPATH );

    sf::Sprite snakeBodySprite;
    snakeBodySprite.setTexture( snakeBodyTexture );

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw( snakeHeadSprite );
        window.draw( snakeBodySprite );
        window.display();
    }

    return 0;
}
