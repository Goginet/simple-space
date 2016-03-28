#pragma once

#include <stack>
#include "state.h"

class GSM
{
  public:
    GSM(sf::RenderWindow *window);
    ~GSM();

    void push(State *st);
    void pop();
    void set(State *state);
    void render();
    void update(unsigned int deltaTime);
    void control(sf::Event event);
  protected:
    // стэк состояний игры
    std::stack<State*> states;
    sf::RenderWindow *window;
};
