/* Copyright 2016 Goginet gogi.soft.gm@gmail.com
*
* Game State Manager(GSM)
*
* Using for switch game states.
* State ate stored in the stack.
* Top state is an active state.
*
* Example states for Classical game:
*                  -> State PLAY
* State START_MENU -> State SETTINGS
*                  -> State ABOUT
*
*/

#ifndef GSM_HPP
#define GSM_HPP

#include <stack>
#include "../../GameManager.hpp"

namespace Lge {
class GSM {
 public:
  explicit GSM(sf::RenderWindow *window);

  ~GSM();

  /* add a new state to the top */
  void push(State *state);

  /* remove the top state */
  void pop();

  /* set this state as active state */
  void set(State *state);

  /* draw active state */
  void render();

  /* update active state */
  void update();

  /* processing this event in active state */
  void control(sf::Event event);

  /* get game pointer */
  Game *getGame();

 protected:
  /* stack wich save game states, the top state is an active state */
  std::stack<State*> states_;

  /* window which is displayed active state */
  sf::RenderWindow *window_;

 private:
  Game *game_;

  friend Game;
};
}  // namespace Lge

#endif /* end of include guard: GSM_HPP */
