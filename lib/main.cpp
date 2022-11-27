#include "Game.h"
#include <iostream>


int main() {

  std::cout << "Hello, peasant" << std::endl;
  auto test = Matrix<int>(0, 5, 5);
  test.Print();
  auto gameOfLife = Game<int>(5, 5, 0, 1);

  std::cout << "Game field round 0:" << std::endl;
  gameOfLife.printGameField();

  gameOfLife.evolveGame(1);

  std::cout << "Game field round 1:" << std::endl;
  gameOfLife.printGameField();
  return 0;
}