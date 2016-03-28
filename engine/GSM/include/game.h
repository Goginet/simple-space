#pragma once

#include "gsm.h"

class Game
{
  public:
    Game(State *startState,float width, float hight);
    ~Game();
    void start();
    void end();
    void restart();
    void back();
  private:
    // delta время для отрисовки и обновления логики
    const static unsigned int DELTA_TIME = 1;
    bool alive;
    // указатель на окно игры
    sf::RenderWindow *window;
    // менеджер состояний
    GSM *gsm;
    static void render(GSM *gsm);
    static void update(GSM *gsm, unsigned int deltaTime);
    void control();
    //std::thread renderThread;                               // TODO: многопоточность отложим до лучших времен)
    //std::thread updateThread;
    //std::thread control;
};
