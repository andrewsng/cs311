// counthsw.cpp
// Andrew S. Ng
// Started: 2020-10-01
// Updated: 2020-10-06
//
// CS 311 Fall 2020
// Source for countHSW:
// Holey spider walks problem

#include "counthsw.h"  // For countHSW
#include <vector>      // For std::vector
using std::vector;
#include <cmath>
using std::abs;


// checkSquare
// Checks if new square is a valid square to move to
// on a given walk.
// Pre:
//   board is a vector of size dim_x holding
//     vectors of size dim_y that hold ints.
//   dim_x,dim_y > 0.
//   0 <= curr_x < dim_x,  0 <= curr_y < dim_y
bool checkSquare(const vector<vector<int>> & board,
    int dim_x, int dim_y, int curr_x, int curr_y,
    int new_x, int new_y)
{
    // NEW SQUARE IS THE CURRENT SQUARE
    if (curr_x == new_x && curr_y == new_y)
        return false;

    // NEW SQUARE IS OUT OF BOUNDS
    if (new_x < 0 || new_x >= dim_x || 
        new_y < 0 || new_y >= dim_y)
        return false;

    // NEW SQUARE HAS BEEN VISITED
    if (board[new_x][new_y] == 1)
        return false;

    return true;
}                 


// countHSW_recurse
// Counts the number of holey spider walks based on 
// a given partial solution.
// Recursive: uses recursive backtracking to compute walks.
// A partial solution is stored using:
//   A 2-D vector of ints set to 1 for visited squares,
//   including the hole, and 0 for unvisited squares.
//   The board's dimensions, finish square, and current square.
//   The number of squares left to visit.
// Pre:
//   board is a vector of size dim_x holding
//     vectors of size dim_y that hold ints.
//   dim_x,dim_y > 0.
//   0 <= finish_x < dim_x,  0 <= finish_y < dim_y
//   0 <= curr_x < dim_x,    0 <= curr_y < dim_y
//   0 <= squaresLeft <= dim_x * dim_y - 2
int countHSW_recurse(vector<vector<int>> & board,
    int dim_x, int dim_y, int finish_x, int finish_y,
    int curr_x, int curr_y, int squaresLeft)
{
    // FULL SOLUTION

    if (squaresLeft == 0 &&
        curr_x == finish_x && curr_y == finish_y)
        return 1;

    // DEAD ENDS

    if (squaresLeft > 0 &&
        curr_x == finish_x && curr_y == finish_y)
        return 0;

    // RECURSIVE CASE

    int total = 0;

    // For each adj. square (N/S/E/W/diagonals),
    // do recursive call if the move is valid
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int new_x = curr_x + dx;  // New square
            int new_y = curr_y + dy;

            if (checkSquare(board,
                            dim_x, dim_y,
                            curr_x, curr_y,
                            new_x, new_y))
            {
                board[new_x][new_y] = 1;
                total += countHSW_recurse(board,
                                          dim_x, dim_y,
                                          finish_x, finish_y,
                                          new_x, new_y,
                                          squaresLeft - 1);
                board[new_x][new_y] = 0;  // Restore change to board
            }
        }
    }

    return total;
}


// countHSW
// (See header.)
int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y)
{
    vector<vector<int>> board(dim_x, vector<int>(dim_y, 0));
    board[start_x][start_y] = 1;
    board[hole_x][hole_y] = 1;
    int squaresLeft = dim_x * dim_y - 2;
    return countHSW_recurse(board,
                            dim_x, dim_y,
                            finish_x, finish_y,
                            start_x, start_y,
                            squaresLeft);
}                          

