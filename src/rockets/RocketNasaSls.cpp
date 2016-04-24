/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "RocketNasaSls.hpp"

#define PI 3.14159265359

RocketNasaSls::RocketNasaSls(b2World *world):
fourthStagePosition_(b2Vec2(0.0f, 1.1750000715255737f + 8.949999809265137f -
                            0.3499999940395355- 0.375)),
fourthStageImage_("../res/stage4.png"),
fourthStageImageHight_(103),
fourthStageImageDensity_(1.0f),
fourthStageImageRestitution_(0.0f),
fourthStageMass_(4000),
fourthStageForcePoint_(b2Vec2(0.5f, 0.1f)),

thirdStagePosition_(b2Vec2(0.0f, 8.949999809265137f - 0.375)),
thirdStageImage_("../res/stage3.png"),
thirdStageImageHight_(42),
thirdStageImageDensity_(1.0f),
thirdStageImageRestitution_(0.0f),
thirdStageMass_(3000),
thirdStageForcePoint_(b2Vec2(0.5f, 0.1f)),

secondStagePosition_(b2Vec2(0.0f, 0.0f)),
secondStageImage_("../res/stage2.png"),
secondStageImageHight_(267),
secondStageImageDensity_(1.0f),
secondStageImageRestitution_(0.0f),
secondStageMass_(8000),
secondStageForcePoint_(b2Vec2(0.5f, 0.1f)),

firstStageLeftPosition_(b2Vec2(-1.0f, 0.0f)),
firstStageLeftImage_("../res/stage1L.png"),
firstStageLeftImageHight_(174),
firstStageLeftImageDensity_(1.0f),
firstStageLeftImageRestitution_(0.0f),
firstStageLeftMass_(7000),
firstStageLeftForcePoint_(b2Vec2(0.5f, 0.1f)),

firstStageRightPosition_(b2Vec2(1.0f, 0.0f)),
firstStageRightImage_("../res/stage1R.png"),
firstStageRightImageHight_(174),
firstStageRightImageDensity_(1.0f),
firstStageRightImageRestitution_(0.0f),
firstStageRightMass_(7000),
firstStageRightForcePoint_(b2Vec2(0.5f, 0.1f)) {
  world_ = world;

  createFourthStage(world, fourthStagePosition_, fourthStageImage_,
                    fourthStageImageHight_, fourthStageImageDensity_,
                    fourthStageImageRestitution_, fourthStageMass_,
                    fourthStageForcePoint_);

  createThirdStage(world, thirdStagePosition_, thirdStageImage_,
                   thirdStageImageHight_, thirdStageImageDensity_,
                   thirdStageImageRestitution_, thirdStageMass_,
                   thirdStageForcePoint_);

  createSecondStage(world, secondStagePosition_, secondStageImage_,
                    secondStageImageHight_, secondStageImageDensity_,
                    secondStageImageRestitution_, secondStageMass_,
                    secondStageForcePoint_);

  createFirstStageLeft(world, firstStageLeftPosition_, firstStageLeftImage_,
                       firstStageLeftImageHight_, firstStageLeftImageDensity_,
                       firstStageLeftImageRestitution_, firstStageLeftMass_,
                       firstStageLeftForcePoint_);

  createFirstStageRight(world, firstStageRightPosition_, firstStageRightImage_,
                       firstStageRightImageHight_, firstStageRightImageDensity_,
                       firstStageRightImageRestitution_, firstStageRightMass_,
                       firstStageRightForcePoint_);


  thirdStageJoint1 = ((Body*)fourthStage_)->createJoint((Body*)thirdStage_,
                      b2Vec2(0, 8.949999809265137f + 1.5750000476837158));
  thirdStageJoint2 = ((Body*)fourthStage_)->createJoint((Body*)thirdStage_,
                      b2Vec2(1, 8.949999809265137f + 1.5750000476837158));
  secondStageJoint1 = ((Body*)thirdStage_)->createJoint((Body*)secondStage_,
                      b2Vec2(0.07500000298023224, 8.949999809265137f));
  secondStageJoint2 = ((Body*)thirdStage_)->createJoint((Body*)secondStage_,
                      b2Vec2(0.925000011920929, 8.949999809265137f));

  firstStageJoint1Left = ((Body*)secondStage_)->
  createJoint((Body*)firstStageLeft_, b2Vec2(0, 5.550000190734863));
  firstStageJoint2Left = ((Body*)secondStage_)->
  createJoint((Body*)firstStageLeft_, b2Vec2(0, 3.550000190734863));

  firstStageJoint1Right = ((Body*)secondStage_)->
  createJoint((Body*)firstStageRight_, b2Vec2(1, 5.550000190734863));
  firstStageJoint2Right = ((Body*)secondStage_)->
  createJoint((Body*)firstStageRight_, b2Vec2(1, 3.550000190734863));


  angle_ = 0 * (PI / 180);
  power_ = 0;
  stage_ = 1;
}

