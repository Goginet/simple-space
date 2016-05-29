/*
* Copyright 2016 Goginet gogi.soft.gm@gmail.com
*
* Game it's main class for configurate your game
* for create game use constructor Game(startState, width, hight)
*   startState - state which displayed when the game starts
*   width and hight - it's sizes for game window
*   and call the method Game::start()
*/

#ifndef LGEGAME_HPP
#define LGEGAME_HPP

#include <string>

#include "../../GameManager.hpp"

namespace Lge {
class Game {
 public:
  Game(State *startState, float width, float hight, std::string name);

  ~Game();

  /* start game */
  void start();

  /* end game */
  void end();

  /* restart game */
  void restart();

  /* go to previous state */
  void back();

 private:
  bool isAlive_;

  /* sfml window were drawing game */
  sf::RenderWindow *window_;

  /* game state manager */
  GSM *gsm_;

  /* draw game */
  void render(GSM *gsm);

  /* update game  */
  void update(GSM *gsm);

  /* listning the events in game */
  void control();
};
}  // namespace namespace Lge

#endif /* end of include guard: LGEGAME_HPP */
