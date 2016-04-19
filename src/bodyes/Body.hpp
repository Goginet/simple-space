#ifndef BODY_H
#define BODY_H


#include <string>

#include "../../../SFML/Graphics.hpp"
#include "../../../Box2D/Box2D.h"

class Body
{
  public:
    Body(b2World *world, b2Vec2 **vertices, const int verticesCount,
          int *verticesSizes, float density, float restitution,
          b2Vec2 position, float imageHight,std::string imagePath);

    void render(sf::RenderWindow *window, float scale);
    b2RevoluteJoint* createJoint(Body *body, b2Vec2 point);
    b2Vec2 getPosition(float scale);
    void setMass(float mass);
    void setBodyPosition(b2Vec2 pos);
    void setImagePath(std::string path);
    void setImageHight(float hight);

  protected:
    b2Body *body_;

  private:
    float imageHight_;
    std::string imagePath_;
};

#endif /* end of include guard: BODY_H */
