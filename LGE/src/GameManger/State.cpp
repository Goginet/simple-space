/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../../GameManager.hpp"

Lge::State::State() {
  this->gsm_ = NULL;
  this->window_ = NULL;
}

void Lge::State::setGSM(GSM *gsm) {
  this->gsm_ = gsm;
}

void Lge::State::setWindow(sf::RenderWindow *window) {
  this->window_ = window;
}
