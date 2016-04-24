/* Copyright 2016 Goginet gogi.soft.gm@gmail.com */

#include "../LGE/LgeGame.hpp"
#include "states/FirstState.hpp"

int main() {
  LgeGame game(new FirstState(), 1400, 900);
  game.start();
  return 0;
}
