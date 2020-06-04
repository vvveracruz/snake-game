#include "game.hpp"

namespace vgg {

Game::Game() {

  Run();

}

void Game::Run() {

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

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
}
}
