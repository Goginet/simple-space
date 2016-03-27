#include "../include/game.h"
#include <unistd.h>

Game::Game(State *startState,float width, float hight):
window(new sf::RenderWindow(sf::VideoMode(width, hight), "SFML works!")),
gsm(window)
{
  gsm.push(startState);
  alive = false;
}

Game::~Game()
{
  // TODO: test
  this->end();
  gsm.~GSM();
  delete window;
}

// отрисовка объектов в игре
void Game::render(GSM gsm)
{
  gsm.render();
}

// обновление логики в игре
void Game::update(GSM gsm, unsigned int deltaTime)
{
  gsm.update(deltaTime);
}

// запуск игры
void Game::start()
{
  alive = true;

  while (alive)                             // жизненый цикл игры
  {
    render(gsm);
    update(gsm, DELTA_TIME);
    sleep(DELTA_TIME);
  }
}

// завершение игры
void Game::end()
{
  alive = false;
  //window.close()
}

void Game::restart()
{
  end();
  start();
}

// возрат к предыдущему окну
void Game::back()
{
  // TODO : test
  gsm.pop();
}
