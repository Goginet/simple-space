/*
* Copyright 2016 Goginet gogi.soft.gm@gmail.com
* Слушатель событий кнопки
*/

#ifndef BUTTON_LISTNER_HPP_
#define BUTTON_LISTNER_HPP_

#include <string>

namespace Lge {
class ButtonListner {
 public:
  /* клик по кнопке */
  virtual void onClick(std::string id) = 0;
  /* на кнопку наведен курсор */
  virtual void onPointing(std::string id) = 0;
  /* кнопка нажата */
  virtual void onPress(std::string id) = 0;
};
}  // namespace Lge

#endif /* end of include guard: BUTTON_LISTNER_HPP_ */
