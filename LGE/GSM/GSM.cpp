/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../../LGE/GSM/GSM.hpp"

GSM::GSM(sf::RenderWindow *window):
states_() {
  window_ = window;
}

GSM::~GSM() {
  // TODO(Goginet): дописать деструктор ~GSM
}

void GSM::push(State *state) {
  state->setGSM(this);
  state->setWindow(window_);
  states_.push(state);
}

void GSM::pop() {
  states_.pop();
}

void GSM::set(State *state) {
  states_.pop();
  states_.push(state);
}

void GSM::render() {
  states_.top()->render();
}

void GSM::update(unsigned int deltaTime) {
  states_.top()->update(deltaTime);
}

void GSM::control(sf::Event event) {
  states_.top()->control(event);
}
