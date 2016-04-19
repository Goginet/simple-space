#ifndef ROCKETSEGMENT_H
#define ROCKETSEGMENT_H


#include "Body.hpp"

class RocketSegment: Body
{
  public:
    RocketSegment(b2World *world, b2Vec2 **vertices, const int verticesCount,
                  int *verticesSizes, float density, float restitution,
                  b2Vec2 position, float imageHight,std::string imagePath);

    void setPower(float power, float angle);
    void setForcePoint(b2Vec2 point);

  private:
    b2Vec2 forcePoint_;
};

#endif /* end of include guard: ROCKETSEGMENT_H */
