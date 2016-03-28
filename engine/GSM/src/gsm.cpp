#include "../include/gsm.h"

GSM::GSM(sf::RenderWindow *window):
states()
{
  this->window = window;
}

GSM::~GSM()
{
  // TODO: дописать деструктор ~GSM
}

// добавление состояния наверх стека
void GSM::push(State *state)
{
  state->setGSM(this);
  state->setWindow(this->window);
  states.push(state);
}

// удаление верхнего состояния
void GSM::pop()
{
  states.pop();
}

// замена активного состояния
void GSM::set(State *state)
{
  states.pop();
  states.push(state);
}

void GSM::render()
{
  states.top()->render();
}

void GSM::update(unsigned int deltaTime)
{
  states.top()->update(deltaTime);
}

void GSM::control(sf::Event event)
{
  states.top()->control(event);
}