/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */
#ifndef START_STATE_HPP_
#define START_STATE_HPP_

#include <string.h>
#include <string>
#include <iostream>

#include "../../../LGE/GameManager.hpp"

/******************************************************************************/
/*                           STATE RESURSES PATH                              */
/******************************************************************************/

/*                             IMAGES PATH                                    */
#define BACKGROUND_IMAGE_PATH \
ADD_RES_PATH("/images/backgrounds/start.png")
#define BUTTON_START_IMAGE_PASSIVE_PATH \
ADD_RES_PATH("/images/buttons/play.png")
#define BUTTON_SETTINGS_IMAGE_PASSIVE_PATH \
ADD_RES_PATH("/images/buttons/settings.png")
#define BUTTON_ABOUT_IMAGE_PASSIVE_PATH \
ADD_RES_PATH("/images/buttons/about.png")
#define BUTTON_EXIT_IMAGE_PASSIVE_PATH \
ADD_RES_PATH("/images/buttons/exit.png")
#define BUTTON_START_IMAGE_ACTIVE_PATH \
ADD_RES_PATH("/images/buttons/playActive.png")
#define BUTTON_SETTINGS_IMAGE_ACTIVE_PATH \
ADD_RES_PATH("/images/buttons/settingsActive.png")
#define BUTTON_ABOUT_IMAGE_ACTIVE_PATH \
ADD_RES_PATH("/images/buttons/aboutActive.png")
#define BUTTON_EXIT_IMAGE_ACTIVE_PATH \
ADD_RES_PATH("/images/buttons/exitActive.png")

/*                               SOUND PATH                                   */
#define BUTTON_SOUND_CLICK_PATH \
ADD_RES_PATH("/audio/buttons/click.wav")

class StartState: public Lge::State, public Lge::ButtonListner {
 public:
  /* размеры этого состояния в пикселях */
  static constexpr float STATE_WIDTH = 1920;
  static constexpr float STATE_HEIGHT = 1080;

  /* ID Кнопок на экране */
  std::string BUTTON_START_ID = "start";
  std::string BUTTON_SETTINGS_ID = "end";
  std::string BUTTON_ABOUT_ID = "about";
  std::string BUTTON_OUT_ID = "exit";

  /****************************************************************************/
  /*                         STATE INITIALIZATION                             */
  /****************************************************************************/

  /* Инициализация/загрузка объектов для этого состояния */
  StartState():
  /* инициализация кнопок */
  buttonStart_(BUTTON_START_ID, sf::Vector2<float>(330, 132),
               sf::Vector2<float>(0, 300)),
  buttonOption(BUTTON_SETTINGS_ID, sf::Vector2<float>(330, 132),
                  sf::Vector2<float>(0, 100)),
  buttonAbout_(BUTTON_ABOUT_ID, sf::Vector2<float>(330, 132),
               sf::Vector2<float>(0, -100)),
  buttonOut_(BUTTON_OUT_ID, sf::Vector2<float>(330, 132),
             sf::Vector2<float>(0, -300)) {
    /* загрузка заднего фона */
    backgroundTexture_.loadFromFile(BACKGROUND_IMAGE_PATH);

    /* загрузка звука */
    soundButtonBuffer.loadFromFile(BUTTON_SOUND_CLICK_PATH);
    soundButtonClick.setBuffer(soundButtonBuffer);

    /* загрузка кнопок */
    loadButtons();
  }

  /****************************************************************************/
  /*                              STATE DESTROY                               */
  /****************************************************************************/

  /* удаление всех объектов этого сотояния */
  ~StartState() {}

  /****************************************************************************/
  /*                               STATE RENDER                               */
  /****************************************************************************/

  /* отрисовка содержимого этого состояния */
  void render() {
    /* подгоняем камеру под экран */
    SAFE_VIEW_RATIO(view_, STATE_WIDTH, STATE_HEIGHT, window_)
    view_.setCenter(0, 0);
    window_->setView(view_);

    /* рисуем задний фон */
    PUT_TEXTURE_INTO_SPRITE_AND_DRAW(window_, backgroundTexture_,
                                     sf::Vector2<float>(70, 0));

    /* рисуем кнопки */
    buttonStart_.render(window_);
    buttonOption.render(window_);
    buttonAbout_.render(window_);
    buttonOut_.render(window_);
  }

  /****************************************************************************/
  /*                               STATE UPDATE                               */
  /****************************************************************************/

  /* обновление логики в этом состоянии */
  void update() {
    /* обновление кнопок */
    buttonStart_.update();
    buttonOption.update();
    buttonAbout_.update();
    buttonOut_.update();
  }

