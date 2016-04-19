#include "Body.hpp"

#define PI 3.14159265359

Body::Body(b2Vec2 **vertices, int verticesCount, int *verticesSizes)
{
  vertices_ = vertices;
  verticesCount_ = verticesCount;
  verticesSizes_ = verticesSizes;
}

void Body::build(b2World *world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(position_.x, position_.y);

  body_ = world -> CreateBody(&bodyDef);

  for(int i = 0; i < verticesCount_; i++)
  {
    b2PolygonShape polygon;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygon;
    fixtureDef.density = density_;
    fixtureDef.restitution = restitution_;

    polygon.Set(vertices_[i], verticesSizes_[i]);

    body_->CreateFixture(&fixtureDef);
  }

  b2MassData *massData = new b2MassData();
  massData->mass = mass_;
  body_->SetMassData(massData);
  body_->SetFixedRotation(false);
}

void Body::destroy()
{
  b2World *world = body_->GetWorld();
  world->DestroyBody(body_);
  body_ = NULL;
}

void Body::setDensity(float density)
{
  density_ = density;
}

void Body::setRestitution(float restitution)
{
  restitution_ = restitution;
}

void Body::setPosition(b2Vec2 position)
{
  position_ = position;
}

b2Vec2 Body::getPosition()
{
  b2Vec2 bodyPosition = body_->GetPosition();
  float x = bodyPosition.x;
  float y = -bodyPosition.y;
  return b2Vec2(x, y);
}

void Body::setImageHight(float hight)
{
  imageHight_ = hight;
}

void Body::setImagePath(std::string path)
{
  imagePath_ = path;
}

void Body::setMass(float mass)
{
  mass_ = mass;
}

void Body::render(sf::RenderWindow *window, float scale)
{
  sf::Sprite sprite;
  sf::Texture texture;
  if (texture.loadFromFile(imagePath_))
  {
    b2Vec2 bodyPosition = body_->GetPosition();
    float x = bodyPosition.x * scale;
    float y = -bodyPosition.y * scale;
    float angle = body_->GetAngle();


    sprite.setTexture(texture);
    sprite.setOrigin(0.0f, imageHight_);
    sprite.setRotation(-(angle* 180) / PI);
    sprite.setPosition(x,y);
    window->draw(sprite);
  }
}

b2RevoluteJoint* Body::createJoint(Body *body, b2Vec2 point)
{
  b2RevoluteJointDef jointDef;
  jointDef.Initialize(body_, body->body_, point);
  return (b2RevoluteJoint*)body_->GetWorld()->CreateJoint(&jointDef);
}
