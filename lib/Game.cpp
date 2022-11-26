#include "Matrix.h"

template <typename T>
class Game
{
private:
    Matrix<T> gameField;
    Matrix<T> gameFieldEvolved;
    T deadValue; // e.g. defaultValue
    T aliveValue;

    
    /// @brief On given cell applies full ruleset and changes the cell status accordingly
    /// @param deadCount: Count of dead cells nearby
    /// @param aliveCount: Count of alive cells nearby
    /// @param col: column coordinate of the cell
    /// @param row: row coordinate of the cell
    /// @param isAlive: Status of given cell
    void applyFullRules(int deadCount, int aliveCount, int col, int row, bool isAlive)
    {
        //Rule 1, 2, 3
        if (isAlive) {
            if (aliveCount < 2 or aliveCount > 3) {
                return deadValue;
            }
            return aliveValue;
        }
        // rule 4
        if (aliveCount == 3) {
            return aliveValue;
        }
        return deadValue;    
    }
    /// @brief On given cell applies full ruleset and changes the cell status accordingly
    /// @param deadCount: Count of dead cells nearby
    /// @param aliveCount: Count of alive cells nearby
    /// @param col: column coordinate of the cell
    /// @param row: row coordinate of the cell
    /// @param isAlive: Status of given cell
    void applyConsensedRules(int deadCount, int aliveCount, int col, int row, bool isAlive)
    {
        //Rule 1, 2, 3
        if (isAlive) 
            return (aliveCount < 2 or aliveCount > 3) ? deadValue : aliveValue;
        // rule 4
        return aliveCount == 3 ? aliveValue : deadValue;   
    }

public:
    Game(int m, int n, T defaultValue, T _aliveValue)
    {
        deadValue = defaultValue;
        aliveValue = _aliveValue;
        gameField = new Matrix<T>(defaultValue, m, n);
        gameFieldEvolved = gameField; // setup for later evolve stages
    }

    /// @brief Takes game field and evolves it according to the rules
    /// @param evolutions: Number of evolutions to be done
    void evolveGame(int evolutions) {
        // TODO: cyklus pro search cells a jejich okoli
        // TODO: ukladani do noveho pole
    }
};