void RocketNasaSls::firstStageDisconnect() {
  if (stage_ == 1) {
    world_ ->DestroyJoint(firstStageJoint1Left);
    world_ ->DestroyJoint(firstStageJoint2Left);
    world_ ->DestroyJoint(firstStageJoint1Right);
    world_ ->DestroyJoint(firstStageJoint2Right);
    stage_ = 2;
  }
}

void RocketNasaSls::secondStageDisconect() {
  if (stage_ == 2) {
    world_ ->DestroyJoint(secondStageJoint1);
    world_ ->DestroyJoint(secondStageJoint2);
    stage_ = 3;
  }
}

void RocketNasaSls::thirdStageDisconect() {
  if (stage_ == 3) {
    world_ ->DestroyJoint(thirdStageJoint1);
    world_ ->DestroyJoint(thirdStageJoint2);
    stage_ = 4;
  }
}

void RocketNasaSls::powerUp(float powerStep) {
  if (power_ < powerStep * 6) {
    power_ += powerStep;
  }
}


void RocketNasaSls::powerDown(float powerStep) {
  if (power_ > 0) {
    power_ -= powerStep;
  }
}


void RocketNasaSls::turnLeft(float angleStep) {
    angle_ = angleStep;
}


void RocketNasaSls::turnRight(float angleStep) {
    angle_ = -angleStep;
}

void RocketNasaSls::goForward() {
    angle_ = 0;
}

void RocketNasaSls::render(sf::RenderWindow *window, float scale) {
  ((Body*)fourthStage_) -> render(window, scale);
  ((Body*)thirdStage_) -> render(window, scale);
  ((Body*)secondStage_) -> render(window, scale);
  ((Body*)firstStageLeft_) -> render(window, scale);
  ((Body*)firstStageRight_) -> render(window, scale);
}

void RocketNasaSls::update() {
  switch (stage_) {
    case 1:
      ((RocketSegment*)firstStageLeft_) -> setPower(power_, angle_);
      ((RocketSegment*)firstStageRight_) -> setPower(power_, angle_);
      ((RocketSegment*)secondStage_) -> setPower(power_, angle_);
    break;

    case 2:
      ((RocketSegment*)secondStage_) -> setPower(power_, angle_);
      ((RocketSegment*)firstStageLeft_) -> setPower(0, angle_);
      ((RocketSegment*)firstStageRight_) -> setPower(0, angle_);
    break;

    case 3:
      ((RocketSegment*)thirdStage_) -> setPower(power_, angle_);
      ((RocketSegment*)secondStage_) -> setPower(0, angle_);
      ((RocketSegment*)firstStageLeft_) -> setPower(0, angle_);
      ((RocketSegment*)firstStageRight_) -> setPower(0, angle_);
    break;

    case 4:
      ((RocketSegment*)fourthStage_) -> setPower(power_, angle_);
      ((RocketSegment*)thirdStage_) -> setPower(0, angle_);
      ((RocketSegment*)firstStageLeft_) -> setPower(0, angle_);
      ((RocketSegment*)firstStageRight_) -> setPower(0, angle_);
      ((RocketSegment*)secondStage_) -> setPower(0, angle_);
    break;
  }
  angle_ = 0;
}

float RocketNasaSls::getPlanetDistance(float scale) {
  return getPosition().y / scale;
}

b2Vec2 RocketNasaSls::getPosition() {
  return ((Body*)fourthStage_) -> getPosition();
}
