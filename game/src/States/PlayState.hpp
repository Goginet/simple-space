/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include <string>
#include <iostream>

#include "../../../LGE/GameManager.hpp"
#include "../Planets/Planet.hpp"

class PlayState: public Lge::State {
 public:
  /* размеры этого состояния в пикселях */
  static constexpr float STATE_WIDTH = 1920;
  static constexpr float STATE_HEIGHT = 1080;

  /* КООРДИНАТЫ объектов */


  /* размеры тел */


  /* ID Кнопок на экране */



  /****************************************************************************/
  /*                          STATE RESURSES PATH                             */
  /****************************************************************************/

  /*                            IMAGES PATH                                   */
  const std::string BACKGROUND_IMAGE_PATH = \
  ADD_RES_PATH("/images/backgrounds/space_global.png");
  const std::string MERCURY_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/mercuryico.png");
  const std::string VENUS_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/venusico.png");
  const std::string EARTH_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/earthico.png");
  const std::string MARS_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/marsico.png");
  const std::string JUPITER_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/jupiterico.png");
  const std::string SATURN_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/saturnico.png");
  const std::string URAN_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/uranico.png");
  const std::string NEPTUNE_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/neptuneico.png");
  const std::string PLUTON_IMAGE_PATH = \
  ADD_RES_PATH("/images/planets/plutonico.png");

  /*                              SOUND PATH                                  */


  /*                              TEXT PATH                                   */


  /****************************************************************************/
  /*                         STATE INITIALIZATION                             */
  /****************************************************************************/

  /* Инициализация/загрузка объектов для этого состояния */
  PlayState() {
    zoom_ = 1;
    scaleLocal_ = 30;
    scaleGlobal_ = 1.0 / 1000;
    globalLocalRatio_ = 1000;
    viewMode_ = GLOBAL_VIEW;
    eyeCentre_.x = 0;
    eyeCentre_.y = 0;
    backgroundMapPosition_.x = 3750;
    backgroundMapPosition_.y = 3750;
    zoomMapBackground_ = 1;


    // мир для симуляции физики
    // localWorld_ = new b2World(b2Vec2(0.0, 0.0), false);

    // Создание ракеты
    // rocket_ = new Ranger(localWorld_, b2Vec2(0, 0));

    // Создание планет
    createPlanets();

    /* загрузка заднего фона карты */
    backgroundMapTexture_.loadFromFile(BACKGROUND_IMAGE_PATH);

    mainView_.setSize(sf::Vector2f(1920 * zoom_, 1080 * zoom_));

    // rocket_->globalX_ = 0;
    // rocket_->globalY_ = 0;
  }

  /****************************************************************************/
  /*                              STATE DESTROY                               */
  /****************************************************************************/

  /* удаление всех объектов этого сотояния */
  ~PlayState() {}

  /****************************************************************************/
  /*                               STATE RENDER                               */
  /****************************************************************************/

  /* отрисовка содержимого этого состояния */
  void render() {
    // управление камерой
    SAFE_VIEW_RATIO(mainView_, STATE_WIDTH  * zoom_, STATE_HEIGHT, window_);
    mainView_.setCenter(eyeCentre_.x, eyeCentre_.y);
    window_->setView(mainView_);

    if (viewMode_ == GLOBAL_VIEW) {
      drawMapBackground();
      // rocket_->renderGLobal(window_, scaleGlobal_, zoom_);
      for (int i = 0; i < 9; i++) {
        planets_[i]->renderGlobalPlanet(window_, scaleGlobal_, zoom_);
      }
    } else if (viewMode_ == LOCAL_VIEW) {
      // // отрисовка ракеты
      // rocket_->render(window_, scaleLocal_);
      //
      // // отрисовка активной части планеты
      // if (activePlanet_ != NULL) {
      //   activePlanet_->renderLocalPlanet(window_, scaleLocal_, eyeCentre_);
      // }
    }
  }

  /****************************************************************************/
  /*                               STATE UPDATE                               */
  /****************************************************************************/

  /* обновление логики в этом состоянии */
  void update() {
  }

  /****************************************************************************/
  /*                              STATE CONTROL                               */
  /****************************************************************************/

