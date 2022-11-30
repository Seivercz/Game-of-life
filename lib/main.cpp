#include "Game.h"
#include <iostream>
#include <string>

int main() {

  std::cout << "Hello, peasant" << std::endl;

  std::cout << "Insert dimensions of the game (MxN) \n";
  int m,n;
  std::cout << "M:";
  std::cin >> m;
  std::cout << "N:";
  std::cin >> n;

  std::cout << "Starting field will be randomized";

  auto gameOfLife = Game<std::string>(m, n, "o", "x");
  gameOfLife.randomizeField();
  int roundCounter = 0;

  while (std::cin.get() != 'q') {

    std::cout << "Game field round 0:" << std::endl;
    gameOfLife.printGameField();

    std::cout << '\n' << "Press a key to for next round or q to end" << std::endl;;
    gameOfLife.evolveGame(1);

  }

  return 0;
}
