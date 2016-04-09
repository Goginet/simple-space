#include "../include/FirstState.h"

FirstState::FirstState(): State(), scale_(30)
{
  world_ = new b2World(b2Vec2(0.0, 0.0), false);

  rocket_ = new RocketNasaSls(world_);

  createGround(world_);


  view_.setCenter(sf::Vector2f(0, 0));
  view_.setSize(sf::Vector2f(1400 * 1.5, 900 * 1.5));

}

void FirstState::render()
{
  b2Vec2 pos = rocket_->getPosition(scale_);

  drawBackground(window,b2Vec2(1400,900),pos);
  if(pos.y < -460)
    view_.setCenter(sf::Vector2f(pos.x, pos.y));
  else
    view_.setCenter(sf::Vector2f(pos.x, -460));
  window->setView(view_);

  //TODO : сделать отображение информации о ракете
  //drawInfo(window);

  rocket_->render(window, scale_);

  ground_->render(window,30,pos);
}

float computeGravity(float r);

void FirstState::update(unsigned int deltaTime)
{
  rocket_->update();

  // TODO: переделать когда планета станет круглой
  world_->SetGravity(b2Vec2(0, -computeGravity(rocket_->getPlanetDistance(scale_))));

  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world_->Step(timeStep, velocityIterations, positionIterations);
}

void FirstState::control(sf::Event event)
{
  float powerStep = 1000;
  float angleStep = 1;

  switch(event.type)
  {
    case sf::Event::KeyPressed:
    {

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
      {
        rocket_->turnLeft(angleStep);
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
      {
        rocket_->turnRight(angleStep);
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
        rocket_->powerUp(powerStep);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
        rocket_->powerDown(powerStep);
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      {
        rocket_->firstStageDisconnect();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
      {
        rocket_->secondStageDisconect();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
      {
        rocket_->thirdStageDisconect();
      }
    }
    break;

    default:
    break;
  }
}

float computeGravity(float r)
{
  float G = 6.67408 * pow(10, 13);
  float M = 5.97;
  float R = 6371 * 1000;
  return (G * M) / pow((R + r),2);
}

//
// void FirstState::drawInfo(sf::RenderWindow *window)
// {
//   sf::Font font;
//   if (!font.loadFromFile("font.ttf"))
//   {
//     float hight = rocket->getPlanetDistance();
//     std::string str = "hight - " + std::to_string(hight) +
//       "gravity - " + std::to_string(computeGravity(hight));
//
//     sf::Text text;
//
//     text.setFont(font);
//
//     text.setString("Hello world");
//
//     text.setCharacterSize(24);
//
//     text.setColor(sf::Color::Red);
//
//     text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//
//     text.setPosition(rocket->getPosition().x + 100,
//                             rocket->getPosition().y + 100);
//
//     window->draw(text);
//   }
// }
