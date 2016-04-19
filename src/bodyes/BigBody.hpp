#ifndef BIGBODY_H
#define BIGBODY_H


#include <string>

#include "../../../SFML/Graphics.hpp"
#include "../../../Box2D/Box2D.h"

class BigBody
{
  public:
    BigBody(b2World *world, b2Vec2 **vertices, const int verticesCount,
            int *verticesSizes, float density, float restitution,
            b2Vec2 position, float imageHight,std::string imagePath,
            b2Vec2 step);

    void render(sf::RenderWindow *window, float scale, b2Vec2 centerView);
    void renderAt(sf::RenderWindow *window,sf::Texture texture, float scale, b2Vec2 position);

  protected:
    b2Body *body_;

  private:
    float imageHight_;
    std::string imagePath_;
    b2Vec2 step_;

};

#endif /* end of include guard: BIGBODY_H */
