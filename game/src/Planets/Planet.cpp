/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "Planet.hpp"
#include <string>

#define PI 3.14

Planet::Planet(b2Vec2 position, b2Vec2 imageCentre, float zoom,
               std::string image, float radius) {
  radius_ = radius;
  position_ = position;
  imageCentre_ = imageCentre;
  texture_.loadFromFile(image);
  zoom_ = zoom;
  // ground_ = NULL;
  imageGround_ = "../res/earth_ground.png";
}

void Planet::renderGlobalPlanet(sf::RenderWindow *window, float scale,
                                float zoom) {
  float x = position_.x * scale;
  float y = -position_.y * scale;

  sf::Sprite sprite;
  sprite.setTexture(texture_);

  sprite.setOrigin(imageCentre_.x, imageCentre_.y);
  sprite.setPosition(x, y);
  if ((radius_ * scale) / zoom < mapMinSize_) {
    float extra = mapMinSize_ / ((radius_ * scale) / zoom);
    sprite.setScale(zoom_ * extra, zoom_ * extra);
  } else {
    sprite.setScale(zoom_, zoom_);
  }
  window->draw(sprite);
}

bool Planet::isContainsInGlobal(double x, double y) {
  // TODO(Goginet): проверяет содержит ли планета точку
  return true;
}

bool Planet::isGroundVisible(double x, double y) {
  if (abs(x) < radius_ + GENERATE_GROUND_DISTANCE &&
      abs(y) < radius_ + GENERATE_GROUND_DISTANCE) {
    float distance = sqrt(pow(x, 2) + pow(y, 2));
    if (distance < radius_ + GENERATE_GROUND_DISTANCE) {
      return true;
    }
  }
  return false;
}

bool Planet::isGroundLoad() {
  // if (ground_ != NULL) {
  //   return true;
  // } else {
  //   return false;
  // }
}


void Planet::loadingGround(b2World *world, double x, double y) {
  // TODO(Goginet): загружает землю по указанным планетным координатам

  // что бы не было нуля)
  x += (x == 0) ? 1:0;
  y += (y == 0) ? 1:0;

  double distance = sqrt(pow(x, 2) + pow(y, 2));
  float angle = atan(abs(x / y));
  float sinx = x / distance;
  float cosx = y / distance;

  if (x > 0 && y > 0) {
    angle += 0;
  } else if (x > 0 && y < 0) {
    angle = PI - angle;
  } else if (x < 0 && y < 0) {
    angle = PI + angle;
  } else if (x < 0 && y > 0) {
    angle = 2 * PI - angle;
  }


  int COUNT = 1;

  int const VERTICES_GROUND = 4;

  b2Vec2 **vertices = new b2Vec2*[COUNT];

  int *verticesSizes = new int[COUNT];
  verticesSizes[0] = VERTICES_GROUND;

  b2Vec2 *verticesGround = new b2Vec2[VERTICES_GROUND];
  verticesGround[0] = b2Vec2(0, -GROUND_HIGHT_B2M);
  verticesGround[1] = b2Vec2(GROUND_WIDTH_B2M / 2, -GROUND_HIGHT_B2M);
  verticesGround[2] = b2Vec2(GROUND_WIDTH_B2M / 2, 0);
  verticesGround[3] = b2Vec2(-GROUND_WIDTH_B2M / 2, 0);

  vertices[0] = verticesGround;

  // ground_ = new LgePhysicalComplexBody(vertices, COUNT, verticesSizes);
  //
  // ground_->setRestitutionDef(0);
  // ground_->setPositionDef(b2Vec2(-GENERATE_GROUND_DISTANCE * sinx,
  //                                -GENERATE_GROUND_DISTANCE * cosx));
  // ground_->setRenderCentre(IMAGE_WIDTH / 2, 0);
  // ground_->loadImage(imageGround_);
  // ground_->setBodyTypeDef(b2_staticBody);
  // ground_->setAngleDef(-angle);
  //
  // ground_->build(world);
}

void Planet::destroyGround() {
  // ground_->destroy();
  // ground_ = NULL;
}


void Planet::renderLocalPlanet(sf::RenderWindow *window, float scale,
                               b2Vec2 eyeCentre) {
  // if (ground_ != NULL) {
  //   int position = ground_->getStepPosition(scale, IMAGE_WIDTH, eyeCentre);
  //   ground_->renderAt(window, scale, position + 3, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position + 2, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position + 1, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 1, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 2, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 3, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 4, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 5, IMAGE_WIDTH);
  //   ground_->renderAt(window, scale, position - 6, IMAGE_WIDTH);
  // }
}

void Planet::setMapMinSize(float size) {
  mapMinSize_ = size;
}
