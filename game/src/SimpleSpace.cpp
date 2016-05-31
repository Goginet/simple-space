/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../../LGE/GameManager.hpp"
#include "States/StartState.hpp"

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    Lge::Game game(new StartState(), 1000, 800, "GameMangerTest");
    game.start();
  }
  return 0;
}
