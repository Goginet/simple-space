/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef STATE_HPP
#define STATE_HPP


#include <SFML/Graphics.hpp>

#include "../../LGE/GSM/GSM.hpp"

/////////////////////////////////////////////////////////
// State it's a base class for all States
// To create a state, you need to define three methods
// 1) render
// 2) update
// 3) control
// if you want to open a new state use gsm_->push(new_state) or
// gsm_->push(new_state)
/////////////////////////////////////////////////////////

class GSM;

class State {
 public:
  State();

  // draw state
  virtual void render() = 0;

  // update state
  virtual void update(unsigned int deltaTime) = 0;

  // processing this event
  virtual void control(sf::Event event) = 0;

  // set gsm_
  void setGSM(GSM *gsm);

  // set window_
  void setWindow(sf::RenderWindow *window);

 protected:
  // gsm which manage the states in game
  GSM *gsm_;

  // window for rendering
  sf::RenderWindow *window_;
};

#endif /* end of include guard: STATE_HPP */
