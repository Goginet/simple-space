/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#ifndef ABOUT_STATE_HPP_
#define ABOUT_STATE_HPP_

#include <string>
#include <iostream>

#include "../../../LGE/GameManager.hpp"

class AboutState: public Lge::State, public Lge::ButtonListner {
 public:
  /* размеры этого состояния в пикселях */
  static constexpr float STATE_WIDTH = 1920;
  static constexpr float STATE_HEIGHT = 1080;

  /* КООРДИНАТЫ объектов */
  const sf::Vector2<float> BUTTON_BACK_POSITION = sf::Vector2<float>(400, -360);
  const sf::Vector2<float> DEV_TEXT_POSITION = sf::Vector2<float>(-450, -100);
  const sf::Vector2<float> VERSION_TEXT_POSITION = sf::Vector2<float>(-170, -420);

  /* размеры тел */
  const sf::Vector2<float> BUTTON_BACK_SIZE = sf::Vector2<float>(330, 132);
  const float DEV_TEXT_SIZE = 30;
  const float VERSION_TEXT_SIZE = 40;

  /* ID Кнопок на экране */
  std::string BUTTON_BACK_ID = "back";

  /* текст хранящий информацию о разработчиках */
  const std::wstring ABOUT_DEVELOPERS_TEXT = \
  std::wstring(L"глав. разаработчик: Goginet\n") +
  std::wstring(L"глав. дизайнер: Goginet\n") +
  std::wstring(L"и просто главнюк: Goginet");

  /* текст хранящий версию игры */
  const std::string GAME_VERSION_TEXT = \
  std::string("simple-space version: ") + std::string(VERSION);

  /****************************************************************************/
  /*                          STATE RESURSES PATH                             */
  /****************************************************************************/

  /*                            IMAGES PATH                                   */
  const std::string BACKGROUND_IMAGE_PATH = \
  ADD_RES_PATH("/images/backgrounds/about.png");
  const std::string BUTTON_BACK_IMAGE_PASSIVE_PATH = \
  ADD_RES_PATH("/images/buttons/back.png");
  const std::string BUTTON_BACK_IMAGE_ACTIVE_PATH = \
  ADD_RES_PATH("/images/buttons/backActive.png");

  /*                              SOUND PATH                                  */
  const std::string BUTTON_SOUND_CLICK_PATH = \
  ADD_RES_PATH("/audio/buttons/click.wav");

  /*                              TEXT PATH                                   */
  const std::string TEXT_FONT_ABOUT_PATH = \
  ADD_RES_PATH("/fonts/default.ttf");

  /****************************************************************************/
  /*                         STATE INITIALIZATION                             */
  /****************************************************************************/

  /* Инициализация/загрузка объектов для этого состояния */
  AboutState():
  /* инициализация кнопок */
  buttonBack_(BUTTON_BACK_ID, BUTTON_BACK_SIZE, BUTTON_BACK_POSITION) {
    /* загрузка заднего фона */
    backgroundTexture_.loadFromFile(BACKGROUND_IMAGE_PATH);

    /* загрузка звука */
    soundButtonBuffer.loadFromFile(BUTTON_SOUND_CLICK_PATH);
    soundButtonClick.setBuffer(soundButtonBuffer);

    /* загрузка шрифтов */
    if (font.loadFromFile(TEXT_FONT_ABOUT_PATH)) {
      aboutDevelopersText.setFont(font);
      gameVersionText.setFont(font);
    }

    /* загрузка текста */
    loadText();

    /* загрузка кнопок */
    loadButtons();
  }

  /****************************************************************************/
  /*                              STATE DESTROY                               */
  /****************************************************************************/

  /* удаление всех объектов этого сотояния */
  ~AboutState() {}

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

    /* рисуем текст */
    window_->draw(aboutDevelopersText);
    window_->draw(gameVersionText);

    /* рисуем кнопки */
    buttonBack_.render(window_);
  }

  /****************************************************************************/
  /*                               STATE UPDATE                               */
  /****************************************************************************/

  /* обновление логики в этом состоянии */
  void update() {
    /* обновление кнопок */
    buttonBack_.update();
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
    buttonBack_.control(event);
  }

  /* загрузка текста */
  void loadText() {
    aboutDevelopersText.setCharacterSize(DEV_TEXT_SIZE);
    gameVersionText.setCharacterSize(VERSION_TEXT_SIZE);

    aboutDevelopersText.setPosition(DEV_TEXT_POSITION);
    gameVersionText.setPosition(VERSION_TEXT_POSITION);

    aboutDevelopersText.setString(ABOUT_DEVELOPERS_TEXT);
    gameVersionText.setString(GAME_VERSION_TEXT);
  }

  /****************************************************************************/
  /*                              STATE BUTTONS                               */
  /****************************************************************************/

  /* инициализация кнопок */
  void loadButtons() {
    /* загрузка текстур для кнопок */
    buttonBack_.loadTexrurePassive(BUTTON_BACK_IMAGE_PASSIVE_PATH);

    buttonBack_.loadTexrureActive(BUTTON_BACK_IMAGE_ACTIVE_PATH);

    /* устанавливаем звук щелчка для кнопок */
    buttonBack_.setClickSound(&soundButtonClick);

    /* задаем этот класс слушателем всех кнопок */
    buttonBack_.setButtonListner(this);
  }

  /* ОБРАБОТКА СОБЫТИЙ ДЛЯ КНОПОК */

  /* клик по кнопке */
  void onClick(std::string id) {
    if (id == BUTTON_BACK_ID) {
      gsm_->getGame()->back();
    }
  }

  /* на кнопку наведен курсор */
  void onPointing(std::string id) {
    if (id == BUTTON_BACK_ID) {
      /* write event code here */
    }
  }

  /* кнопка нажата */
  void onPress(std::string id) {
    if (id == BUTTON_BACK_ID) {
      /* write event code here */
    }
  }

 private:
  /* шрифт */
  sf::Font font;
  /* текст */
  sf::Text aboutDevelopersText;
  sf::Text gameVersionText;

  /* текстура  */
  sf::Texture backgroundTexture_;

  /* Кнопки */
  Lge::Button buttonBack_;

  /* Звук шелканья кнопки */
  sf::Sound soundButtonClick;
  sf::SoundBuffer soundButtonBuffer;

  /* вид который показывает все в этом состоянии */
  sf::View view_;
};

#endif /* end of include guard: ABOUT_STATE_HPP_ */
