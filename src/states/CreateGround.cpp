/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "FirstState.hpp"


void FirstState::createGround(b2World *world) {
  int COUNT = 1;

  int const VERTICES = 4;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int verticesSizes[COUNT] = {
    VERTICES
  };

  b2Vec2 vertices1[VERTICES] = {
    b2Vec2(0, 0),
    b2Vec2(10000000, 0),
    b2Vec2(10000000, 14.729640922146643),
    b2Vec2(0, 14.729640922146643)
  };

  vertices[0] = vertices1;

  ground_ = new BigBody(world, vertices, COUNT, verticesSizes, 1, 0,
                        b2Vec2(-10000000 / 2, -14.729640922146643), 441,
                        "../res/ground.jpg", b2Vec2(20, 0));
}
