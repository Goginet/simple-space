/*
* Copyright 2016 Goginet gogi.soft.gm@gmail.com
*
* Модуль "GameManager" служит для разбития игры на состояния, и для
* управления между ниими
*
*/

#ifndef GAME_MANAGER_
#define GAME_MANAGER_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define PUT_TEXTURE_INTO_SPRITE_ZOOM_AND_DRAW(WINDOW, TEXTURE, SCALE, CENTRE) \
do { \
  sf::Sprite sprite; \
  sprite.setTexture(TEXTURE); \
  sprite.setOrigin(CENTRE); \
  sprite.setScale(SCALE); \
  WINDOW->draw(sprite); \
} while (false);

#define PUT_TEXTURE_INTO_SPRITE_AND_DRAW(WINDOW, TEXTURE, POSITION) \
do { \
  sf::Sprite sprite; \
  sprite.setTexture(TEXTURE); \
  sf::Vector2u textureSize = TEXTURE.getSize(); \
  sprite.setOrigin(static_cast<float>(textureSize.x) / 2 + POSITION.x, \
                   static_cast<float>(textureSize.y) / 2 - POSITION.y); \
  WINDOW->draw(sprite); \
} while (false);

#define SAFE_VIEW_RATIO(VIEW, VIEW_WIDTH, VIEW_HEIGHT, WINDOW) \
do { \
  sf::Vector2u windowSize = WINDOW->getSize(); \
  float nowRatio = static_cast<float>(windowSize.x) / windowSize.y; \
  float deltaRatio = nowRatio / static_cast<float>(VIEW_WIDTH / VIEW_HEIGHT); \
  VIEW.setSize(sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT / deltaRatio)); \
} while (false);

#define CONVERT_SCREEN_X_TO_VIEW(WINDOW, SCREN_X, VIEW_X) \
(VIEW_X / WINDOW->getSize().x) * SCREN_X

#define CONVERT_SCREEN_Y_TO_VIEW(WINDOW, SCREN_Y, VIEW_Y) \
(VIEW_Y / WINDOW->getSize().y) * SCREN_Y

namespace Lge {
class State;
class GSM;
class Game;
}

#include "include/GameManager/Game.hpp"
#include "include/GameManager/GSM.hpp"
#include "include/GameManager/State.hpp"
#include "include/GameManager/Button.hpp"

#endif /* end of include guard: GAME_MANAGER_ */
