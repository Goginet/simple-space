#include "../include/RocketNasaSls.h"


void RocketNasaSls::createSecondStage(b2World *world, b2Vec2 position,
                                      std::string image,
                                      float imageHight,
                                      float density,
                                      float restitution,
                                      float mass,
                                      b2Vec2 forcePoint)
{
  int COUNT = 4;

  int const VERTICES_DOCK_L = 4;
  int const VERTICES_DOCK_R = 4;
  int const VERTICES_TRUNK = 4;
  int const VERTICES_ENGINE = 4;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int verticesSizes[COUNT] = {
    VERTICES_DOCK_L,
    VERTICES_DOCK_R,
    VERTICES_TRUNK,
    VERTICES_ENGINE
  };

  b2Vec2 verticesDock_L[VERTICES_DOCK_L] =
  {
    b2Vec2(0, 8.550000190734863),
    b2Vec2(0.07500000298023224, 8.550000190734863),
    b2Vec2(0.07500000298023224, 8.949999809265137),
    b2Vec2(0, 8.949999809265137)
  };

  b2Vec2 verticesDock_R[VERTICES_DOCK_R] =
  {
    b2Vec2(0.925000011920929, 8.550000190734863),
    b2Vec2(1, 8.550000190734863),
    b2Vec2(1, 8.949999809265137),
    b2Vec2(0.925000011920929, 8.949999809265137)
  };

  b2Vec2 verticesTrunk[VERTICES_TRUNK] =
  {
    b2Vec2(0, 0.550000011920929),
    b2Vec2(1, 0.550000011920929),
    b2Vec2(1, 8.550000190734863),
    b2Vec2(0, 8.550000190734863)
  };

  b2Vec2 verticesEngine[VERTICES_ENGINE] =
  {
    b2Vec2(0.17499999701976776, 0),
    b2Vec2(0.824999988079071, 0),
    b2Vec2(0.824999988079071, 0.550000011920929),
    b2Vec2(0.17499999701976776, 0.550000011920929)
  };

  vertices[0] = verticesDock_L;
  vertices[1] = verticesDock_R;
  vertices[2] = verticesTrunk;
  vertices[3] = verticesEngine;

  secondStage_ = new RocketSegment(world, vertices, COUNT,
  verticesSizes, density, restitution,
  position, imageHight, image);

  ((Body*)secondStage_)->setMass(mass);
  secondStage_->setForcePoint(forcePoint);

}
