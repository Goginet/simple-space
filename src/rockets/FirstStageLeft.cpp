/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include <string>
#include "RocketNasaSls.hpp"

void RocketNasaSls::createFirstStageLeft(b2World *world, b2Vec2 position,
                                         std::string image,
                                         float imageHight,
                                         float density,
                                         float restitution,
                                         float mass,
                                         b2Vec2 forcePoint) {
  int COUNT = 3;

  int const VERTICES_TRUNK = 4;
  int const VERTICES_ENGINE = 6;
  int const VERTICES_UP = 6;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int verticesSizes[COUNT] = {
    VERTICES_TRUNK,
    VERTICES_ENGINE,
    VERTICES_UP
  };

  float ZOOM = 0.46482036570588986f;
  b2Vec2 verticesTrunk[VERTICES_TRUNK] = {
    b2Vec2(0.07500000298023224 * ZOOM, 1.524999976158142 * ZOOM),
    b2Vec2(0.925000011920929 * ZOOM, 1.524999976158142 * ZOOM),
    b2Vec2(0.925000011920929 * ZOOM, 11.52500057220459 * ZOOM),
    b2Vec2(0.07500000298023224 * ZOOM, 11.52500057220459 * ZOOM)
  };

  b2Vec2 verticesEngine[VERTICES_ENGINE] = {
    b2Vec2(0 * ZOOM, 0 * ZOOM),
    b2Vec2(1 * ZOOM, 0 * ZOOM),
    b2Vec2(1 * ZOOM, 0.75 * ZOOM),
    b2Vec2(0.925000011920929 * ZOOM, 1.524999976158142 * ZOOM),
    b2Vec2(0.07500000298023224 * ZOOM, 1.524999976158142 * ZOOM),
    b2Vec2(0 * ZOOM, 0.75 * ZOOM)
  };

  b2Vec2 verticesUp[VERTICES_UP] = {
    b2Vec2(0.07500000298023224 * ZOOM, 11.52500057220459 * ZOOM),
    b2Vec2(0.925000011920929 * ZOOM, 11.52500057220459 * ZOOM),
    b2Vec2(0.625 * ZOOM, 12.350000381469727 * ZOOM),
    b2Vec2(0.5250000357627869 * ZOOM, 12.449999809265137 * ZOOM),
    b2Vec2(0.4749999940395355 * ZOOM, 12.449999809265137 * ZOOM),
    b2Vec2(0.375 * ZOOM, 12.350000381469727 * ZOOM)
  };

  vertices[0] = verticesTrunk;
  vertices[1] = verticesEngine;
  vertices[2] = verticesUp;

  forcePoint.x = forcePoint.x * ZOOM;
  forcePoint.y = forcePoint.y * ZOOM;

  position.x = position.x * ZOOM;
  position.y = position.y * ZOOM;

  firstStageLeft_ = new RocketSegment(vertices, COUNT, verticesSizes);

  ((Body*)firstStageLeft_)->setDensity(density);
  ((Body*)firstStageLeft_)->setRestitution(restitution);
  ((Body*)firstStageLeft_)->setPosition(position);
  ((Body*)firstStageLeft_)->setImageHight(imageHight);
  ((Body*)firstStageLeft_)->setImagePath(image);
  ((Body*)firstStageLeft_)->setMass(mass);

  firstStageLeft_->setForcePoint(forcePoint);

  ((Body*)firstStageLeft_)->build(world);

}