  /* обработка событий случившихся в этом состоянии */
  void control(sf::Event event) {
    float powerStep = 1000;
    float angleStep = 3.14 / 2;

    static bool isMosePressed = false;

    static float x = 0;
    static float y = 0;

    switch (event.type) {
      case sf::Event::KeyPressed:
      {
      }
      break;

      case sf::Event::MouseButtonPressed:
        isMosePressed = true;
        x = event.mouseButton.x;
        y = event.mouseButton.y;
      break;

      case sf::Event::MouseButtonReleased:
        isMosePressed = false;
      break;

      case sf::Event::MouseMoved:
      if (isMosePressed) {
        eyeCentre_.x += (x - event.mouseMove.x) * zoom_;
        eyeCentre_.y += (y - event.mouseMove.y) * zoom_;
        backgroundMapPosition_.x += (x - event.mouseMove.x) * (1 / zoom_) * 2;
        backgroundMapPosition_.y += (y - event.mouseMove.y) * (1 / zoom_) * 2;
        if (backgroundMapPosition_.x > 3750 + 1500 ||
            backgroundMapPosition_.x < 3750 - 1500)
          backgroundMapPosition_.x = 3750;
        if (backgroundMapPosition_.y > 3750  + 1500 ||
            backgroundMapPosition_.y < 3750 - 1500)
          backgroundMapPosition_.y = 3750;
        x = event.mouseMove.x;
        y = event.mouseMove.y;
      }
      break;

      case sf::Event::MouseWheelMoved:
      {
          zoom_ += event.mouseWheel.delta * (zoom_ * 0.1);
          zoomMapBackground_ += event.mouseWheel.delta *
                                (zoomMapBackground_ * 0.09);
      }
      break;

      default:
      break;
    }
  }

  void createPlanets() {
    planets_ = new Planet*[9];

    float MERCURY_IMAGE_PX = 500;
    float VENUS_IMAGE_PX = 1200;
    float EARTH_IMAGE_PX = 1200;
    float MARS_IMAGE_PX = 535;
    float JUPITER_IMAGE_PX = 1000;
    float SATURN_IMAGE_PX = 415;
    float SATURN_IMAGE_WIDTH_PX = 1000;
    float URAN_IMAGE_PX = 629;
    float NEPTUNE_IMAGE_PX = 728;
    float PLUTON_IMAGE_PX = 842;

    float MERCURY_RADIUS = 2440000;
    float VENUS_RADIUS = 6052000;
    float EARTH_RADIUS = 6371000;
    float MARS_RADIUS = 3390000;
    float JUPITER_RADIUS = 69911000;
    float SATURN_RADIUS = 58222000;
    float URAN_RADIUS = 25362000;
    float NEPTUNE_RADIUS = 24622000;
    float PLUTON_RADIUS = 118600;

    float MERCURY_DISTANCE = 57910000000;
    float VENUS_DISTANCE = 108200000000;
    float EARTH_DISTANCE = 149600000000;
    float MARS_DISTANCE = 227900000000;
    float JUPITER_DISTANCE = 778500000000;
    float SATURN_DISTANCE = 1429000000000;
    float URAN_DISTANCE = 2877000000000;
    float NEPTUNE_DISTANCE = 4498000000000;
    float PLUTON_DISTANCE = 5906507000000;

    {
      float imageZoom = (MERCURY_RADIUS * scaleGlobal_)
                      / MERCURY_IMAGE_PX;
      planets_[0] = new Planet(b2Vec2(MERCURY_DISTANCE, 0),
                             b2Vec2(MERCURY_IMAGE_PX / 2, MERCURY_IMAGE_PX / 2),
                              imageZoom, MERCURY_IMAGE_PATH,
                              MERCURY_RADIUS);
      planets_[0]->setMapMinSize(MERCURY_RADIUS / 500000);
    }
    {
      float imageZoom = (VENUS_RADIUS * scaleGlobal_)
                        / VENUS_IMAGE_PX;
      planets_[1] = new Planet(b2Vec2(VENUS_DISTANCE, 0),
                               b2Vec2(VENUS_IMAGE_PX / 2, VENUS_IMAGE_PX / 2),
                               imageZoom, VENUS_IMAGE_PATH,
                               VENUS_RADIUS);
      planets_[1]->setMapMinSize(VENUS_RADIUS / 500000);
    }
    {
      float imageZoom = (EARTH_RADIUS * scaleGlobal_)
                        / EARTH_IMAGE_PX;
      planets_[2] = new Planet(b2Vec2(EARTH_DISTANCE, 0),
                               b2Vec2(EARTH_IMAGE_PX / 2, EARTH_IMAGE_PX / 2),
                               imageZoom, EARTH_IMAGE_PATH,
                               EARTH_RADIUS);
      planets_[2]->setMapMinSize(EARTH_RADIUS / 500000);
    }
    {
      float imageZoom = (MARS_RADIUS * scaleGlobal_)
                        / MARS_IMAGE_PX;
      planets_[3] = new Planet(b2Vec2(MARS_DISTANCE, 0),
                               b2Vec2(MARS_IMAGE_PX / 2, MARS_IMAGE_PX / 2),
                               imageZoom, MARS_IMAGE_PATH,
                               MARS_RADIUS);
      planets_[3]->setMapMinSize(MARS_RADIUS / 500000);
    }
    {
      float imageZoom = (JUPITER_RADIUS * scaleGlobal_)
                        / JUPITER_IMAGE_PX;
      planets_[4] = new Planet(b2Vec2(JUPITER_DISTANCE, 0),
                             b2Vec2(JUPITER_IMAGE_PX / 2, JUPITER_IMAGE_PX / 2),
                              imageZoom, JUPITER_IMAGE_PATH,
                              JUPITER_RADIUS);
      planets_[4]->setMapMinSize(JUPITER_RADIUS / 500000);
    }
    {
      float imageZoom = (SATURN_RADIUS * scaleGlobal_)
                        / SATURN_IMAGE_PX;
      planets_[5] = new Planet(b2Vec2(SATURN_DISTANCE, 0),
                         b2Vec2(SATURN_IMAGE_WIDTH_PX / 2, SATURN_IMAGE_PX / 2),
                           imageZoom, SATURN_IMAGE_PATH,
                           SATURN_RADIUS);
      planets_[5]->setMapMinSize(SATURN_RADIUS / 500000);
    }
    {
      float imageZoom = (URAN_RADIUS * scaleGlobal_)
                        / URAN_IMAGE_PX;
      planets_[6] = new Planet(b2Vec2(URAN_DISTANCE, 0),
                               b2Vec2(URAN_IMAGE_PX / 2, URAN_IMAGE_PX / 2),
                               imageZoom, URAN_IMAGE_PATH,
                               URAN_RADIUS);
      planets_[6]->setMapMinSize(URAN_RADIUS / 500000);
    }
    {
      float imageZoom = (NEPTUNE_RADIUS * scaleGlobal_)
                        / NEPTUNE_IMAGE_PX;
      planets_[7] = new Planet(b2Vec2(NEPTUNE_DISTANCE, 0),
                             b2Vec2(NEPTUNE_IMAGE_PX / 2, NEPTUNE_IMAGE_PX / 2),
                              imageZoom, NEPTUNE_IMAGE_PATH,
                              NEPTUNE_RADIUS);
      planets_[7]->setMapMinSize(NEPTUNE_RADIUS / 500000);
    }
    {
      float imageZoom = (PLUTON_RADIUS * scaleGlobal_)
                        / PLUTON_IMAGE_PX;
      planets_[8] = new Planet(b2Vec2(PLUTON_DISTANCE, 0),
                               b2Vec2(PLUTON_IMAGE_PX / 2, PLUTON_IMAGE_PX / 2),
                               imageZoom, PLUTON_IMAGE_PATH,
                               PLUTON_RADIUS);
      planets_[8]->setMapMinSize(PLUTON_RADIUS / 500000);
    }
  }

