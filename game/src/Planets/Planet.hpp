/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <Box2D/Box2D.h>
#include <string>
#include "../../../LGE/Physics.hpp"

class Planet {
  public:
    static constexpr float GROUND_WIDTH_B2M = 300;
    static constexpr float GROUND_HIGHT_B2M = 100;
    static constexpr float GENERATE_GROUND_DISTANCE = 50;
    static constexpr float IMAGE_WIDTH = 1050;
    static constexpr float IMAGE_HIGHT = 525;

    Planet(b2Vec2 position, b2Vec2 imageCentre, float zoom,
           std::string image, float radius);

    // проверяет содержит ли планета данную точку
    bool isContainsInGlobal(double x, double y);

    // проверяет выход за границы планеты
    bool isContainsInPlanet(double x, double y);

    // проверяет видна ли земля
    bool isGroundVisible(double x, double y);

    // проверяет
    bool isGroundLoad();

    // прогружает землю
    void loadingGround(b2World *world, double x, double y);

    // удаляет землю
    void destroyGround();

    // рисует планету в глобальном мире
    void renderGlobalPlanet(sf::RenderWindow *window, float scale,
                            float zoom);

    // рисует видимую локальную часть планеты
    void renderLocalPlanet(sf::RenderWindow *window, float scale,
                           b2Vec2 eyeCentre);

    void setMapMinSize(float size);
  protected:
    // минимальный допустимый размер планеты на миникарте
    float mapMinSize_;

    // радиус планеты (реальный)
    double radius_;

    // зум для подгона картинки
    float zoom_;

    // позиция планеты в солнечной системе
    b2Vec2 position_;

    // для центрирования картинки (ширина / 2, высота / 2)
    b2Vec2 imageCentre_;

    // текстура планеты на миникарте
    sf::Texture texture_;

    // физическая часть земли(NULL если не прогруженна)
    // LgePhysicalComplexBody *ground_;

    // путь к картинке земли
    std::string imageGround_;
};

#endif /* end of include guard: PLANET_HPP_ */
