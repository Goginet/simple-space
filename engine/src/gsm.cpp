#include "../include/gsm.h"

GSM::GSM(Window *window):
states()
{
  this->window = window;
}

GSM::~GSM()
{
  // TODO: дописать деструктор ~GSM
}

void GSM::push(State state)
{
  states.push(state);
}

void GSM::pop()
{
  states.pop();
}

void GSM::set(State state)
{
  states.pop();
  states.push(state);
}

void GSM::render()
{
  states.top().render();
}

void GSM::update(unsigned int deltaTime)
{
  states.top().update(deltaTime);
}
