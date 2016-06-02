/*
* Copyright 2016 Goginet gogi.soft.gm@gmail.com
*
* Модуль "GameManager" служит для упрошения создания интерфейса игры
*
* Game - главный класс игры
*
* Для создания игры используйте конструктор
* Lge::Game(стартовое_состояние, ширина, высота, название);
*
* для запуска игры используйте метод
* Lge::Game::start();
*
* Каждое отдеьное состояние описывается в отдельном классе наследующимся
* от State. И имеет следующую структуру ...
*
* 1. Lge::State::State() - инициализация
* 2. update - обновление логики
* 3. render - отрисовка
* 4. control - обработка событий для этого состояния
*
*/

#ifndef GAME_MANAGER_
#define GAME_MANAGER_

/* необходимые библиотеки */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/* МАКРОСЫ */

/* проверяет существует ли макрос RES_PATH(путь к папке с рессурсами),
 * если нет то выводит предупреждение и выставляет значение по умолчанию */
#ifndef RES_PATH
#define RES_PATH ""
#warning not initialized macro RES_PATH
#endif

/* проверяет существует ли макрос VERSION(версия программы),
 * если нет то выводит предупреждение и выставляет значение по умолчанию */
#ifndef VERSION
#define VERSION "0.0"
#warning not initialized macro VERSION
#endif

/* добавляет путь к папке с рессурсами */
#define ADD_RES_PATH(PATH) (std::string(RES_PATH) + std::string(PATH)).c_str()

/* для рисования текстуры с изменением размера */
#define PUT_TEXTURE_INTO_SPRITE_ZOOM_AND_DRAW(WINDOW, TEXTURE, SCALE, CENTRE) \
do { \
  sf::Sprite sprite; \
  sprite.setTexture(TEXTURE); \
  sprite.setOrigin(CENTRE); \
  sprite.setScale(SCALE); \
  WINDOW->draw(sprite); \
} while (false);

/* для рисования текстуры без изменения размера */
#define PUT_TEXTURE_INTO_SPRITE_AND_DRAW(WINDOW, TEXTURE, POSITION) \
do { \
  sf::Sprite sprite; \
  sprite.setTexture(TEXTURE); \
  sf::Vector2u textureSize = TEXTURE.getSize(); \
  sprite.setOrigin(static_cast<float>(textureSize.x) / 2 + POSITION.x, \
                   static_cast<float>(textureSize.y) / 2 - POSITION.y); \
  WINDOW->draw(sprite); \
} while (false);

/* для сохранения изначальных пропорций камеры состояния  */
#define SAFE_VIEW_RATIO(VIEW, VIEW_WIDTH, VIEW_HEIGHT, WINDOW) \
do { \
  sf::Vector2u windowSize = WINDOW->getSize(); \
  float nowRatio = static_cast<float>(windowSize.x) / windowSize.y; \
  float deltaRatio = nowRatio / static_cast<float>(VIEW_WIDTH / VIEW_HEIGHT); \
  VIEW.setSize(sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT / deltaRatio)); \
} while (false);

/* объявление классов модуля */
namespace Lge {
class State;
class GSM;
class Game;
class Button;
class ButtonListner;
}

/* подключение заголовочных файлов модуля */
#include "include/GameManager/Game.hpp"
#include "include/GameManager/GSM.hpp"
#include "include/GameManager/State.hpp"
#include "include/GameManager/Button.hpp"
#include "include/GameManager/ButtonListner.hpp"

#endif /* end of include guard: GAME_MANAGER_ */