  /****************************************************************************/
  /*                              STATE CONTROL                               */
  /****************************************************************************/

  /* обработка событий случившихся в этом состоянии */
  void control(sf::Event event) {
    /* конвертирование экранных координат в координаты состояния */
    if (event.type == sf::Event::MouseMoved) {
      float zoom = STATE_WIDTH / window_->getSize().x;
      event.mouseMove.x -= window_->getSize().x / 2;
      event.mouseMove.y -= window_->getSize().y / 2;
      event.mouseMove.x *= zoom;
      event.mouseMove.y *= zoom;
    } else if (event.type == sf::Event::MouseButtonPressed ||
               event.type == sf::Event::MouseButtonPressed) {
     float zoom = STATE_WIDTH / window_->getSize().x;
     event.mouseButton.x -= window_->getSize().x / 2;
     event.mouseButton.y -= window_->getSize().y / 2;
     event.mouseButton.x *= zoom;
     event.mouseButton.y *= zoom;
    }

    /* передача событий в кнопки */
    buttonStart_.control(event);
    buttonOption.control(event);
    buttonAbout_.control(event);
    buttonOut_.control(event);
  }

  /****************************************************************************/
  /*                              STATE BUTTONS                               */
  /****************************************************************************/

  /* инициализация кнопок */
  void loadButtons() {
    /* загрузка текстур для кнопок */
    buttonStart_.loadTexrurePassive(BUTTON_START_IMAGE_PASSIVE_PATH);
    buttonOption.loadTexrurePassive(BUTTON_SETTINGS_IMAGE_PASSIVE_PATH);
    buttonAbout_.loadTexrurePassive(BUTTON_ABOUT_IMAGE_PASSIVE_PATH);
    buttonOut_.loadTexrurePassive(BUTTON_EXIT_IMAGE_PASSIVE_PATH);

    buttonStart_.loadTexrureActive(BUTTON_START_IMAGE_ACTIVE_PATH);
    buttonOption.loadTexrureActive(BUTTON_SETTINGS_IMAGE_ACTIVE_PATH);
    buttonAbout_.loadTexrureActive(BUTTON_ABOUT_IMAGE_ACTIVE_PATH);
    buttonOut_.loadTexrureActive(BUTTON_EXIT_IMAGE_ACTIVE_PATH);

    /* устанавливаем звук щелчка для кнопок */
    buttonStart_.setClickSound(&soundButtonClick);
    buttonOption.setClickSound(&soundButtonClick);
    buttonAbout_.setClickSound(&soundButtonClick);
    buttonOut_.setClickSound(&soundButtonClick);

    /* задаем этот класс слушателем всех кнопок */
    buttonStart_.setButtonListner(this);
    buttonOption.setButtonListner(this);
    buttonAbout_.setButtonListner(this);
    buttonOut_.setButtonListner(this);
  }

  /* ОБРАБОТКА СОБЫТИЙ ДЛЯ КНОПОК */

  /* клик по кнопке */
  void onClick(std::string id) {
    if (id == BUTTON_START_ID) {
      /* write event code here */
    } else if (id == BUTTON_SETTINGS_ID) {
      /* write event code here */
    } else if (id == BUTTON_ABOUT_ID) {
      /* write event code here */
    } else if (id == BUTTON_OUT_ID) {
      gsm_->getGame()->end();
    }
  }

  /* на кнопку наведен курсор */
  void onPointing(std::string id) {
    if (id == BUTTON_START_ID) {
      /* write event code here */
    } else if (id == BUTTON_SETTINGS_ID) {
      /* write event code here */
    } else if (id == BUTTON_ABOUT_ID) {
      /* write event code here */
    } else if (id == BUTTON_OUT_ID) {
      /* write event code here */
    }
  }

  /* кнопка нажата */
  void onPress(std::string id) {
    if (id == BUTTON_START_ID) {
      /* write event code here */
    } else if (id == BUTTON_SETTINGS_ID) {
      /* write event code here */
    } else if (id == BUTTON_ABOUT_ID) {
      /* write event code here */
    } else if (id == BUTTON_OUT_ID) {
      /* write event code here */
    }
  }

 private:
  /* текстура  */
  sf::Texture backgroundTexture_;

  /* Кнопки */
  Lge::Button buttonStart_;
  Lge::Button buttonOption;
  Lge::Button buttonAbout_;
  Lge::Button buttonOut_;

  /* Звук шелканья кнопки */
  sf::Sound soundButtonClick;
  sf::SoundBuffer soundButtonBuffer;

  /* вид который показывает все в этом состоянии */
  sf::View view_;
};

#endif /* end of include guard: START_STATE_HPP_ */
