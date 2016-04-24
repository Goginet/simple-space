/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../../LGE/GSM/State.hpp"

State::State() {
  this->gsm_ = NULL;
  this->window_ = NULL;
}

void State::setGSM(GSM *gsm) {
  this->gsm_ = gsm;
}

void State::setWindow(sf::RenderWindow *window) {
  this->window_ = window;
}