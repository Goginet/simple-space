#include "Body.hpp"

#define PI 3.14159265359

Body::Body(b2World *world, b2Vec2 **vertices, const int verticesCount,
            int *verticesSizes, float density, float restitution,
            b2Vec2 position, float imageHight,std::string imagePath)
{
  imageHight_ = imageHight;
  imagePath_ = imagePath;

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(position.x, position.y);

  body_ = world -> CreateBody(&bodyDef);

  for(int i = 0; i < verticesCount; i++)
  {
    b2PolygonShape polygon;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygon;
    fixtureDef.density = density;
    fixtureDef.restitution = restitution;

    polygon.Set(vertices[i], verticesSizes[i]);

    body_->CreateFixture(&fixtureDef);
  }

  body_->SetFixedRotation(false);
};

void Body::setMass(float mass)
{
  b2MassData *massData = new b2MassData();
  massData->mass = mass;
  body_->SetMassData(massData);
  body_->SetFixedRotation(false);
}



void Body::setImagePath(std::string path)
{
  imagePath_ = path;

}

void Body::setImageHight(float hight)
{
  imageHight_ = hight;
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

b2Vec2 Body::getPosition(float scale)
{
    b2Vec2 bodyPosition = body_->GetPosition();
    float x = bodyPosition.x * scale;
    float y = -bodyPosition.y * scale;
    return b2Vec2(x, y);
}

b2RevoluteJoint* Body::createJoint(Body *body, b2Vec2 point)
{
  b2RevoluteJointDef jointDef;
  jointDef.Initialize(body_, body->body_, point);
  return (b2RevoluteJoint*)body_->GetWorld()->CreateJoint(&jointDef);
}
