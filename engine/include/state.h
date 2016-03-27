#include "window.h"

class GSM;

class State
{
  public:
    void render();
    void update(unsigned int deltaTime);
  private:
    Window *window;
    GSM *gsm;
};
