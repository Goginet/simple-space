#include "RocketNasaSls.hpp"


void RocketNasaSls::createFourthStage(b2World *world, b2Vec2 position,
                                      std::string image,
                                      float imageHight,
                                      float density,
                                      float restitution,
                                      float mass,
                                      b2Vec2 forcePoint)
{
  int COUNT = 4;

  int const VERTICES_TRUNK = 6;
  int const VERTICES_ENGINE_L = 8;
  int const VERTICES_ENGINE_R = 8;
  int const VERTICES_UP = 8;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int verticesSizes[COUNT] = {
    VERTICES_TRUNK,
    VERTICES_ENGINE_L,
    VERTICES_ENGINE_R,
    VERTICES_UP
  };

  b2Vec2 verticesTrunk[VERTICES_TRUNK] =
  {
    b2Vec2(0, 0.3499999940395355),
    b2Vec2(1, 0.3499999940395355),
    b2Vec2(1, 0.5250000357627869),
    b2Vec2(1, 2.375),
    b2Vec2(0, 2.375),
    b2Vec2(0, 0.5250000357627869)
  };

  b2Vec2 verticesEngineL[VERTICES_ENGINE_L] =
  {
    b2Vec2(0.10000000149011612, 0),
    b2Vec2(0.4749999940395355, 0),
    b2Vec2(0.4749999940395355, 0.10000000149011612),
    b2Vec2(0.45000001788139343, 0.22500000894069672),
    b2Vec2(0.375, 0.3499999940395355),
    b2Vec2(0.17499999701976776, 0.3499999940395355),
    b2Vec2(0.10000000149011612, 0.22500000894069672),
    b2Vec2(0.10000000149011612, 0.10000000149011612)
  };

  b2Vec2 verticesEngineR[VERTICES_ENGINE_R] =
  {
    b2Vec2(0.5250000357627869, 0),
    b2Vec2(0.9000000357627869, 0),
    b2Vec2(0.9000000357627869, 0.10000000149011612),
    b2Vec2(0.9000000357627869, 0.22500000894069672),
    b2Vec2(0.824999988079071, 0.3499999940395355),
    b2Vec2(0.625, 0.3499999940395355),
    b2Vec2(0.550000011920929, 0.22500000894069672),
    b2Vec2(0.5250000357627869, 0.10000000149011612)
  };

  b2Vec2 verticesUp[VERTICES_UP] =
  {
    b2Vec2(0, 2.375 ),
    b2Vec2(1, 2.375 ),
    b2Vec2(0.8500000238418579, 2.875 ),
    b2Vec2(0.6000000238418579, 3.4000000953674316 ),
    b2Vec2(0.5250000357627869, 3.450000047683716 ),
    b2Vec2(0.4749999940395355, 3.450000047683716 ),
    b2Vec2(0.4000000059604645, 3.4000000953674316 ),
    b2Vec2(0.15000000596046448, 2.875 )
  };

  vertices[0] = verticesTrunk;
  vertices[1] = verticesEngineL;
  vertices[2] = verticesEngineR;
  vertices[3] = verticesUp;

  fourthStage_ = new RocketSegment(vertices, COUNT, verticesSizes);

  ((Body*)fourthStage_)->setDensity(density);
  ((Body*)fourthStage_)->setRestitution(restitution);
  ((Body*)fourthStage_)->setPosition(position);
  ((Body*)fourthStage_)->setImageHight(imageHight);
  ((Body*)fourthStage_)->setImagePath(image);
  ((Body*)fourthStage_)->setMass(mass);

  fourthStage_->setForcePoint(forcePoint);

  ((Body*)fourthStage_)->build(world);
}
