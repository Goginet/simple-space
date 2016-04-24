/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../LGE/LgeGame.hpp"

LgeGame::LgeGame(State *startState, float width, float hight) {
  window_ = new sf::RenderWindow(sf::VideoMode(width, hight), "simple space");
  gsm_ = new GSM(window_);
  gsm_->push(startState);
  window_->setFramerateLimit(60);
  isAlive_ = false;
}

LgeGame::~LgeGame() {
  end();
  gsm_->~GSM();
  window_->close();
  delete gsm_;
  delete window_;
}

void LgeGame::render(GSM *gsm) {
  gsm_->render();
}

void LgeGame::update(GSM *gsm, unsigned int deltaTime) {
  gsm_->update(deltaTime);
}

void LgeGame::control() {
  sf::Event event;
  while (window_->pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window_->close();
        end();
      break;

      default:
        gsm_->control(event);
      break;
    }
  }
}

void LgeGame::start() {
  isAlive_ = true;

  // life cycle for game
  while (isAlive_) {
    // TODO(Goginet): допили таймер!!!
    window_->clear();
    render(gsm_);
    update(gsm_, DELTA_TIME);
    control();
    window_->display();
  }
}

void LgeGame::end() {
  isAlive_ = false;
  window_->close();
}

void LgeGame::restart() {
  end();
  start();
}

void LgeGame::back() {
  gsm_->pop();
}
