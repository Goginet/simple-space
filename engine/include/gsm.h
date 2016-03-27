#include <stack>
#include "state.h"

class GSM
{
  public:
    GSM(Window *window);
    ~GSM();

    void push(State state);
    void pop();
    void set(State state);
    void render();
    void update(unsigned int deltaTime);
  private:
    std::stack<State> states;
    Window *window;
};
