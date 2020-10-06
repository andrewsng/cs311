// counthsw.h
// Andrew S. Ng
// Started: 2020-10-01
// Updated: 2020-10-06
//
// CS 311 Fall 2020
// Header for countHSW:
// Holey spider walks problem

#ifndef FILE_COUNTHSW_H_INCLUDED
#define FILE_COUNTHSW_H_INCLUDED


// countHSW
// Counts the number of holey spider walks on a given board.
// A board is specified by the dimensions of the board, and
// the coordinates of the hole, start, and finish squares.
// Pre:
//   dim_x,dim_y > 0.
//   0 <= hole_x < dim_x,   0 <= hole_y < dim_y
//   0 <= start_x < dim_x,  0 <= start_y < dim_y
//   0 <= finish_x < dim_x, 0 <= finish_y < dim_y
//   The hole, start, and finish have distinct coordinates.
int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y);


#endif // FILE_COUNTHSW_H_INCLUDED

