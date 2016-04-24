/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef LGEGAME_HPP
#define LGEGAME_HPP

#include <SFML/Graphics.hpp>

#include "../LGE/GSM/GSM.hpp"

////////////////////////////////////////////////////////
// LgeGame it's main class for configurate your game
// for create game use constructor Game(startState, width, hight)
//   startState - state which displayed when the game starts
//   width and hight - it's sizes for game window
// and call the method LgeGame::start()
////////////////////////////////////////////////////////

class LgeGame {
 public:
  LgeGame(State *startState, float width, float hight);

  ~LgeGame();

  // start game
  void start();

  // end game
  void end();

  // restart game
  void restart();

  // go to previous state
  void back();

 private:
  static const unsigned int DELTA_TIME = 1;

  bool isAlive_;

  sf::RenderWindow *window_;

  GSM *gsm_;

  // draw game
  void render(GSM *gsm);

  // update game
  void update(GSM *gsm, unsigned int deltaTime);

  // listning the events in game
  void control();
};

#endif /* end of include guard: LGEGAME_HPP */
