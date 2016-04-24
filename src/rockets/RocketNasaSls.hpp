/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef ROCKET_H
#define ROCKET_H

#include <Box2D/Box2D.h>
#include<string>

#include "../bodyes/RocketSegment.hpp"

class RocketNasaSls {
 public:
  explicit RocketNasaSls(b2World *world);
  void firstStageDisconnect();
  void secondStageDisconect();
  void thirdStageDisconect();
  void fourhStageDisconect();
  void fifthStageDisconect();
  void powerUp(float powerStep);
  void powerDown(float powerStep);
  void turnLeft(float angleStep);
  void turnRight(float angleStep);
  void goForward();
  void update();
  float getPlanetDistance(float scale);
  void render(sf::RenderWindow *window, float scale);
  b2Vec2 getPosition();

 private:
  b2World * world_;

  float angle_;
  float power_;
  int stage_;

  RocketSegment *fourthStage_;
  RocketSegment *thirdStage_;
  RocketSegment *secondStage_;
  RocketSegment *firstStageLeft_;
  RocketSegment *firstStageRight_;

  b2RevoluteJoint* thirdStageJoint1;
  b2RevoluteJoint* thirdStageJoint2;
  b2RevoluteJoint* secondStageJoint1;
  b2RevoluteJoint* secondStageJoint2;
  b2RevoluteJoint* firstStageJoint1Left;
  b2RevoluteJoint* firstStageJoint2Left;
  b2RevoluteJoint* firstStageJoint1Right;
  b2RevoluteJoint* firstStageJoint2Right;

  b2Vec2 fourthStagePosition_;
  std::string fourthStageImage_;
  float fourthStageImageHight_;
  float fourthStageImageDensity_;
  float fourthStageImageRestitution_;
  float fourthStageMass_;
  b2Vec2 fourthStageForcePoint_;

  b2Vec2 thirdStagePosition_;
  std::string thirdStageImage_;
  float thirdStageImageHight_;
  float thirdStageImageDensity_;
  float thirdStageImageRestitution_;
  float thirdStageMass_;
  b2Vec2 thirdStageForcePoint_;

  b2Vec2 secondStagePosition_;
  std::string secondStageImage_;
  float secondStageImageHight_;
  float secondStageImageDensity_;
  float secondStageImageRestitution_;
  float secondStageMass_;
  b2Vec2 secondStageForcePoint_;

  b2Vec2 firstStageLeftPosition_;
  std::string firstStageLeftImage_;
  float firstStageLeftImageHight_;
  float firstStageLeftImageDensity_;
  float firstStageLeftImageRestitution_;
  float firstStageLeftMass_;
  b2Vec2 firstStageLeftForcePoint_;

  b2Vec2 firstStageRightPosition_;
  std::string firstStageRightImage_;
  float firstStageRightImageHight_;
  float firstStageRightImageDensity_;
  float firstStageRightImageRestitution_;
  float firstStageRightMass_;
  b2Vec2 firstStageRightForcePoint_;

  void createFourthStage(b2World *world, b2Vec2 position, std::string image,
                         float imageHight, float density, float restitution,
                         float mass, b2Vec2 forcePoint);

  void createThirdStage(b2World *world, b2Vec2 position, std::string image,
                        float imageHight, float density, float restitution,
                        float mass, b2Vec2 forcePoint);

  void createSecondStage(b2World *world, b2Vec2 position, std::string image,
                        float imageHight, float density, float restitution,
                        float mass, b2Vec2 forcePoint);

  void createFirstStageLeft(b2World *world, b2Vec2 position,
                            std::string image, float imageHight,
                            float density, float restitution,
                            float mass, b2Vec2 forcePoint);

  void createFirstStageRight(b2World *world, b2Vec2 position,
                             std::string image, float imageHight,
                             float density, float restitution,
                             float mass, b2Vec2 forcePoint);
};


#endif /* end of include guard: ROCKET_H */
