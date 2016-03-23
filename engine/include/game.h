#include "gsm.h"
#include <thread>

class Game
{
  public:
    Game(float width, float hight, int x, int y);
    ~Game();
    void start();
    void end();
    void restart();
    void back();
  private:
    // delta время для отрисовки и обновления логики
    const unsigned int DELTA_TIME = 1;
    bool alive;
    // указатель на графическое окно игры
    Window *window;
    // менеджер состояний
    GSM gsm;
    static void render(GSM gsm);
    static void update(GSM gsm, unsigned int deltaTime);
    //std::thread renderThread;                               // TODO: многопоточность отложим до лучших времен)
    //std::thread updateThread;
};
