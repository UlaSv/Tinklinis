#pragma once

#include <SFML/Graphics.hpp>
#include <format>
#include "Sources/Defines.h"

class Game
{
private:
    sf::RenderWindow _app;
    sf::Texture _texture;
    sf::Sprite _sprite;

  public:
      Game() {};
      ~Game() {};

      int run() 
      {
          _app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tenisas");
          _app.setFramerateLimit(60);

          // This should do some error checking as well and 'return' just in case.
          texture.loadFromFile("myImage.png");
          sprite.setTexture(texture);

          while (window.isOpen()) {
              // Your standard game loop here...
              // Polling events...
              sf::Event event;
              while (window.pollEvent(event)) {
                switch (event.type) {
                  case sf::Event::Closing:
                    window.close();
                    break;
                }
              }

              // Updating things...

              // Drawing everything...
              window.clear();
              window.draw(sprite);
              window.display();
            }
            return 0;
          }
};


