#include "FirstState.hpp"

void FirstState::drawBackground(sf::RenderWindow *window, b2Vec2 size,
                                b2Vec2 position)
{
  sf::Sprite sprite;
  sf::Texture texture;
  if(position.y > -15000)
  {
    if (texture.loadFromFile("../res/background1.jpeg"))
    {
      sprite.setTexture(texture);
      sprite.setOrigin(811/2, 520 / 2);
      sprite.scale(3.5,5);
      sprite.setPosition(position.x, position.y);
      window->draw(sprite);
    }
  }
  else
  {
    if(position.y < -50000)
    {
      if (texture.loadFromFile("../res/background3.jpg"))
      {
        sprite.setTexture(texture);
        sprite.setOrigin(854/2, 417 / 2);
        sprite.scale(3.5,5);
        sprite.setPosition(position.x, position.y);
        window->draw(sprite);
      }
    }
    else
    {
      if (texture.loadFromFile("../res/background2.png"))
      {
        sprite.setTexture(texture);
        sprite.setOrigin(1000/2, 775 / 2);
        sprite.scale(3.5,5);
        sprite.setPosition(position.x, position.y);
        window->draw(sprite);
      }
    }
  }
}
