#include "game.h"


Game::Game(State *startState,float width, float hight):
window(new sf::RenderWindow(sf::VideoMode(width, hight), "simple space")),
gsm(new GSM(window))
{
  gsm->push(startState);
  window->setFramerateLimit(60);
  alive = false;
}

Game::~Game()
{
  // TODO: test
  this->end();
  gsm->~GSM();
  window->close();
  delete gsm;
  delete window;
}

// отрисовка объектов в игре
void Game::render(GSM *gsm)
{
  gsm->render();
}

// обновление логики в игре
void Game::update(GSM *gsm, unsigned int deltaTime)
{
  gsm->update(deltaTime);
}

// обработка событий в игре
void Game::control()
{
  sf::Event event;
  while (window->pollEvent(event))
  {
    switch (event.type) {
      case sf::Event::Closed:
        window->close();
        this->end();
      break;

      default:
        gsm->control(event);
      break;
    }
  }
}

// запуск игры
void Game::start()
{
  alive = true;


  while (alive)                             // жизненый цикл игры
  {
    // TODO: допили счетчик!!!
    window->clear();
    render(gsm);
    update(gsm, DELTA_TIME);
    control();
    window->display();
  }
}

// завершение игры
void Game::end()
{
  alive = false;
  window->close();
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
  gsm->pop();
}
