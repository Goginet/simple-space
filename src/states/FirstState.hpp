/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef FIRSTSTATE_H
#define FIRSTSTATE_H

#include <Box2D/Box2D.h>

#include <SFML/Window.hpp>

#include <string>

#include "../../LGE/GSM/State.hpp"
#include "../bodyes/BigBody.hpp"
#include "../rockets/RocketNasaSls.hpp"

class FirstState: public State {
 public:
  FirstState();
  virtual void render();
  virtual void update(unsigned int deltaTime);
  virtual void control(sf::Event event);

 private:
  RocketNasaSls *rocket_;

  BigBody *ground_;

  b2World *world_;

  sf::View view_;

  float scale_;

  float zoom_;

  float ratio_;

  void createGround(b2World *world);
  void drawBackground(sf::RenderWindow *window, b2Vec2 size, b2Vec2 position);
  void drawInfo(sf::RenderWindow *window);
};

#endif /* end of include guard: FIRSTSTATE_H */
