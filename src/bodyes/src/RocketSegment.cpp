#include "../include/RocketSegment.h"

#define PI 3.14159265359

RocketSegment::RocketSegment(b2World *world,
                             b2Vec2 **vertices,
                             const int verticesCount,
                             int *verticesSizes,
                             float density,
                             float restitution,
                             b2Vec2 position,
                             float imageHight,
                             std::string imagePath):
                             Body(world, vertices, verticesCount,
                                  verticesSizes, density, restitution,
                                  position, imageHight, imagePath)
{

};

void RocketSegment::setPower(float power, float angle)
{
  b2Vec2 localForceVec(power * sin(angle * (PI / 180)),
                       power * cos(angle) * (PI / 180));
  b2Vec2 localForcePoint(forcePoint_.x, forcePoint_.y);
  b2Vec2 globalForceVec = body_->GetWorldVector(localForceVec);
  b2Vec2 globalForcePoint = body_->GetWorldPoint(localForcePoint);
  body_->ApplyForce(globalForceVec, globalForcePoint);
}

void RocketSegment::setForcePoint(b2Vec2 point)
{
  forcePoint_ = point;
}
