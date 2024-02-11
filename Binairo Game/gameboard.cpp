/* Program author
* Name: Baqir Kazmi
*/
#include "gameboard.hh"
#include <iostream>
#include <random>
using namespace std;
GameBoard::GameBoard()
{
board = vector<vector<Element_type>>(SIZE, vector<Element_type>(SIZE, EMPTY));
}

void GameBoard::print() const
{ // prints the gameboard graphically
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');
    cout << "|   | ";
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        cout << i + 1 << " ";
    }
    cout << "|" << endl;
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '-');
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            char symbol;
            if(board[i][j] == ZERO)
                symbol = '0';
            else if(board[i][j] == ONE)
                symbol = '1';
            else
                symbol = ' ';
            cout << symbol << " ";
        }
        cout << "|" << endl;
    }
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');
}

bool GameBoard::is_game_over() const
{
    // Check if the board is fully filled
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            if(board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

bool GameBoard::fill_random(int seed)
{
    // Check if the seed is bad
    if(seed >= 1 && seed <= 50)
    {
        for(unsigned int i = 0; i < BAD_SEEDS.size(); ++i)
        {
            if(seed == BAD_SEEDS[i])
            {
                cout << "Bad seed" << endl;
                return false;
            }
        }
    }

    default_random_engine rand_gen(seed);
    uniform_int_distribution<int> distribution(0, DISTR_UPPER_BOUND);
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            int rand_num = distribution(rand_gen);
            if(rand_num == 0)
                board[i][j] = ZERO;
            else if(rand_num == 1)
                board[i][j] = ONE;
            // Otherwise, leave it empty
        }
    }
    return true;
}

bool GameBoard::fill_input(const string& input)
{
    if(input.size() != SIZE * SIZE + 2)
    {
        cout << "Wrong size of input" << endl;
        return false;
    }

    for(unsigned int i = 1; i <= SIZE; ++i)
    {
        for(unsigned int j = 1; j <= SIZE; ++j)
        {
            char symbol = input[(i - 1) * SIZE + j];
            if(symbol == '0')
                board[i - 1][j - 1] = ZERO;
            else if(symbol == '1')
                board[i - 1][j - 1] = ONE;
            else if(symbol != ' ')
            {
                cout << "Wrong character" << endl;
                return false;
            }
        }
    }
    return true;
}

bool GameBoard::add_element(unsigned int x, unsigned int y, Element_type symbol)
{ // adds element after checking a series of flags: i.e. if the position entered in not out of bounds, if the the symbol entered is neither 1 nor 0,
    // if the position is already filled or not and lastly checks if the move does not violate game rules.
    if(x < 1 || x > SIZE || y < 1 || y > SIZE)
    {
        cout << "Out of board" << endl;
        return false;
    }

    if(symbol != ZERO && symbol != ONE)
    {
        cout << "Invalid input" << endl;
        return false;
    }

    if(board[y - 1][x - 1] != EMPTY)
    {
        cout << "Can't add" << endl;
        return false;
    }
    if(!check_rules(x - 1, y - 1, symbol))
    {
        cout << "Can't add" << endl;
        return false;
    }

    board[y - 1][x - 1] = symbol;
    return true;
}

bool GameBoard::check_rules(unsigned int x, unsigned int y, Element_type symbol) const
{ // x=5 y=1 s=0
    // Check row for adjacency violations
    int row_count = 1;
    // Check to the left
    if (x > 1 && board[y][x-1] == symbol && board[y][x-2] == symbol){
        row_count++;}
    // Check to the right
    if (x < SIZE-1 && board[y][x+1] == symbol && board[y][x+2] == symbol){
        row_count++;}
    if (row_count >= 2){
       // cout<<"here1"<<endl;
        return false;}

    // Check column for adjacency violations
    int col_count = 1;
    // Check above
    if (y > 1 && board[y - 1][x] == symbol && board[y - 2][x] == symbol){
        col_count++;}
    // Check below
    if (y < SIZE-1 && board[y + 1][x] == symbol && board[y+2][x] == symbol){
        col_count++;}
    if (col_count >= 2)
    {//cout<<"here2"<<endl;
        return false;}

    // ********************* 2nd Check ***********************
    // that ones or zzeros should not be beyond 3 check if already there are 3 otherwise return false
    // x= 1, y =2 , 0
    // Check row for equal number of 0s and 1s
    // Check rows
        int symbol_count_row = 0;
        for (unsigned int j = 0; j < SIZE; ++j) {
            if (board[y][j] == symbol) {
                symbol_count_row++;
                if (symbol_count_row > 2) {
                    return false; // Exceeded symbol limit in this row
                }
            }
        }


    // Check columns vertically
        int symbol_count_col = 0;
        for (unsigned int i = 0; i < SIZE; ++i) {
            if (board[i][x] == symbol) {
                symbol_count_col++;
                if (symbol_count_col > 2) {
                    return false; // Exceeded symbol limit in this column
                }
            }
        }


    return true;
}



void GameBoard::print_line(unsigned int length, char fill_character) const
{ // prints a line of length specified and with characters given to fill in. used in the user input function.
    for(unsigned int i = 0; i < length; ++i)
    {
        cout << fill_character;
    }
    cout << endl;
}
