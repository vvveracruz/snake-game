#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

namespace vgg {

class Game {

public:
    Game( int width, int height, std::string title );

private:
    void Run( );

};
}
