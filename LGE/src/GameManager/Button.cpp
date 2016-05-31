/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include <string>
#include <iostream>

#include "../../GameManager.hpp"

Lge::Button::Button(std::string id, sf::Vector2<float> size,
                    sf::Vector2<float> position) {
  /* выставление значений по умолчанию */
  isOnPushRepeated_ = false;
  isOnActiveRepeated_ = false;

  id_ = id;

  /* сдвигаем центр в прямоугольнике с середины в левый верхний угол
   * для упрошения отрисовки  */
  position.x = position.x - size.x / 2;
  position.y = position.y - size.y / 2;

  rect_ = sf::FloatRect(position, size);
}


void Lge::Button::update() {
  /* флаг, что на кнопку курсор только навелся */
  static bool isFirstPointed = true;

  if (isActive_) {
    /* выполняет при необходимости onActiveEvent_ */
    if (isOnActiveRepeated_ && listner_ != NULL) {
      listner_->onPointing(id_);
    } else if (isFirstPointed && listner_ != NULL) {
      listner_->onPointing(id_);
      isFirstPointed = false;
    }

    /* флаг, что кнопка только что нажата */
    static bool isPressedFirst = true;

    /* выполняет при необходимости onPushEvent_ */
    if (isPressed_) {
      if (isOnPushRepeated_ && listner_ != NULL) {
        listner_->onPress(id_);
      } else if (isPressedFirst && listner_ != NULL) {
        listner_->onPress(id_);
        isPressedFirst = false;
      }
    } else {
      isPressedFirst = true;
    }

    /* выполняет при необходимости onClickEvent_ */
    if (isClick_) {
      if (listner_ != NULL) {
        listner_->onClick(id_);
      }
      /* воспроизведение звука нажатия */
      if (soundClick != NULL) {
        soundClick->play();
      }
      isClick_ = false;
    }

  } else {
    isFirstPointed = true;
  }
}

bool Lge::Button::control(sf::Event event) {
  switch (event.type) {
    case sf::Event::MouseMoved:
    {
      /* проверяем активна ли кнопка */
      if (rect_.contains(event.mouseMove.x, -event.mouseMove.y)) {
        isActive_ = true;
      } else {
        isActive_ = false;
      }
    }
    return false;

    case sf::Event::MouseButtonPressed:
    {
      if (isActive_) {
        isPressed_ = true;
      } else {
        isPressed_ = false;
      }
    }
    return true;

    case sf::Event::MouseButtonReleased:
    {
      if (isPressed_) {
        isPressed_ = false;
        isClick_ = true;
      } else {
        isClick_ = false;
      }
    }
    return true;

    default:
    return false;
  }
}

void Lge::Button::render(sf::RenderWindow *window) {
  sf::Texture texture;
  /* в зависимости от состояния выбераем какую текстуру показывать */
  if (isActive_) {
    if (isPressed_) {
      texture = texturePress_;
    } else {
      texture = textureActive_;
    }
  } else {
    texture = texturePassive_;
  }

  /* отрисовка */
  sf::Vector2u textureSize = texture.getSize();
  float deltaX = rect_.width / static_cast<float>(textureSize.x);
  float deltaY = rect_.height / static_cast<float>(textureSize.y);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setScale(deltaX, deltaY);
  sprite.setPosition(rect_.left, -rect_.top - rect_.height);
  window->draw(sprite);
}

void Lge::Button::setButtonListner(Lge::ButtonListner *listner) {
  listner_ = listner;
}

void Lge::Button::setOnTouchRepeated(bool isOnTouchRepeated) {
  isOnPushRepeated_ = isOnTouchRepeated;
}

void Lge::Button::setOnPointRepeated(bool isOnPointRepeated) {
  isOnActiveRepeated_ = isOnPointRepeated;
}

void Lge::Button::loadTexrurePassive(std::string path) {
  texturePassive_.loadFromFile(path);
}
void Lge::Button::loadTexrureActive(std::string path) {
  textureActive_.loadFromFile(path);
}
void Lge::Button::loadTexrurePress(std::string path) {
  texturePress_.loadFromFile(path);
}

void Lge::Button::setClickSound(sf::Sound *sound) {
  soundClick = sound;
}
