/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

/* макрос указывающий путь к папке с рессурсами */
#define RES_PATH "../../game/res"

#define VERSION "0.0.1"

#include <string.h>
#include <string>

#include "../../LGE/GameManager.hpp"

// TODO(Goginet): include your states here
#include "../../game/src/States/StartState.hpp"
#include "../../game/src/States/AboutState.hpp"

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    /* load your state here */
    if (std::string(argv[1]) ==  std::string("1")) {
      Lge::Game game(new StartState(), 1000, 800, "testbed");
      game.start();
    } else if (std::string(argv[1]) ==  std::string("2")) {
      Lge::Game game(new AboutState(), 1000, 800, "testbed");
      game.start();
    } else {
      std::cout << "incorrect state nomber" << std::endl;
    }
  } else {
    std::cout << "Please choose State nomber!" << std::endl;
    std::cout << "testbed [state_nomber]" << std::endl;
  }
  return 0;
}
