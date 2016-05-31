/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */
#ifndef START_STATE_HPP_
#define START_STATE_HPP_

#include <string>
#include <iostream>

#include "../../../LGE/GameManager.hpp"

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
    backgroundTexture_.loadFromFile("../res/images/backgrounds/start.png");

    /* загрузка звука */
    soundButtonBuffer.loadFromFile("../res/audio/buttons/click.wav");
    soundButtonClick.setBuffer(soundButtonBuffer);

    /* загрузка кнопок */
    loadButtons();
  }

  /* удаление всех объектов этого сотояния */
  ~StartState() {}

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

  /* обновление логики в этом состоянии */
  void update() {
    /* обновление кнопок */
    buttonStart_.update();
    buttonOption.update();
    buttonAbout_.update();
    buttonOut_.update();
  }

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

  /* инициализация кнопок */
  void loadButtons() {
    /* загрузка текстур для кнопок */
    buttonStart_.loadTexrurePassive("../res/images/buttons/play.png");
    buttonOption.loadTexrurePassive("../res/images/buttons/settings.png");
    buttonAbout_.loadTexrurePassive("../res/images/buttons/about.png");
    buttonOut_.loadTexrurePassive("../res/images/buttons/exit.png");

    buttonStart_.loadTexrureActive("../res/images/buttons/playActive.png");
    buttonOption.loadTexrureActive("../res/images/buttons/settingsActive.png");
    buttonAbout_.loadTexrureActive("../res/images/buttons/aboutActive.png");
    buttonOut_.loadTexrureActive("../res/images/buttons/exitActive.png");

    /* устанавливаем звук щелчка для кнопок */
    buttonStart_.setClickSound(&soundButtonClick);
    buttonOption.setClickSound(&soundButtonClick);
    buttonAbout_.setClickSound(&soundButtonClick);
    buttonOut_.setClickSound(&soundButtonClick);

    /* задаем этот класс слушателем всех кнопок */
    buttonOut_.setButtonListner(this);
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
