/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include <iostream>
#include "../../GameManager.hpp"

Lge::GSM::GSM(sf::RenderWindow *window):
states_() {
  window_ = window;
}

Lge::GSM::~GSM() {
  while (!states_.empty()) {
    delete states_.top();
    states_.pop();
  }
}

void Lge::GSM::push(State *state) {
  state->setGSM(this);
  state->setWindow(window_);
  states_.push(state);
}

void Lge::GSM::pop() {
  states_.pop();
}

void Lge::GSM::set(State *state) {
  states_.pop();
  states_.push(state);
}

void Lge::GSM::render() {
  states_.top()->render();
}

void Lge::GSM::update() {
  states_.top()->update();
}

void Lge::GSM::control(sf::Event event) {
  states_.top()->control(event);
}