  void drawMapBackground() {
    sf::Sprite sprite;
    sprite.setTexture(backgroundMapTexture_);

    sprite.setOrigin(backgroundMapPosition_.x, backgroundMapPosition_.y);
    sprite.setPosition(eyeCentre_.x, eyeCentre_.y);
    sprite.setScale(zoomMapBackground_, zoomMapBackground_);
    window_->draw(sprite);
  }

 private:
  /* текстура  */
  sf::Texture backgroundTexture_;

  /* вид который показывает все в этом состоянии */
  sf::View mainView_;

  int const GLOBAL_VIEW = 1;
  int const LOCAL_VIEW = 2;
  int viewMode_;

  Planet *activePlanet_;

  // планеты
  Planet **planets_;

  // текстура заднего фона(постоянно в памяти)
  sf::Texture backgroundMapTexture_;

  // позиция куда сейчас смотрит камера
  b2Vec2 eyeCentre_;

  // расположение заднего фона
  // в игре фон немножко двигается
  b2Vec2 backgroundMapPosition_;

  // Rocket *rocket_;

  // кусок глобального мира реального размера
  b2World *localWorld_;

  // глобальный мир - весь мир, но уменьшенный в размерах
  b2World *globalWorld_;

  // главная камера
  sf::View mainmainView_;
  // камера миникарты
  // sf::View mainmainView_;

  // зум
  float zoom_;
  // зум для заднего фона
  float zoomMapBackground_;

  // отношение физических координат мира Box2D и координат экрана
  float scaleGlobal_;
  float scaleLocal_;

  // отношение между координатами глобального и локального мира global/local
  float globalLocalRatio_;
};

#endif /* end of include guard: PLAY_STATE_HPP */
