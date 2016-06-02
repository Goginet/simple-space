/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

/* макрос указывающий путь к папке с рессурсами */
#define RES_PATH "../res"

#define VERSION "0.0.1"

#include "../../LGE/GameManager.hpp"
#include "States/StartState.hpp"

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    Lge::Game game(new StartState(), 1100, 800, "GameMangerTest");
    game.start();
  }
  return 0;
}
