#ifndef FIRSTSTATE_H
#define FIRSTSTATE_H

#include <string>

#include "../../../SFML/Window.hpp"
#include "../../../Box2D/Box2D.h"

#include "../../../engine/GSM/include/gsm.h"
#include "../../bodyes/include/BigBody.h"
#include "../../rockets/include/RocketNasaSls.h"

class FirstState: public State
{
  public:
    FirstState();
    virtual void render();
    virtual void update(unsigned int deltaTime);
    virtual void control(sf::Event event);

  private:
    RocketNasaSls *rocket_;

    BigBody *ground_;

    b2World *world_;

    sf::View view_;

    float scale_;

    void createGround(b2World *world);
    void drawBackground(sf::RenderWindow *window, b2Vec2 size, b2Vec2 position);
    void drawInfo(sf::RenderWindow *window);
};

#endif /* end of include guard: FIRSTSTATE_H */
