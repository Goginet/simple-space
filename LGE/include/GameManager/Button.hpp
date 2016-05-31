/*
* Copyright 2016 Goginet gogi.soft.gm@gmail.com
*
* Класс расширяет возможности библиотеки sfml
* добавляя туда кнопки
*
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <string>
#include "../../GameManager.hpp"

namespace Lge {
class Button {
 public:
  Button(std::string id, sf::Vector2<float> size, sf::Vector2<float> position);

  /* обновление логики кнопки */
  virtual void update();

  /* отрисовка кнопки */
  void render(sf::RenderWindow *window);

  /* обработка событий переданных из вне */
  bool control(sf::Event event);

  /* Texture loaders */
  void loadTexrurePassive(std::string path);
  void loadTexrureActive(std::string path);
  void loadTexrurePress(std::string path);

  /* SETERS */
  void setButtonListner(Lge::ButtonListner *listner);
  void setOnTouchRepeated(bool isOnPressRepeated);
  void setOnPointRepeated(bool isOnActiveRepeated);
  void setClickSound(sf::Sound *sound);

 private:
  /* id кнопки */
  std::string id_;
  /* прямоугольник ограничивающий кнопку */
  sf::FloatRect rect_;

  /* текстура кнопки в обычном состоянии */
  sf::Texture texturePassive_;

  /* текстура кнопки в активном состоянии */
  sf::Texture textureActive_;

  /* текстура кнопки в обычном состоянии */
  sf::Texture texturePress_;

  /* звук который воспроизводится при нажатии */
  sf::Sound *soundClick;

  /* слушатель событий кнопки */
  Lge::ButtonListner *listner_;

  /* повторяеться ли событие onTouch если кнопка зажата */
  bool isOnPushRepeated_;

  /* повторяеться ли событие onPoint пока курсор находиться на кнопке */
  bool isOnActiveRepeated_;

  /* активна ли кнопка */
  bool isActive_;

  /* нажата ли кнопка */
  bool isPressed_;

  /* произошел ли клик */
  bool isClick_;
};
}  // namespace Lge

#endif /* end of include guard: BUTTON_HPP_ */
