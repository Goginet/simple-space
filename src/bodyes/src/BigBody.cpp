#include "../include/BigBody.h"

#define PI 3.14159265359

BigBody::BigBody(b2World *world, b2Vec2 **vertices, const int verticesCount,
                 int *verticesSizes, float density, float restitution,
                 b2Vec2 position, float imageHight,std::string imagePath,
                 b2Vec2 step)
{
  step_ = step;

  imageHight_ = imageHight;
  imagePath_ = imagePath;

  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
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

void BigBody::render(sf::RenderWindow *window, float scale, b2Vec2 centerView)
{
  // TODO : временно

  const int Y = -14.729640922146643;

  sf::Texture texture;
  if (texture.loadFromFile(imagePath_))
  {
    int x = centerView.x / scale;
    float position = x - (((x * 100) % (int)(step_.x * 100)) / 100);
    renderAt(window, texture, scale, b2Vec2(position + 20, Y));
    renderAt(window, texture, scale, b2Vec2(position, Y));
    renderAt(window, texture, scale, b2Vec2(position - 20, Y));
    renderAt(window, texture, scale, b2Vec2(position + 40, Y));
    renderAt(window, texture, scale, b2Vec2(position - 40, Y));
    renderAt(window, texture, scale, b2Vec2(position + 60, Y));
    renderAt(window, texture, scale, b2Vec2(position - 60, Y));
    renderAt(window, texture, scale, b2Vec2(position - 80, Y));
  }
}

void BigBody::renderAt(sf::RenderWindow *window,sf::Texture texture,
                       float scale, b2Vec2 position)
{
    float localPointX = (position.x );
    float localPointY = (position.y);

    float x = localPointX * scale;
    float y = -localPointY * scale;
    float angle = body_->GetAngle();

    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.setOrigin(0.0f, imageHight_);
    sprite.setRotation(-(angle* 180) / PI);
    sprite.setPosition(x,y);
    window->draw(sprite);
}
