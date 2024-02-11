/* Program author
* Name: Baqir Kazmi
*/
#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <vector>
#include <string>
using namespace std;

// Type of the elements in the gameboard.
enum Element_type {ZERO, ONE, EMPTY};

// Constants for the size of the gameboard.
const int NUMBER_OF_SYMBOLS = 3;
const int SIZE = 2 * NUMBER_OF_SYMBOLS;

// Constant for the upper bound of probability distribution.
// Zeros and ones have the same probability, say x, and the estimated
// probability of empties is 6x, whereupon their sum is 8x, and thus,
// the interval must have eigth points, as [0..7].
const int DISTR_UPPER_BOUND = 7;

// Width of the left-most column, needed in printing the gameboard.
const unsigned int LEFT_COLUMN_WIDTH = 5;


class GameBoard
{
public:
    // Constructor.
    GameBoard();

    // Prints the gameboard.
    void print() const;
    // knows when game is over and what response to give
    bool is_game_over() const;
    // fills the board randomly with a given seed value
    bool fill_random(int seed);
    // fills the board if the mode of input is user defined
    bool fill_input(const string& input);
    // fills the board with user defined position and the element symbols either 1 or 0. Also performs checks for game rules violations.
    bool add_element(unsigned int x, unsigned int y, Element_type symbol);

private:
    // Prints a line with the given length and the given character.
    void print_line(unsigned int length, char fill_character) const;
    // declaring a 2D vector of element_type as board
    vector<vector<Element_type>> board;
    // checks if move entered does not violate game rules: i.e. not more than two adjacency check and not more than 3 of ones and zeros in a row or column check.
    bool check_rules(unsigned int x, unsigned int y, Element_type symbol) const;
    // Seed values, from [1..50], producing non-solvable gameboard.
    const std::vector<int> BAD_SEEDS = { 2, 8, 12, 13, 16, 20, 21, 23,
                                                  26, 29, 31, 32, 34, 41, 42,
                                                  43, 44, 46 };
};

#endif // GAMEBOARD_HH
