#include "RocketNasaSls.hpp"


void RocketNasaSls::createThirdStage(b2World *world, b2Vec2 position,
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
  int const VERTICES_ENGINE = 8;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int verticesSizes[COUNT] = {
    VERTICES_DOCK_L,
    VERTICES_DOCK_R,
    VERTICES_TRUNK,
    VERTICES_ENGINE
  };

  b2Vec2 verticesDock_L[VERTICES_DOCK_L] =
  {
    b2Vec2(0, 1.1750000715255737),
    b2Vec2(0.07500000298023224, 1.1750000715255737),
    b2Vec2(0.07500000298023224, 1.5750000476837158),
    b2Vec2(0, 1.5750000476837158)
  };

  b2Vec2 verticesDock_R[VERTICES_DOCK_R] =
  {
    b2Vec2(0.925000011920929, 1.1750000715255737),
    b2Vec2(1, 1.1750000715255737),
    b2Vec2(1, 1.5750000476837158),
    b2Vec2(0.925000011920929, 1.5750000476837158)
  };

  b2Vec2 verticesTrunk[VERTICES_TRUNK] =
  {
    b2Vec2(0, 0.375),
    b2Vec2(1, 0.375),
    b2Vec2(1, 1.1750000715255737 + 0.04999998211860657),
    b2Vec2(0,1.1750000715255737  + 0.04999998211860657)
  };

  b2Vec2 verticesEngine[VERTICES_ENGINE] =
  {
    b2Vec2(0.125, 0),
    b2Vec2(0.875, 0),
    b2Vec2(0.875, 0.125),
    b2Vec2(0.8500000238418579, 0.25),
    b2Vec2(0.7250000238418579, 0.375),
    b2Vec2(0.2750000059604645, 0.375),
    b2Vec2(0.15000000596046448, 0.25),
    b2Vec2(0.125, 0.125)
  };

  vertices[0] = verticesDock_L;
  vertices[1] = verticesDock_R;
  vertices[2] = verticesTrunk;
  vertices[3] = verticesEngine;

  thirdStage_ = new RocketSegment(vertices, COUNT, verticesSizes);

  ((Body*)thirdStage_)->setDensity(density);
  ((Body*)thirdStage_)->setRestitution(restitution);
  ((Body*)thirdStage_)->setPosition(position);
  ((Body*)thirdStage_)->setImageHight(imageHight);
  ((Body*)thirdStage_)->setImagePath(image);
  ((Body*)thirdStage_)->setMass(mass);

  thirdStage_->setForcePoint(forcePoint);

  ((Body*)thirdStage_)->build(world);
}
