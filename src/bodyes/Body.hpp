#ifndef BODY_H
#define BODY_H


#include <string>

#include "../../../SFML/Graphics.hpp"
#include "../../../Box2D/Box2D.h"

class Body
{
  public:
    Body(b2Vec2 **vertices, int verticesCount, int *verticesSizes);

    void build(b2World *world);

    void destroy();

    void render(sf::RenderWindow *window, float scale);

    b2RevoluteJoint* createJoint(Body *body, b2Vec2 point);

    void setDensity(float density);

    void setRestitution(float restitution);

    void setPosition(b2Vec2 position);

    b2Vec2 getPosition();

    void setImageHight(float hight);

    void setImagePath(std::string path);

    void setMass(float mass);

  protected:
    b2Body *body_;

  private:
    b2Vec2 **vertices_;
    int verticesCount_;
    int *verticesSizes_;
    float density_;
    float restitution_;
    b2Vec2 position_;
    float imageHight_;
    std::string imagePath_;
    float mass_;
};

#endif /* end of include guard: BODY_H */
