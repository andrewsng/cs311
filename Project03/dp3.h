// dp3.h
// Skeleton by Glenn G. Chappell
// 2020-09-17
// Implementation by Andrew S. Ng
// Started: 2020-09-21
// Updated: 2020-09-24
//
// For CS 311 Fall 2020
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>   // For std::is_sorted


// lookup
// Returns item in linked list
// corresponding to given index.
// Requirements on Types:
//   ValueType has a copy ctor.
// Pre:
//   0 <= index < size, where size is
//     the number of items in the list.
//   head points to a valid LLNode. Passing
//     nullptr is treated as a list of size 0.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    while (head != nullptr) {
        if (index == 0) {
            return head->_data;
        }
        head = head->_next;
        --index;
    }
    throw std::out_of_range(
        "Index is out of range of the linked list nodes");
}


// didItThrow
// Calls function ff.
// If ff throws, sets threw to true, and
// throws the same exception.
// Otherwise, sets threw to false and returns.
// Pre:
//   ff is a function with no parameters, or
//     an obj with operator() defined.
void didItThrow(const std::function<void()> & ff,
                bool & threw);


// checkSorted
// Returns true if given range of data is sorted
// in ascending order.
// Returns true for ranges of size 0 or 1.
// Requirements on Types:
//   FDIter must be a forward iterator.
//   FDIter refers to items with operator< defined.
// Pre:
//   first and last specify a valid range.
template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    return std::is_sorted(first, last);
}


// gcd
// Computes the greatest common divisor of a and b.
// Does not throw.
// Recursive.
// Pre:
//   a and b are nonnegative integers.
//   a and b are not both 0.
int gcd(int a,
        int b);
        

#endif  // #ifndef FILE_DP3_H_INCLUDED