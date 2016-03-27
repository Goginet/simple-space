#include "../include/state.h"

State::State()
{
  this->gsm = NULL;
  this->window = NULL;
}

void State::setGSM(GSM *gsm)
{
  this->gsm = gsm;
}

void State::setWindow(sf::RenderWindow *window)
{
  this->window = window;
}
