// counthsw.cpp
// Andrew S. Ng
// 2020-10-01
//
// CS 311 Fall 2020
// Source for countHSW:
// Holey spider walks problem

#include "counthsw.h"
#include <vector>
using std::vector;


bool checkSquare(const vector<vector<int>> & board,
    int dim_x, int dim_y, int new_x, int new_y,
    int dx, int dy)
{
    if (dx == 0 && dy == 0)
        return false;

    if (new_x < 0 || new_x >= dim_x ||
        new_y < 0 || new_y >= dim_y)
        return false;

    if (board[new_x][new_y] == 1)
        return false;

    return true;
}                 


int countHSW_recurse(vector<vector<int>> & board,
    int dim_x, int dim_y, int finish_x, int finish_y,
    int curr_x, int curr_y, int squaresLeft)
{
    if (squaresLeft == 0 && 
        curr_x == finish_x && curr_y == finish_y)
        return 1;

    int total = 0;

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int new_x = curr_x + dx;
            int new_y = curr_y + dy;

            if (checkSquare(board,
                            dim_x, dim_y,
                            new_x, new_y,
                            dx, dy))
            {
                board[new_x][new_y] = 1;
                total += countHSW_recurse(board,
                                          dim_x, dim_y,
                                          finish_x, finish_y,
                                          curr_x + dx, curr_y + dy,
                                          squaresLeft - 1);
                board[new_x][new_y] = 0;
            }
        }
    }

    return total;
}


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

