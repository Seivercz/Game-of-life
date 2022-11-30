#include "Matrix.h"
#include <tuple>
#include <utility>
#include <cstdlib>

template <typename T> class Game {
private:
  Matrix<T> gameField;
  Matrix<T> gameFieldEvolved;
  T deadValue; // e.g. defaultValue
  T aliveValue;

  /// @brief On given cell applies full ruleset and changes the cell status
  /// accordingly
  /// @param deadCount: Count of dead cells nearby
  /// @param aliveCount: Count of alive cells nearby
  /// @param col: column coordinate of the cell
  /// @param row: row coordinate of the cell
  /// @param isAlive: Status of given cell
  /// @return:  whether the cell should be alive or not
  bool applyRules(int deadCount, int aliveCount, int col, int row,
                  bool isAlive) {
    // Rule 1, 2, 3
    if (isAlive)
      return (aliveCount < 2 or aliveCount > 3) ? false : true;
    // rule 4
    return aliveCount == 3 ? true : false;
  }

  /// @brief Counts the amount of dead/alive cells in given cell location
  /// @param x: x coordinate of the cell
  /// @param y: y coordinate of the cell
  std::tuple<int, int> checkAroundCell(int x, int y) {
    std::pair<int, int> boundX = std::make_pair(-1, 1);
    std::pair<int, int> boundY = std::make_pair(-1, 1);

    int aliveCells = 0;
    int deadCells = 0;

    // make range boundaries when cell is at the ceiling, bottom or walls of the
    // matrix
    if (x == 0)
      boundX.first = 0;
    if (x == gameField.getsizeM() - 1)
      boundX.second = 0;
    if (y == 0)
      boundY.first = 0;
    if (y == gameField.getsizeN() - 1)
      boundY.second = 0;

    // cycle the boundaries around and count for dead/alive cells
    for (auto i = x + boundX.first; i <= (x + boundX.second); i++) {
      for (auto j = y + boundY.first; j <= (y + boundY.second); j++) {
        // aliveCells += gameField.getValue(i, j) == aliveValue ? 1 : 0;
        // deadCells += gameField.getValue(i, j) == deadValue ? 1 : 0;
        if (i != x or j != y) {
          deadCells += gameField.getValue(i, j) == deadValue ? 1 : 0;
          aliveCells += gameField.getValue(i, j) == aliveValue ? 1 : 0;
        }
      }
    }
    return {deadCells, aliveCells};
  }

  bool isCellAlive(int x, int y) {
    return gameField.getValue(x, y) == aliveValue ? true : false;
  }

public:
  Game(int m, int n, T defaultValue, T _aliveValue) {
    deadValue = defaultValue;
    aliveValue = _aliveValue;
    gameField = Matrix<T>(defaultValue, m, n);
    gameFieldEvolved = gameField; // setup for later-on evolve stages
  }

  Game(Matrix<T> mat, T dead, T alive) {
    deadValue = dead;
    aliveValue = alive;
    gameField = mat;
    gameFieldEvolved = gameField;
  }
  

  /// @brief Takes game field and evolves it according to the rules
  /// @param evolutions: Number of evolutions (rounds) to be done
  void evolveGame(uint evolutions) {
    if (evolutions > 0) {
      int deadCells, aliveCells = 0;
      for (size_t i = 0; i < gameField.getsizeM() - 1; i++) {
        for (size_t j = 0; j < gameField.getsizeN() - 1; j++) {
          std::tie(deadCells, aliveCells) = checkAroundCell(i, j);
          bool cellState = applyRules(deadCells, aliveCells, i, j, isCellAlive(i, j));
          gameFieldEvolved.setValue(i, j, cellState ? aliveValue : deadValue);
        }
      }
      gameField = gameFieldEvolved;
      evolutions--;
      evolveGame(evolutions);
    }
  }

  void randomizeField() {
    srand(time(NULL));
    for (int i = 0; i < gameField.getsizeM() - 1; i++)
        for (int j = 0; j < gameField.getsizeN() - 1; j++)
          gameField.setValue(i, j, rand()%2 == 0 ? deadValue : aliveValue);
    gameFieldEvolved = gameField;
  }

  void printGameField() { gameField.Print(); }
};
