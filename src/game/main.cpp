#include "../../engine/game.h"
#include "../states/include/FirstState.h"

int main()
{
  Game game(new FirstState(),1400,900);
  game.start();
  return 0;
}
