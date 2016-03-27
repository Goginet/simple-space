#include <SFML/Graphics.hpp>

class GSM;

class State
{
  public:
    State();
    virtual void render() = 0;
    virtual void update(unsigned int deltaTime) = 0;
    void setGSM(GSM *gsm);
    void setWindow(sf::RenderWindow *window);

  private:
    GSM *gsm;
    sf::RenderWindow *window;
};
