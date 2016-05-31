/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include <string>

#include "../../GameManager.hpp"

Lge::Game::Game(State *startState, float width, float hight, std::string name) {
  window_ = new sf::RenderWindow(sf::VideoMode(width, hight), name);

  gsm_ = new GSM(window_);
  gsm_->game_ = this;
  gsm_->push(startState);
  window_->setFramerateLimit(60);
  isAlive_ = false;
}

Lge::Game::~Game() {
  end();
  delete gsm_;
  delete window_;
}

void Lge::Game::render(GSM *gsm) {
  gsm_->render();
}

void Lge::Game::update(GSM *gsm) {
  gsm_->update();
}

void Lge::Game::control() {
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

void Lge::Game::start() {
  isAlive_ = true;

  // life cycle for game
  while (isAlive_ && !gsm_->states_.empty()) {
    // TODO(Goginet): допили таймер!!!
    window_->clear();
    render(gsm_);
    update(gsm_);
    control();
    window_->display();
  }
}

void Lge::Game::end() {
  isAlive_ = false;
  window_->close();
}

void Lge::Game::restart() {
  end();
  start();
}

void Lge::Game::back() {
  gsm_->pop();
}
